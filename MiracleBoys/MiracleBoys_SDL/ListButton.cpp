#include "stdafx.h"

void ListButton::Init(SDL_Renderer* pRender, std::string addr, SDL_Rect posit, std::function<void()> behavior)
{
	//GameObject ��� �ʱ�ȭ
	SetPosit(posit);

	//RandererbleObject ��� �ʱ�ȭ
	LoadSprite(pRender, (BTN_FILEADDR + addr + BTN_ADDR_SPRITE).c_str());

	//SplittableButton ��� �ʱ�ȭ
	SDL_Rect temp = posit;
	temp.x = temp.y = 0;
	SetSpriteSplit(temp, true, 3);

	//���� ������ ���� �ʱ�ȭ
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

	//���콺�� ������Ʈ ���� ���� �ö���ִ��� Ȯ��
	bool isMouseOver = ((rtTemp.x <= ptTemp.x) && (ptTemp.x <= (rtTemp.x + rtTemp.w))) &&
		((rtTemp.y <= ptTemp.y) && (ptTemp.y <= (rtTemp.y + rtTemp.h)));

	//���콺�� ���¿� ���� �Է� �ڵ鸵�� �ٸ��� �̷����.
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