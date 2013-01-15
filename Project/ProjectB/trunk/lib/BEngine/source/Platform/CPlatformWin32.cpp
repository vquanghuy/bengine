#include "Platform/CPlatformWin32.h"

#ifdef PLATFORM_WIN32

namespace BEngine
{
	CPlatformWin32::CPlatformWin32() :	m_bFullScreen(false),
								m_bInit(false),
								m_iWidth(800),
								m_iHeight(600),
								m_sTitle("Game")
	{
	}

	CPlatformWin32::~CPlatformWin32()
	{
	}

	///////////////////////////////////////////////
	//protected function
	///////////////////////////////////////////////
	void CPlatformWin32::CreateWin32View()
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
	}

	LRESULT CALLBACK CPlatformWin32::WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam) 
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

	void CPlatformWin32::DestroyWin32View()
	{
	}

	///////////////////////////////////////////////
	//public function
	///////////////////////////////////////////////
	__INT32 CPlatformWin32::GetWidth()
	{
		return m_iWidth;
	}

	__INT32 CPlatformWin32::GetHeight()
	{
		return m_iHeight;
	}

	__BOOL CPlatformWin32::IsFullScreen()
	{
		return m_bFullScreen;
	}

	__BOOL CPlatformWin32::IsInit()
	{
		return m_bInit;
	}

	void CPlatformWin32::Create(__INT32 iWidth, __INT32 iHeight, __STRING sTitle, __BOOL bFullscreen)
	{
		if (!m_bInit)
		{
			m_iWidth = iWidth;
			m_iHeight = iHeight;
			m_sTitle = sTitle;
			m_bFullScreen = bFullscreen;

			CreateWin32View();

			m_bInit = true;
		}

	}

	void CPlatformWin32::Destroy()
	{
		if (m_bInit)
		{
			DestroyWin32View();
			m_bInit = false;
		}
	}

	void CPlatformWin32::Update()
	{
		if(PeekMessage(&m_sMessage, NULL, 0, 0, PM_REMOVE)) {
            if(m_sMessage.message == WM_QUIT) {
                
            } else {
                TranslateMessage(&m_sMessage);
                DispatchMessage(&m_sMessage);
            }
        }
	}
}

#endif
