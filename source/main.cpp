#include <iostream>
using namespace std;

#include "bengine.h"

int main()
{
	BEngine::WGLDisplay::GetInstance()->Create();

	while(true)
		BEngine::WGLDisplay::GetInstance()->Update();

	return 0;
}