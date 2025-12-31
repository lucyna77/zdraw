#ifndef STYLE_HPP
#define STYLE_HPP

#include <include/zdraw/zdraw.hpp>

namespace zui {

    struct style
    {
        float window_padding_x{ 10.0f };
        float window_padding_y{ 10.0f };
        float item_spacing_x{ 8.0f };
        float item_spacing_y{ 6.0f };
        float frame_padding_x{ 6.0f };
        float frame_padding_y{ 3.0f };
        float border_thickness{ 1.0f };

        float group_box_title_height{ 18.0f };
        float checkbox_size{ 14.0f };
        float slider_height{ 10.0f };
        float keybind_width{ 80.0f };
        float keybind_height{ 20.0f };
        float combo_height{ 22.0f };
        float combo_item_height{ 20.0f };
        float color_picker_swatch_size{ 14.0f };
        float color_picker_popup_width{ 180.0f };
        float color_picker_popup_height{ 220.0f };
        float text_input_height{ 22.0f };

        float scrollbar_width{ 6.0f };
        float scrollbar_padding{ 2.0f };
        float scrollbar_min_thumb_height{ 20.0f };

        zdraw::rgba window_bg{ 22, 24, 28, 255 };
        zdraw::rgba window_border{ 52, 56, 62, 255 };

        zdraw::rgba nested_bg{ 16, 18, 21, 255 };
        zdraw::rgba nested_border{ 46, 50, 56, 255 };

        zdraw::rgba group_box_bg{ 16, 18, 21, 255 };
        zdraw::rgba group_box_border{ 42, 46, 52, 255 };
        zdraw::rgba group_box_title_text{ 175, 180, 190, 255 };

        zdraw::rgba checkbox_bg{ 28, 31, 36, 255 };
        zdraw::rgba checkbox_border{ 55, 60, 68, 255 };
        zdraw::rgba checkbox_check{ 95, 160, 230, 255 };

        zdraw::rgba slider_bg{ 28, 31, 36, 255 };
        zdraw::rgba slider_border{ 55, 60, 68, 255 };
        zdraw::rgba slider_fill{ 85, 150, 220, 255 };
        zdraw::rgba slider_grab{ 95, 160, 230, 255 };
        zdraw::rgba slider_grab_active{ 115, 175, 245, 255 };

        zdraw::rgba button_bg{ 32, 35, 42, 255 };
        zdraw::rgba button_border{ 58, 63, 72, 255 };
        zdraw::rgba button_hovered{ 42, 46, 54, 255 };
        zdraw::rgba button_active{ 26, 29, 34, 255 };

        zdraw::rgba keybind_bg{ 28, 31, 36, 255 };
        zdraw::rgba keybind_border{ 55, 60, 68, 255 };
        zdraw::rgba keybind_waiting{ 95, 160, 230, 255 };

        zdraw::rgba combo_bg{ 28, 31, 36, 255 };
        zdraw::rgba combo_border{ 55, 60, 68, 255 };
        zdraw::rgba combo_arrow{ 145, 150, 160, 255 };
        zdraw::rgba combo_hovered{ 38, 42, 50, 255 };
        zdraw::rgba combo_popup_bg{ 20, 22, 26, 255 };
        zdraw::rgba combo_popup_border{ 52, 56, 62, 255 };
        zdraw::rgba combo_item_hovered{ 40, 44, 52, 255 };
        zdraw::rgba combo_item_selected{ 95, 160, 230, 35 };

        zdraw::rgba color_picker_bg{ 28, 31, 36, 255 };
        zdraw::rgba color_picker_border{ 55, 60, 68, 255 };

        zdraw::rgba text_input_bg{ 28, 31, 36, 255 };
        zdraw::rgba text_input_border{ 55, 60, 68, 255 };

        zdraw::rgba scrollbar_bg{ 20, 22, 26, 100 };
        zdraw::rgba scrollbar_thumb{ 65, 70, 80, 200 };
        zdraw::rgba scrollbar_thumb_hovered{ 85, 92, 105, 220 };
        zdraw::rgba scrollbar_thumb_active{ 95, 160, 230, 255 };

        zdraw::rgba text{ 220, 222, 228, 255 };
        zdraw::rgba accent{ 95, 160, 230, 255 };
    };

	enum class style_var
	{
		window_padding_x,
		window_padding_y,
		item_spacing_x,
		item_spacing_y,
		frame_padding_x,
		frame_padding_y,
		border_thickness,
		group_box_title_height,
		checkbox_size,
		slider_height,
		keybind_height,
		combo_height,
		combo_item_height
	};

	enum class style_color
	{
		window_bg,
		window_border,
		nested_bg,
		nested_border,
		group_box_bg,
		group_box_border,
		group_box_title_text,
		checkbox_bg,
		checkbox_border,
		checkbox_check,
		slider_bg,
		slider_border,
		slider_fill,
		slider_grab,
		slider_grab_active,
		button_bg,
		button_border,
		button_hovered,
		button_active,
		keybind_bg,
		keybind_border,
		keybind_waiting,
		combo_bg,
		combo_border,
		combo_arrow,
		combo_hovered,
		combo_popup_bg,
		combo_popup_border,
		combo_item_hovered,
		combo_item_selected,
		color_picker_bg,
		color_picker_border,
		text_input_bg,
		text_input_border,
		text,
		accent
	};

} // namespace zui

#endif // !STYLE_HPP