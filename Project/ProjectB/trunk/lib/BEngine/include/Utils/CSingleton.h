#ifndef _CSINGLETON_H_
#define _CSINGLETON_H_

template <class T>
class CSingleton
{
	static T			m_sInstance;

	CSingleton<T>();

public:
	T GetInstance();	
};

#endif