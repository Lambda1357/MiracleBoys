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
		//GameObject 인자 초기화
		SetPosit(posit);

		//RanderableObject 인자 초기화
		LoadSprite(pRender, (FIMAGE_FILEADDR + str + FIMAGE_ADDR_SPRITE).c_str());
	}

	//false를 반환하면 생성한 씬에서 삭제해주도록 처리
	bool UpdateChack()
	{
		SDL_Point ptTemp = EVENTHANDLER->GetMousePosition();
		SDL_Rect  rtTemp = GetPosit();
		bool	  isCursurOutBox =	((rtTemp.x >= ptTemp.x) && (ptTemp.x >= (rtTemp.x + rtTemp.w))) &&
									((rtTemp.y >= ptTemp.y) && (ptTemp.y >= (rtTemp.y + rtTemp.h)));
		bool	  isLButtonClick = EVENTHANDLER->IsClick(E_MouseButton::LEFT);

		if (isCursurOutBox&&isLButtonClick) return false;
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