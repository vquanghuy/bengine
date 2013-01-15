#ifndef _BENGINE_HEADER_H_
#define _BENGINE_HEADER_H_

#if defined(PLATFORM_WIN32) || defined(PLATFORM_ANDROID)
typedef unsigned long long	__UINT64;
typedef long long			__INT64;
typedef int					__INT32;
typedef unsigned int		__UINT32;
typedef signed short		__INT16;
typedef unsigned short		__UINT16;
typedef signed char			__INT8;
typedef unsigned char		__UINT8;
typedef char				__CHAR;
typedef char*				__PCHAR;
#endif

#include "bengine_macros.h"

#endif