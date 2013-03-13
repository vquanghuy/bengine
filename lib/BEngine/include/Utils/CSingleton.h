#ifndef _CSINGLETON_H_
#define _CSINGLETON_H_

namespace BEngine
{
	template <class T>
	class CSingleton
	{
	protected:
		static T*			m_sInstance;

		CSingleton<T>();

	public:
		~CSingleton<T>();

		static T*			GetInstance();
		static void			DestroyInstance();
	};
}

#include "../../source/Utils/CSingleton.cpp"

#endif