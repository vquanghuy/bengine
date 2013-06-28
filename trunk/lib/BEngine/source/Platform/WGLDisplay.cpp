#include "Platform/WGLDisplay.h"

#ifdef PLATFORM_WIN32

//include for OpenGL
#include <gl/GL.h>
#include <gl/GLU.h>

namespace BEngine
{
	WGLDisplay::WGLDisplay() :	m_bFullScreen(false),
								m_bInit(false),
								m_iWidth(800),
								m_iHeight(600),
								m_sTitle("Game"),
								m_bUseOpenGLES(false)
	{
	}

	WGLDisplay::~WGLDisplay()
	{
	}

	///////////////////////////////////////////////
	//protected function
	///////////////////////////////////////////////
	void WGLDisplay::CreateWin32View()
	{
		WNDCLASS wc;
		RECT wRect;		
		HINSTANCE hInstance;

		wRect.left = 0L;
		wRect.right = (long)m_iWidth;
		wRect.top = 0L;
		wRect.bottom = (long)m_iHeight;

		hInstance = GetModuleHandle(NULL);

		wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wc.lpfnWndProc = (WNDPROC)WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = NULL;
		wc.lpszMenuName = NULL;
		wc.lpszClassName = "main";

		RegisterClass(&wc);

		AdjustWindowRectEx(&wRect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);

		m_hWindow = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE, 
									"main", m_sTitle.c_str(), 
									WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, 
									0, 0, m_iWidth, m_iHeight, NULL, NULL, hInstance, NULL);

		ShowWindow(m_hWindow, SW_SHOW);
		SetForegroundWindow(m_hWindow);
		SetFocus(m_hWindow);

		m_hDisplay = GetDC(m_hWindow);
	}

	LRESULT CALLBACK WGLDisplay::WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam) 
	{
		switch(uiMsg) 
		{
			case WM_CLOSE:
					exit(1);
					return 0;

			case WM_ACTIVATE:
			case WM_KEYDOWN:
			case WM_KEYUP:
			case WM_SIZE: 
			{				
				
			}
			return 0;
		}

		return DefWindowProc(hWnd, uiMsg, wParam, lParam);
	}

	void WGLDisplay::DestroyWin32View()
	{
	}

	///////////////////////////////////////////////
	//public function
	///////////////////////////////////////////////
	s32 WGLDisplay::GetWidth()
	{
		return m_iWidth;
	}

	s32 WGLDisplay::GetHeight()
	{
		return m_iHeight;
	}

	bool WGLDisplay::IsFullScreen()
	{
		return m_bFullScreen;
	}

	bool WGLDisplay::IsInit()
	{
		return m_bInit;
	}

	void WGLDisplay::Create()
	{
		if (!m_bInit)
		{
			CreateWin32View();

			if (!m_bUseOpenGLES)
				InitGL();

			m_bInit = true;
		}
	}

	void WGLDisplay::Create(s32 iWidth, s32 iHeight, bool bUseOpenGLES, std::string sTitle, bool bFullscreen)
	{
		if (!m_bInit)
		{
			m_iWidth = iWidth;
			m_iHeight = iHeight;
			m_sTitle = sTitle;
			m_bFullScreen = bFullscreen;
			m_bUseOpenGLES = bUseOpenGLES;

			CreateWin32View();

			if (!m_bUseOpenGLES)
				InitGL();

			m_bInit = true;
		}

	}

	void WGLDisplay::Destroy()
	{
		if (m_bInit)
		{
			DestroyWin32View();

			//reset all variable to default value
			m_bFullScreen = false;
			m_bInit = false;
			m_iWidth = 800;
			m_iHeight = 600;
			m_sTitle = "Game";

			m_bInit = false;
		}
	}

	void WGLDisplay::Update()
	{
		if(PeekMessage(&m_sMessage, NULL, 0, 0, PM_REMOVE)) 
		{
            if(m_sMessage.message == WM_QUIT) 
			{
                
            } 
			else 
			{
                TranslateMessage(&m_sMessage);
                DispatchMessage(&m_sMessage);
            }
        }
		else
		{
			RefeshGL();
		}
	}

	void WGLDisplay::InitGL()
	{
		PIXELFORMATDESCRIPTOR pfd;
		int iFormat;

		ZeroMemory(&pfd, sizeof(pfd));

		pfd.nSize  = sizeof(pfd);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 24;
		pfd.cDepthBits = 16;
		pfd.iLayerType = PFD_MAIN_PLANE;
		iFormat = ChoosePixelFormat(m_hDisplay, &pfd);
		SetPixelFormat(m_hDisplay, iFormat, &pfd);

		//init hdc and hrc
		HGLRC hRC = wglCreateContext(m_hDisplay);
		wglMakeCurrent(m_hDisplay, hRC);
	}

	void WGLDisplay::RefeshGL()
	{
		SwapBuffers(m_hDisplay);

		glEnable(GL_DEPTH_TEST);
		glDepthMask(true);
		glDepthFunc(GL_LEQUAL);
		glClearDepth(1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}

#endif
