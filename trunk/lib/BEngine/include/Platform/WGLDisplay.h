#ifndef _CPLATFORM_WIN32_H_
#define _CPLATFORM_WIN32_H_

#include "bengine_header.h"

#ifdef PLATFORM_WIN32

#include "Utils/CSingleton.h"
#include "Display.h"

namespace BEngine
{
	//////////////////////////////////////
	// WGLDisplay class
	//////////////////////////////////////
	class WGLDisplay : public CSingleton<WGLDisplay>, public Display
	{
		friend class CSingleton<WGLDisplay>;
		
		WGLDisplay();

		//class variable
	protected:
		s32				m_iWidth;
		s32				m_iHeight;
		bool			m_bFullScreen;
		std::string		m_sTitle;
		bool			m_bInit;
		bool			m_bUseOpenGLES;

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
		virtual ~WGLDisplay();

		//////////////////////////////////////
		// get basic info function
		//////////////////////////////////////
		s32			GetWidth();
		s32			GetHeight();
		bool			IsFullScreen();
		bool			IsInit();

		//////////////////////////////////////
		// create and destroy window function
		//////////////////////////////////////
		void			Create();
		void			Create(s32 iWidth, s32 iHeight, bool bUseOpenGLES = false, std::string sTitle = "Game", bool bFullscreen = false);		
		void			Destroy();

		//////////////////////////////////////
		// update function
		//////////////////////////////////////
		void			Update();

		//////////////////////////////////////
		// OpenGL function
		//////////////////////////////////////
		void			InitGL();
		void			RefeshGL();

		//////////////////////////////////////
		// OpenGL ES function
		// !!!!! IMPLEMENT LATER !!!!!
		//////////////////////////////////////
		

		/////////////////////////////////////
		//temp here
		////////////////////////////////////
		//init the display - return true if success
		virtual bool		Init() { return true; };
		//swap buffer
		virtual void		Swap() { };	
		virtual void		Cleanup() { };

	};
}

#endif

#endif