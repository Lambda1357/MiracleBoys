#include "stdafx.h"

void Button::Init(SDL_Renderer* pRender, std::string addr, SDL_Rect posit, std::function<void()> behavior)
{
	//GameObject 멤버 초기화
	SetPosit(posit);

	//RandererbleObject 멤버 초기화
	LoadSprite(pRender, (BTN_FILEADDR + addr + BTN_ADDR_SPRITE).c_str());

	//직접 소유한 멤버 초기화
	mouseOver	=	MyLoadTextureFromAddress(pRender, BTN_FILEADDR + addr + BTN_ADDR_MOUSEOVER);
	click		=	MyLoadTextureFromAddress(pRender, BTN_FILEADDR + addr + BTN_ADDR_CLICK);
	ButtonBehavior = behavior;
	e_bState = DEFAULT;
}

void Button::Update()
{
	SDL_Rect rtTemp = GetPosit();
	SDL_Point ptTemp	= EVENTHANDLER->GetMousePosition();
	bool isLButtonClick = EVENTHANDLER->IsClick(E_MouseButton::LEFT);
	bool isLButtonPress = EVENTHANDLER->IsPress(E_MouseButton::LEFT);
	bool isLButtonUp = EVENTHANDLER->IsButtonUp(E_MouseButton::LEFT);

	//마우스가 오브젝트 영역 위에 올라와있는지 확인
	bool isMouseOver =	((rtTemp.x <= ptTemp.x) && (ptTemp.x <= (rtTemp.x + rtTemp.w))) &&
						((rtTemp.y <= ptTemp.y) && (ptTemp.y <= (rtTemp.y + rtTemp.h)));
	
	//마우스의 상태에 따라 입력 핸들링이 다르게 이루어짐.
	switch (e_bState)
	{
	case Button::DEFAULT:
		if (isMouseOver)
		{
			if (isLButtonClick) e_bState = CLICK;
			else e_bState = MOUSEOVER;
		}
		break;
	case Button::MOUSEOVER:
		if (isMouseOver)
		{
			if (isLButtonClick) e_bState = CLICK;
		}
		else e_bState = DEFAULT;

		break;
	case Button::CLICK:
		if (isMouseOver)
		{
			if (isLButtonClick || isLButtonPress||isLButtonUp)
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

void Button::Render(SDL_Renderer* pRender)
{
	switch (e_bState)
	{
	case Button::DEFAULT:
		DrawSprite(pRender);
		break;
	case Button::MOUSEOVER:
		SDL_RenderCopy(pRender, mouseOver, NULL, &GetPosit());
		break;
	case Button::CLICK:
		SDL_RenderCopy(pRender, click, NULL, &GetPosit());
		break;
	}
}

void Button::Destroy()
{
	SDL_DestroyTexture(click);
	SDL_DestroyTexture(mouseOver);
	DestroySprite();
}
