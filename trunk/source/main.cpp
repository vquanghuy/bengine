#include <iostream>
using namespace std;

#include "bengine.h"

int main()
{
	BEngine::CPlatformWin32::GetInstance()->Create();

	while(true)
		BEngine::CPlatformWin32::GetInstance()->Update();

	return 0;
}