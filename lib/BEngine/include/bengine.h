#ifndef _BENGINE_H_
#define _BENGINE_H_

#include "bengine_header.h"

#include "Utils/CSingleton.h"
#include "Core/CState.h"
#include "Core/CStateManagement.h"
#include "Platform/CPlatformWin32.h"

#ifdef PLATFORM_WIN32
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"BEngine.lib")
#endif

using namespace BEngine;

#endif