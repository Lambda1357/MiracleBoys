#include "stdafx.h"

void Character::Init(SDL_Renderer* pRender, SDL_Rect posit, std::string imgaddr, int frameCnt, int isMoveNow, int delay, int framelngth)
{
	//GameObject 멤버 초기화
	SetPosit(posit);

	//Renderable+SpittableObject 멤버 초기화
	SDL_Rect rtTemp = posit;
	rtTemp.x = rtTemp.y = 0;
	LoadSprite(pRender, (CHARACTER_FILEADDR + imgaddr + CHARACTER_ADDR_SPRITE).c_str());
	if (framelngth == 0)	SetSpriteSplit(rtTemp, true, frameCnt);
	else					SetSpriteSplit(rtTemp, true, frameCnt, framelngth);

	//Character 객체 멤버 초기화
	standImg = MyLoadTextureFromAddress(pRender, CHARACTER_FILEADDR + imgaddr + CHARACTER_ADDR_STANDIMG);
	frameDelay = delay;
	isAnimate = isMoveNow;
	isFirstAnimationStop = true;
	curFrameDelay = frameDelay;
	index = 0;
}

void Character::Update()
{
	if (isAnimate)
	{
		if (!isFirstAnimationStop)									//애니메이션 동작 상태로 처음 들어왔을 시
		{
			isFirstAnimationStop = true;

			curFrameDelay = frameDelay;	//프레임딜레이 초기화
			index = 0;					//애니메이션 프레임 인덱스 0으로 초기화
		}

		if (curFrameDelay <= 0)										//프레임 딜레이가 전부 소진되었는지 검사하고, 프레임 딜레이를 감소시킴 
		{
			if (index + 1 < GetSplitCount())	index++;			//인덱스가 애니메이션 최대프레임에 도달하지 않았다면
			else								index = 0;			//아니라면 인덱스를 첫 인덱스(0번)으로 전환함

			curFrameDelay = frameDelay;
			this->operator[](index);								//현재 객체의 스프라이트 시트 index번째로 클립영역 이동
		}
		else curFrameDelay--;
	}
	else
	{
		if (isFirstAnimationStop)									//애니메이션 정지 상태로 처음 들어왔을 시
		{
			isFirstAnimationStop = false;
			//여기에 애니메이션 정지 시 처리해야 할 코드를 입력
		}
	}
}

void Character::Render(SDL_Renderer* pRender) const
{
	//업데이트에서 처리된 상태대로 출력
	if (isAnimate)	DrawSprite(pRender);
	else			SDL_RenderCopy(pRender, standImg, NULL, &GetPosit());
}

void Character::Destroy()
{
	if (standImg != NULL) SDL_DestroyTexture(standImg);
	DestroySprite();
}
