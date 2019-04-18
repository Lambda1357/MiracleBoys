#include "stdafx.h"

void StartScene::Init(CSystem* m_perent, SDL_Renderer* m_pRender)
{
	SDL_Rect rtTemp;
	Button* temp;
	perent = m_perent;
	pRender = m_pRender;

	bg = MyLoadTextureFromAddress(pRender, SCENE_BACKGROUND_FILEADDR + std::string("StartScene.bmp"));

	temp = new Button;
	MySetRect(rtTemp, 546, 502, 204, 74);
	temp->Init(pRender, "Start", rtTemp, [&]() 
	{
		perent->ChangeScene(PLAYSCENE);
	});
	btnArray.push_back(temp);

	temp = new Button;
	MySetRect(rtTemp, 546, 586, 204, 74);
	temp->Init(pRender, "GameExit", rtTemp, [&]()
	{
		perent->StopGameRun();
	});
	btnArray.push_back(temp);

	temp = new Button;
	MySetRect(rtTemp, 0, 0, 68, 68);
	temp->Init(pRender, "Credit", rtTemp, [&]()
	{
		SDL_Rect tmp = { 0,0,1280,720 };
		curFloat = new FloatImage(pRender, "Credit", tmp);
	});
	btnArray.push_back(temp);

	temp = new Button;
	MySetRect(rtTemp, 0, 652, 68, 68);
	temp->Init(pRender, "Howto", rtTemp, [&]()
	{
		SDL_Rect tmp{ 0,0,1280,720 };
		curFloat = new FloatImage(pRender, "Howto", tmp);
	});
	btnArray.push_back(temp);
}

void StartScene::Update()
{
	//현재 플로팅 창이 존재한다면 창만 업데이트, 플로팅 창에서 참이 반환된다면 창 삭제
	if (curFloat)
	{
		if (!curFloat->UpdateChack())
		{
			delete curFloat;
			curFloat = nullptr;
		}
	}
	else
	{
		for (auto iter = btnArray.begin(); iter != btnArray.end(); iter++)
			(*iter)->Update();
	}
}

void StartScene::Render(SDL_Renderer* pRender)
{
	SDL_RenderCopy(pRender, bg, NULL, NULL);
	for (auto iter = btnArray.rbegin(); iter != btnArray.rend(); iter++)
		(*iter)->Render(pRender);

	if (curFloat) curFloat->Render(pRender);
}

void StartScene::Destroy()
{
	if (curFloat) delete curFloat;
	for (auto iter = btnArray.rbegin(); iter != btnArray.rend(); iter++)
		(*iter)->Destroy();
	SDL_DestroyTexture(bg);
}
