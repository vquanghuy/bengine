#ifndef _IPLATFORM_H_
#define _IPLATFORM_H_

namespace BEngine
{
	class IPlatform
	{
		virtual void Create() = 0;
		virtual void Destroy() = 0;
		virtual void Update() = 0;
	};
}

#endif