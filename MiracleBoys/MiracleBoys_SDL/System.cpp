#include "stdafx.h"

CSystem::CSystem(void)
{

}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize()
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pGameFrame = new CFrameSkip;
	m_pGameFrame->SetFramePerSec(60);

	return true;
}

void CSystem::Pulse()
{
	CTimeManager::Pulse();
	EVENTHANDLER->HandleEvent();

	float fTimeStep = CTimeManager::GetTimeStep();

	if (m_pGameFrame->Update(fTimeStep))
	{
		SDL_SetRenderDrawColor(m_pRender, MIN8, MIN8, MAX8, MAX8);
		SDL_RenderClear(m_pRender);
		//=======================================================
		//���⿡ ������Ʈ  ���μ��� �ڵ带 ��������

		//=======================================================
		SDL_RenderPresent(m_pRender);
	}
}

void CSystem::Terminate()
{
	//���⿡ ���� �ڵ带 ��������
	EVENTHANDLER->DestroyInstance();
	CBaseWindow::Terminate();
	CTimeManager::Terminate();
}

void CSystem::Run()
{
	while (m_bIsGameRun)
	{
		Pulse(); //Update()
	}
}