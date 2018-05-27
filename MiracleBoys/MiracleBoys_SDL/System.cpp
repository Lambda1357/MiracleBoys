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

	sceneArray.resize(SCENECOUNT);

	sceneArray[STARTSCENE] = new StartScene;
	sceneArray[STARTSCENE]->Init(const_cast<CSystem*>(this), m_pRender);

	EVENTHANDLER->GetInstance();
	SCENEMANAGER->SetCurrentScene(STARTSCENE);

	return true;
}

void CSystem::Pulse()
{
	CTimeManager::Pulse();


	float fTimeStep = CTimeManager::GetTimeStep();

	if (m_pGameFrame->Update(fTimeStep))
	{
		EVENTHANDLER->HandleEvent();
		//���⿡ ������Ʈ ������Ʈ �ڵ带 ��������======
		sceneArray[SCENEMANAGER->GetCurrentScene()]->Update();

		//===========================================
		SDL_SetRenderDrawColor(m_pRender, MIN8, MIN8, MAX8, MAX8);
		SDL_RenderClear(m_pRender);
		//=======================================================
		//���⿡ ������Ʈ  ���� �ڵ带 ��������
		sceneArray[SCENEMANAGER->GetCurrentScene()]->Render(m_pRender);

		//=======================================================
		SDL_RenderPresent(m_pRender);
	}
}

void CSystem::Terminate()
{
	//���⿡ ���� �ڵ带 ��������

	SCENEMANAGER->DestroyInstance();
	EVENTHANDLER->DestroyInstance();

	sceneArray[STARTSCENE]->Destroy();
	delete sceneArray[STARTSCENE];
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

void CSystem::ChangeScene(SCENENUMBER sn)
{
	sceneArray[SCENEMANAGER->GetCurrentScene()]->OnChangeScene();

	SCENEMANAGER->SetCurrentScene(sn);
}
