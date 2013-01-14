#include "Utils/CSingleton.h"

#include "bengine_header.h"

namespace BEngine
{
	template <class T>
	CSingleton<T>::CSingleton()
	{
	}

	template <class T>
	T CSingleton<T>::m_sInstance = NULL;

	template <class T>
	T CSingleton<T>::GetInstance()
	{
		if(!m_sInstance)
		{
			m_sInstance = new CSingleton<T>;
		}

		return m_sInstance;	
	}

	template <class T>
	void CSingleton<T>::DestroyInstance()
	{
		if(m_sInstance)
		{
			SAFE_DEL(m_sInstance);
		}

		m_sInstance = NULL;
	}
}