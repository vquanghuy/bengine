#ifndef _CPLATFORM_WIN32_H_
#define _CPLATFORM_WIN32_H_

#include "bengine_header.h"

#ifdef PLATFORM_WIN32

#include "Utils/CSingleton.h"
#include "IPlatform.h"

namespace BEngine
{
	//////////////////////////////////////
	// CPlatformWin32 class
	//////////////////////////////////////
	class CPlatformWin32 : public CSingleton<CPlatformWin32>, public IPlatform
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
		__BOOL			m_bUseOpenGLES;

		//handle windows
		HWND			m_hWindow;
		HDC				m_hDisplay;

		//message info
		MSG				m_sMessage;

		//protected function
	protected:
		void						CreateWin32View();
		void						DestroyWin32View();

		static LRESULT CALLBACK		WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);
				
	public:
		virtual ~CPlatformWin32();

		//////////////////////////////////////
		// get basic info function
		//////////////////////////////////////
		__INT32			GetWidth();
		__INT32			GetHeight();
		__BOOL			IsFullScreen();
		__BOOL			IsInit();

		//////////////////////////////////////
		// create and destroy window function
		//////////////////////////////////////
		void			Create();
		void			Create(__INT32 iWidth, __INT32 iHeight, __BOOL bUseOpenGLES = false, __STRING sTitle = "Game", __BOOL bFullscreen = false);		
		void			Destroy();

		//////////////////////////////////////
		// update function
		//////////////////////////////////////
		void			Update();

		//////////////////////////////////////
		// OpenGL function
		//////////////////////////////////////
		__BOOL			InitGL();

		//////////////////////////////////////
		// OpenGL ES function
		// !!!!! IMPLEMENT LATER !!!!!
		//////////////////////////////////////
		

	};
}

#endif

#endif