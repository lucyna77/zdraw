#ifndef SHADERS_HPP
#define SHADERS_HPP

namespace shaders {

    constexpr const char* vertex_shader_src = R"(
        cbuffer ProjectionBuffer : register(b0)
        {
            float4x4 projection;
        };

        struct VS_INPUT
        {
            float2 pos : POSITION;
            float2 uv  : TEXCOORD0;
            float4 col : COLOR0;
        };

        struct PS_INPUT
        {
            float4 pos : SV_POSITION;
            float2 uv  : TEXCOORD0;
            float4 col : COLOR0;
        };

        PS_INPUT main(VS_INPUT input)
        {
            PS_INPUT output;
            output.pos = mul(projection, float4(input.pos, 0.0f, 1.0f));
            output.uv  = input.uv;
            output.col = input.col;
            return output;
        }
    )";

    constexpr const char* pixel_shader_src = R"(
        Texture2D tex     : register(t0);
        SamplerState samp : register(s0);

        struct PS_INPUT
        {
            float4 pos : SV_POSITION;
            float2 uv  : TEXCOORD0;
            float4 col : COLOR0;
        };

        float4 main(PS_INPUT input) : SV_Target
        {
            float4 texColor = tex.Sample(samp, input.uv);
            return texColor * input.col;
        }
    )";

    constexpr const char* blur_horizontal_src = R"(
        Texture2D tex : register(t0);
        SamplerState samp : register(s0);

        cbuffer BlurParams : register(b0)
        {
            float2 texel_size;
            float blur_radius;
            float padding;
        };

        struct PS_INPUT
        {
            float4 pos : SV_POSITION;
            float2 uv  : TEXCOORD0;
        };

        float4 main(PS_INPUT input) : SV_Target
        {
            float4 color = float4(0.0, 0.0, 0.0, 0.0);
            float total_weight = 0.0;

            int radius = (int)blur_radius;
            float sigma = blur_radius * 0.5;
            float two_sigma_sq = 2.0 * sigma * sigma;

            for (int i = -radius; i <= radius; i++)
            {
                float weight = exp(-(float)(i * i) / two_sigma_sq);
                float2 offset = float2(texel_size.x * (float)i, 0.0);
                color += tex.Sample(samp, input.uv + offset) * weight;
                total_weight += weight;
            }

            return color / total_weight;
        }
    )";

    constexpr const char* blur_vertical_src = R"(
        Texture2D tex : register(t0);
        SamplerState samp : register(s0);

        cbuffer BlurParams : register(b0)
        {
            float2 texel_size;
            float blur_radius;
            float padding;
        };

        struct PS_INPUT
        {
            float4 pos : SV_POSITION;
            float2 uv  : TEXCOORD0;
        };

        float4 main(PS_INPUT input) : SV_Target
        {
            float4 color = float4(0.0, 0.0, 0.0, 0.0);
            float total_weight = 0.0;

            int radius = (int)blur_radius;
            float sigma = blur_radius * 0.5;
            float two_sigma_sq = 2.0 * sigma * sigma;

            for (int i = -radius; i <= radius; i++)
            {
                float weight = exp(-(float)(i * i) / two_sigma_sq);
                float2 offset = float2(0.0, texel_size.y * (float)i);
                color += tex.Sample(samp, input.uv + offset) * weight;
                total_weight += weight;
            }

            return color / total_weight;
        }
    )";

    constexpr const char* blur_vertex_src = R"(
        struct VS_INPUT
        {
            float2 pos : POSITION;
            float2 uv  : TEXCOORD0;
        };

        struct PS_INPUT
        {
            float4 pos : SV_POSITION;
            float2 uv  : TEXCOORD0;
        };

        PS_INPUT main(VS_INPUT input)
        {
            PS_INPUT output;
            output.pos = float4(input.pos, 0.0, 1.0);
            output.uv  = input.uv;
            return output;
        }
    )";

} // namespace shaders

#endif // SHADERS_HPP