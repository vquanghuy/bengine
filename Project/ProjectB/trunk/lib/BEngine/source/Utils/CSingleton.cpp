#include "Utils/CSingleton.h"

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