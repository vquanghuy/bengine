#ifndef _CSINGLETON_H_
#define _CSINGLETON_H_

namespace BEngine
{
	template <class T>
	class CSingleton
	{
		static T			m_sInstance;

		CSingleton<T>();

	public:
		T					GetInstance();
		void				DestroyInstance();
	};
}

#endif