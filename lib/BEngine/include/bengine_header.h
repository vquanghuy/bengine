#ifndef _BENGINE_HEADER_H_
#define _BENGINE_HEADER_H_

////////////////////////////////////////
/// We have 3 basic platform
// PLATFORM_WIN32
// PLATFORM_ANDROID
// PLATFORM_IOS
////////////////////////////////////////

#ifdef _WIN32
#	define PLATFORM_WIN32
#elif defined(_ANDROID)
#	define PLATFORM_ANDROID
#endif

#include <string>
#include "bengine_types.h"
#include "bengine_macros.h"

#endif