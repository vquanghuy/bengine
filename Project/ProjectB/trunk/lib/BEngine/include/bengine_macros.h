#ifndef _BENGINE_MACROS_
#define _BENGINE_MACROS_

namespace BEngine
{
	// compile - runtime helper
	//fix it later
	/*#ifdef PLATFORM_WIN32
	#	include <stdlib.h>
	#	define TODO(x) __pragma(message("[TODO]:" __FILE__ "("TOSTRING(__LINE__)") " TOSTRING(x))); LOGI(x);
	#	define BREAK_IF(cond, _message) if (cond) {LOGE(_message); _asm int 3}
	#	define BREAK(_message) BREAK_IF(true, _message)
	#	define EXEC(command)	system(command)
	#else
	#	define TODO(x) ;
	#	define WARNING(x) ;
	#	define ERR(x) ;
	#	define BREAK_IF(cond, _message) ;
	#	define BREAK(cond, _message) ;
	#	define EXEC(command)	;
	#endif*/

	// log helper
	#ifdef PLATFORM_WIN32
	#	define LOGI(...)	printf(__VA_ARGS__);printf("\n")
	#	define LOGE(...)	printf(__VA_ARGS__);printf("\n");
	#elif defined(PLATFORM_ANDROID)
	#	include <android/log.h>
	#	define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, "BEngine" ,__VA_ARGS__)
	#	define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, "BEngine" ,__VA_ARGS__)
	#endif

	// some define function
	#define SAFE_DEL(a)					{if(a){delete (a);(a) = NULL;}}
	#define SAFE_DEL_ARRAY(a)			{if(a){delete[] (a);(a) = NULL;}}
}

#endif