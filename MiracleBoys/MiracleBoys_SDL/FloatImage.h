#pragma once

#define FIMAGE_FILEADDR		"./Resource/FloatImage/"
#define FIMAGE_ADDR_SPRITE	".bmp"

class FloatImage : protected RenderableObject
{
private:
	FloatImage();
public:
	FloatImage(SDL_Renderer* pRender, std::string str, SDL_Rect posit)
	{
		//GameObject ���� �ʱ�ȭ
		SetPosit(posit);

		//RanderableObject ���� �ʱ�ȭ
		LoadSprite(pRender, (FIMAGE_FILEADDR + str + FIMAGE_ADDR_SPRITE).c_str());
	}

	//false�� ��ȯ�ϸ� ������ ������ �������ֵ��� ó��
	bool UpdateChack()
	{
		SDL_Point ptTemp = EVENTHANDLER->GetMousePosition();
		SDL_Rect  rtTemp = { 619,570,68,68 };
		bool	  isCursurOnBox =	((rtTemp.x <= ptTemp.x) && (ptTemp.x <= (rtTemp.x + rtTemp.w))) &&
									((rtTemp.y <= ptTemp.y) && (ptTemp.y <= (rtTemp.y + rtTemp.h)));
		bool	  isLButtonClick = EVENTHANDLER->IsClick(E_MouseButton::LEFT);
		bool	  isLButtonPress = EVENTHANDLER->IsPress(E_MouseButton::LEFT);

		if (isCursurOnBox&&(isLButtonClick||isLButtonPress)) 
			return false;
		else return true;
	}

	void Render(SDL_Renderer* pRender)
	{
		DrawSprite(pRender);
	}

	~FloatImage()
	{
		DestroySprite();
	}
};