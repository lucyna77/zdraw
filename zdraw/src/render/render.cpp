#include <include/global.hpp>

namespace render {

	bool initialize( )
	{
		if ( !window::initialize( ) )
		{
			return false;
		}

		if ( !directx::initialize( ) )
		{
			return false;
		}

		return true;
	}

	void loop( )
	{
		constexpr float clear_color[ 4 ]{ 0.0f, 0.0f, 0.0f, 0.0f };
		MSG msg{};

		while ( msg.message != WM_QUIT )
		{
			while ( PeekMessage( &msg, window::hwnd, 0, 0, PM_REMOVE ) )
			{
				if ( msg.message == WM_QUIT )
				{
					break;
				}

				TranslateMessage( &msg );
				DispatchMessage( &msg );
			}

			if ( GetAsyncKeyState( VK_END ) & 1 )
			{
				DestroyWindow( window::hwnd );
				break;
			}

			directx::device_context->OMSetRenderTargets( 1, &directx::render_target_view, nullptr );
			directx::device_context->ClearRenderTargetView( directx::render_target_view, clear_color );

			zdraw::begin_frame( );
			zdraw::end_frame( );

			directx::swap_chain->Present( 1, 0 );
		}
	}

	bool window::initialize( )
	{
		const WNDCLASSEXW wc
		{
			.cbSize = sizeof( WNDCLASSEXW ),
			.style = CS_CLASSDC,
			.lpfnWndProc = procedure,
			.hInstance = GetModuleHandleW( nullptr ),
			.hCursor = LoadCursorW( nullptr, IDC_ARROW ),
			.lpszClassName = L"zdraw"
		};

		if ( !RegisterClassExW( &wc ) )
		{
			return false;
		}

		const auto width{ GetSystemMetrics( SM_CXSCREEN ) };
		const auto height{ GetSystemMetrics( SM_CYSCREEN ) };

		hwnd = CreateWindowExW( WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TRANSPARENT, L"zdraw", L"zdraw example", WS_POPUP, 0, 0, width, height, nullptr, nullptr, wc.hInstance, nullptr );
		if ( !hwnd )
		{
			return false;
		}

		SetLayeredWindowAttributes( hwnd, RGB( 0, 0, 0 ), 0, LWA_COLORKEY );
		ShowWindow( hwnd, SW_SHOWDEFAULT );
		UpdateWindow( hwnd );

		return true;
	}

	long long __stdcall window::procedure( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
	{
		switch ( msg )
		{

		case WM_LBUTTONDOWN:
		{
			is_dragging = true;
			SetCapture( hwnd );

			POINT cursor{};
			GetCursorPos( &cursor );

			RECT rect{};
			GetWindowRect( hwnd, &rect );

			drag_offset.x = cursor.x - rect.left;
			drag_offset.y = cursor.y - rect.top;
			return 0;
		}

		case WM_LBUTTONUP:
		{
			is_dragging = false;
			ReleaseCapture( );

			return 0;
		}

		case WM_MOUSEMOVE:
		{
			if ( is_dragging )
			{
				POINT cursor{};
				GetCursorPos( &cursor );
				SetWindowPos( hwnd, nullptr, cursor.x - drag_offset.x, cursor.y - drag_offset.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
			}

			return 0;
		}

		case WM_DESTROY:
		{
			PostQuitMessage( 0 );
			return 0;
		}

		}

		return DefWindowProcW( hwnd, msg, wparam, lparam );
	}

	bool directx::initialize( )
	{
		DXGI_SWAP_CHAIN_DESC sc_desc
		{
			.BufferDesc = {.Format = DXGI_FORMAT_R8G8B8A8_UNORM },
			.SampleDesc = {.Count = 1 },
			.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT,
			.BufferCount = 2,
			.OutputWindow = window::hwnd,
			.Windowed = TRUE,
			.SwapEffect = DXGI_SWAP_EFFECT_DISCARD,
			.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH
		};

		constexpr D3D_FEATURE_LEVEL feature_levels[ ]{ D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0 };

		D3D_FEATURE_LEVEL selected{};

		if ( FAILED( D3D11CreateDeviceAndSwapChain( nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, feature_levels, _countof( feature_levels ), D3D11_SDK_VERSION, &sc_desc, &swap_chain, &device, &selected, &device_context ) ) )
		{
			return false;
		}

		ID3D11Texture2D* back_buffer{ nullptr };
		if ( FAILED( swap_chain->GetBuffer( 0, IID_PPV_ARGS( &back_buffer ) ) ) )
		{
			return false;
		}

		const auto result{ device->CreateRenderTargetView( back_buffer, nullptr, &render_target_view ) };
		back_buffer->Release( );

		if ( FAILED( result ) )
		{
			return false;
		}

		D3D11_VIEWPORT viewport
		{
			.TopLeftX = 0.0f,
			.TopLeftY = 0.0f,
			.Width = static_cast< float >( GetSystemMetrics( SM_CXSCREEN ) ),
			.Height = static_cast< float >( GetSystemMetrics( SM_CYSCREEN ) ),
			.MinDepth = 0.0f,
			.MaxDepth = 1.0f
		};

		device_context->RSSetViewports( 1, &viewport );

		if ( !zdraw::initialize( device, device_context ) )
		{
			return false;
		}

		if ( !zui::initialize( window::hwnd ) )
		{
			return false;
		}

		return true;
	}

} // namespace render