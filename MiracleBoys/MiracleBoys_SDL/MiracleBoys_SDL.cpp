// MiracleBoys_SDL.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	CSystem* pSystem = new CSystem; //�޸� �Ҵ�, ��ü ����

	pSystem->Initialize(); //pSystem �ʱ�ȭ

	pSystem->Run(); //

	pSystem->Terminate();

	delete pSystem;

	return 0;
}

