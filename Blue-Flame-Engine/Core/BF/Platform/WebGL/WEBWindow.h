#pragma once
#include <emscripten.h>
#include <html5.h>
#include <EGL/egl.h>
#include "BF/Application/Window.h"
#include "BF/Platform/API/OpenGL/Context/WEBGLContext.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace WebGL
		{
			class BF_API WEBWindow : public Application::Window
			{
				friend class BF::Platform::API::OpenGL::WEBGLContext;

				private:
					EGLint eglMajVers, eglMinVers;

					EGLNativeWindowType nativeWindow;
					EGLDisplay display;
					EGLSurface surface;
					EGLConfig config;
					EGLint numConfigs;
					EGLint format;

				public:
					WEBWindow(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style);
					~WEBWindow();

					void Initialize();
					void Update();

				private:
					void SetClientSize(int width, int height);

					static EM_BOOL mouseCallback(int eventType, const EmscriptenMouseEvent *e, void *userData);
			};
		}
	}
}