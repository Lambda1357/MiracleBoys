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
		//여기에 오브젝트  프로세스 코드를 넣으세요

		//=======================================================
		SDL_RenderPresent(m_pRender);
	}
}

void CSystem::Terminate()
{
	//여기에 해제 코드를 넣으세요
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