#ifndef _CWIN32_VIEW_H_
#define _CWIN32_VIEW_H_

#ifdef PLATFORM_WIN32

#include "bengine_header.h"
#include "Utils/CSingleton.h"

namespace BEngine
{
	class CPlatformWin32 : public CSingleton<CPlatformWin32>
	{
		friend class CSingleton<CPlatformWin32>;
		
		CPlatformWin32();

		//class variable
	protected:
		__INT32			m_iWidth;
		__INT32			m_iHeight;
		__BOOL			m_bFullScreen;
		__STRING		m_sTitle;
		__BOOL			m_bInit;

		//handle windows
		HWND			m_hWindow;
		HDC				m_hDisplay;

		//protected function
	protected:
		void						CreateWin32View();
		void						DestroyWin32View();

		static LRESULT CALLBACK		WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);
				
	public:
		virtual ~CPlatformWin32();

		__INT32			GetWidth();
		__INT32			GetHeight();
		__BOOL			IsFullScreen();
		__BOOL			IsInit();

		void			Create(__INT32 iWidth = 800 , __INT32 iHeight = 600, __STRING sTitle = "Game", __BOOL bFullscreen = false);
		void			Destroy();
	};
}

#endif

#endif