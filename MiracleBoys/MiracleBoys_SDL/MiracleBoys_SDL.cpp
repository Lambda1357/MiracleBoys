// MiracleBoys_SDL.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	CSystem* pSystem = new CSystem; //메모리 할당, 객체 생성

	pSystem->Initialize(); //pSystem 초기화

	pSystem->Run(); //

	pSystem->Terminate();

	delete pSystem;

	return 0;
}

