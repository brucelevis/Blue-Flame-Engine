#pragma once
#include <iostream>
#include <Windowsx.h>
#include <Dwmapi.h>
#include "BF/Application/WindowStyle.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application { class Window; }

	namespace Platform
	{
		namespace Windows
		{
			class BF_API WINWindow
			{
				private:
					HWND hWnd;
					MSG msg;
					DWORD currentWindowStyle;
					POINT mousePosition;
					Application::Window* window;

				public:
					WINWindow() = default;
					WINWindow(Application::Window* window);
					~WINWindow();

					void Update();
					bool IsOpen();
					void Move();
					void SetWindowTitle(const std::string& title);
					PIXELFORMATDESCRIPTOR GetPixelFormat() const;

				private:
					void SetClientSize();

				public:
					inline const HWND& GetHWND() const { return hWnd; }

				private:
					static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			};
		}
	}
}