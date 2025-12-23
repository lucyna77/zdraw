#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#define NOMINMAX

// linking
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")

// standard
#include <windows.h>
#include <dwmapi.h>

// directx
#include <d3d11.h>
#include <dxgi.h>
#include <dxgi1_3.h>

// core
#include <include/menu/menu.hpp>
#include <include/render/render.hpp>
#include <include/zdraw/zui/zui.hpp>

#endif // !GLOBAL_HPP
