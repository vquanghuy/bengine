#pragma once

#include "DisplayMode.h"

namespace BEngine
{
	class Display
	{
		//init the display - return true if success
		virtual bool		Init(const DisplayMode& dmode) = 0;
		//swap buffer
		virtual void		Swap() = 0;	
		virtual void		Cleanup() = 0;
	};
}