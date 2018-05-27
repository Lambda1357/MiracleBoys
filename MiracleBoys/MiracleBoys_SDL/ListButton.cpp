#include "stdafx.h"

void ListButton::Init(SDL_Renderer* pRender, std::string addr, SDL_Rect posit, std::function<void()> behavior)
{
	//GameObject 멤버 초기화
	SetPosit(posit);

	//RandererbleObject 멤버 초기화
	LoadSprite(pRender, (BTN_FILEADDR + addr + BTN_ADDR_SPRITE).c_str());

	//SplittableButton 멤버 초기화
	SDL_Rect temp = posit;
	temp.x = temp.y = 0;
	SetSpriteSplit(temp, true, 3);

	//직접 소유한 인자 초기화
	ButtonBehavior = behavior;
	e_bState = DEFAULT;
	isSelect = false;
}

void ListButton::Update()
{
	SDL_Rect rtTemp = GetPosit();
	SDL_Point ptTemp = EVENTHANDLER->GetMousePosition();
	bool isLButtonClick = EVENTHANDLER->IsClick(E_MouseButton::LEFT);
	bool isLButtonPress = EVENTHANDLER->IsPress(E_MouseButton::LEFT);
	bool isLButtonUp = EVENTHANDLER->IsButtonUp(E_MouseButton::LEFT);

	//마우스가 오브젝트 영역 위에 올라와있는지 확인
	bool isMouseOver = ((rtTemp.x <= ptTemp.x) && (ptTemp.x <= (rtTemp.x + rtTemp.w))) &&
		((rtTemp.y <= ptTemp.y) && (ptTemp.y <= (rtTemp.y + rtTemp.h)));

	//마우스의 상태에 따라 입력 핸들링이 다르게 이루어짐.
	switch (e_bState)
	{
	case ListButton::DEFAULT:
		if (isMouseOver)
		{
			if (isLButtonClick) e_bState = CLICK;
			else e_bState = MOUSEOVER;
		}
		break;
	case ListButton::MOUSEOVER:
		if (isMouseOver)
		{
			if (isLButtonClick) e_bState = CLICK;
		}
		else e_bState = DEFAULT;

		break;
	case ListButton::CLICK:
		if (isMouseOver)
		{
			if (isLButtonClick || isLButtonPress || isLButtonUp)
			{
				if (isLButtonUp)
					ButtonBehavior();
			}
			else e_bState = MOUSEOVER;
		}
		else e_bState = DEFAULT;

		break;
	}
}

void ListButton::Render(SDL_Renderer* pRender)
{
	if (isSelect)
	{
		(*this)[MOUSEOVER];
	}
	else
	{
		switch (e_bState)
		{
		case ListButton::DEFAULT:
			(*this)[DEFAULT];
			break;
		case ListButton::MOUSEOVER:
			(*this)[MOUSEOVER];
			break;
		case ListButton::CLICK:
			(*this)[CLICK];
			break;
		}
	}
	DrawSprite(pRender);
}

void ListButton::Destroy()
{
	DestroySprite();
}