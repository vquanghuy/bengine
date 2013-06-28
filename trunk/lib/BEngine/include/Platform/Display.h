#ifndef _IPLATFORM_H_
#define _IPLATFORM_H_

namespace BEngine
{
	class Display
	{
		//init the display - return true if success
		virtual bool		Init() = 0;
		//swap buffer
		virtual void		Swap() = 0;	
		virtual void		Cleanup() = 0;
	};
}

#endif