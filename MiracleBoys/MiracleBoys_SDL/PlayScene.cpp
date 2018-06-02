#include "stdafx.h"

void PlayScene::SetAniData()
{
	for (int i = 0; i < MUSIC_END; i++)
	{
		FILE* fp = fopen(MUSICDATA_ADDR(std::to_string(i)).c_str(), "r");
		char strTemp[32];
		while (fgets(strTemp, 32, fp))
		{
			int sec;
			int angel, heart, mino, unicorn, yonghu;
			sscanf(strTemp, "%d %d %d %d %d %d", &sec, &angel, &heart, &mino, &unicorn, &yonghu);
			aniData[i].insert_or_assign(sec, AnimateData(angel, heart, mino, unicorn, yonghu));
		}
		if (fclose(fp))
			SDL_Log("Song data temp cleanup failed! Chack %d.txt \n", i);
	}
}

void PlayScene::ApplyCurNode()
{
	CharaList[ANGEL]->SetAnimate(curNode->second.isMoveNow[ANGEL]);
	CharaList[HEART]->SetAnimate(curNode->second.isMoveNow[HEART]);
	CharaList[MINO]->SetAnimate(curNode->second.isMoveNow[MINO]);
	CharaList[UNICORN]->SetAnimate(curNode->second.isMoveNow[UNICORN]);
	CharaList[YONGHU]->SetAnimate(curNode->second.isMoveNow[YONGHU]);
}

void PlayScene::ApplyPrvNode()
{
	CharaList[ANGEL]->SetAnimate(prvNode->second.isMoveNow[ANGEL]);
	CharaList[HEART]->SetAnimate(prvNode->second.isMoveNow[HEART]);
	CharaList[MINO]->SetAnimate(prvNode->second.isMoveNow[MINO]);
	CharaList[UNICORN]->SetAnimate(prvNode->second.isMoveNow[UNICORN]);
	CharaList[YONGHU]->SetAnimate(prvNode->second.isMoveNow[YONGHU]);
}

void PlayScene::StopAnimate()
{
	for (int i = 0; i < CHARALIST_END; i++)
	{
		CharaList[i]->SetAnimate(false);
	}
}

void PlayScene::Init(CSystem* m_perent, SDL_Renderer* pRender)
{
	SDL_Rect rtTemp;
	Button* temp;
	ListButton* lTemp;
	perent = m_perent;

	bg = MyLoadTextureFromAddress(pRender, SCENE_BACKGROUND_FILEADDR + std::string("PlayScene.bmp"));

	//Button
	temp = new Button;
	MySetRect(rtTemp, 0, 0, 68, 68);
	temp->Init(pRender, "SceneExit", rtTemp, [&]()
	{
		perent->ChangeScene(STARTSCENE);
	});
	btnArray.push_back(temp);

	temp = new Button;
	MySetRect(rtTemp, 1104, 32, 40, 40);
	temp->Init(pRender, "Play", rtTemp, [&]()
	{
		if (MUSICMANAGER->GetState() == PAUSE)
		{
			ApplyPrvNode();
		}
		MUSICMANAGER->Play();
	});
	btnArray.push_back(temp);
	
	temp = new Button;
	MySetRect(rtTemp, 1166, 32, 40, 40);
	temp->Init(pRender, "Pause", rtTemp, [&]()
	{
		MUSICMANAGER->Pause();
		StopAnimate();
	});
	btnArray.push_back(temp);

	temp = new Button;
	MySetRect(rtTemp, 1230, 32, 40, 40);
	temp->Init(pRender, "Stop", rtTemp, [&]()
	{
		MUSICMANAGER->Stop();
		StopAnimate();
		prvNode = curNode = aniData[MUSICMANAGER->GetCurTrack()].begin();
	});
	btnArray.push_back(temp);

	//ListButton
	MySetRect(rtTemp, 997, 91, 283, 110);
	for (int i = 0; i < MUSIC_END; i++)
	{
		lTemp = new ListButton;
		lTemp->Init(pRender, "Song" + std::to_string(i), rtTemp, [&, i] ()
		{
			int curentTrack = MUSICMANAGER->GetCurTrack();
			if (curentTrack != i)
			{
				musicList[curentTrack]->SetSelected(false);
				MUSICMANAGER->ChangeTrackTo(i);
				musicList[MUSICMANAGER->GetCurTrack()]->SetSelected(true);
				prvNode = curNode = aniData[i].begin();
				StopAnimate();
			}
		});
		musicList[i] = lTemp;
		rtTemp.y += 119;
	}

	//Character
	CharaList[ANGEL] = new Character;
	MySetRect(rtTemp, 500, 207, 512, 512);
	CharaList[ANGEL]->Init(pRender, rtTemp, "angel", 6, false, 6);

	CharaList[HEART] = new Character;
	MySetRect(rtTemp, 637, 80, 512, 512);
	CharaList[HEART]->Init(pRender, rtTemp, "heart", 5, false, 6);

	CharaList[MINO] = new Character;
	MySetRect(rtTemp, 0, 80, 512, 512);
	CharaList[MINO]->Init(pRender, rtTemp, "mino", 5, false, 6);

	CharaList[UNICORN] = new Character;
	MySetRect(rtTemp, 135, 208, 512, 512);
	CharaList[UNICORN]->Init(pRender, rtTemp, "unicorn", 5, false, 6);

	CharaList[YONGHU] = new Character;
	MySetRect(rtTemp, 338, 80, 512, 512);
	CharaList[YONGHU]->Init(pRender, rtTemp, "yonghu", 8, false, 6);

	SetAniData();
	curNode = aniData[0].begin();
	musicList[0]->SetSelected(true);
}

void PlayScene::Update()
{
	MUSICMANAGER->UpdateTime();

	for (auto iter = btnArray.begin(); iter != btnArray.end(); iter++)
		(*iter)->Update();

	for (int i = 0; i < MUSIC_END; i++)
	{
		musicList[i]->Update();
	}
	for (int i = 0; i < CHARALIST_END; i++)
	{
		CharaList[i]->Update();
	}

	if (MUSICMANAGER->GetState() == PLAY)
	{
		if ((MUSICMANAGER->GetElipseTime() >= curNode->first)&&
			(curNode != aniData[MUSICMANAGER->GetCurTrack()].end()))
		{
			ApplyCurNode();
			prvNode = curNode++;
		}
	}
}

void PlayScene::Render(SDL_Renderer * pRender)
{
	SDL_RenderCopy(pRender, bg, NULL, NULL);

	CharaList[YONGHU]->Render(pRender);
	CharaList[MINO]->Render(pRender);
	CharaList[HEART]->Render(pRender);
	CharaList[UNICORN]->Render(pRender);
	CharaList[ANGEL]->Render(pRender);

	for (auto iter = btnArray.begin(); iter != btnArray.end(); iter++)
		(*iter)->Render(pRender);
	for (int i = 0; i < MUSIC_END; i++)
	{
		musicList[i]->Render(pRender);
	}
}

void PlayScene::Destroy()
{
	for (int i = CHARALIST_END; i >= 0; i--)
	{
		CharaList[i]->Destroy();
	}
	for (int i = MUSIC_END; i >= 0; i--)
	{
		musicList[i]->Destroy();
	}
	for (auto iter = btnArray.rbegin(); iter != btnArray.rend(); iter++)
	{
		(*iter)->Destroy();
	}
	SDL_DestroyTexture(bg);
}

void PlayScene::OnChangeScene()
{
	MUSICMANAGER->SetUp();
}
