#pragma once

	/*
	*	이벤트 핸들러 싱글톤 객체에 의존하여
	*	마우스올림, 클릭 등 이벤트에 반응하여 작동하는 객체
	*	Auther : 배준형
	*/

#define BTN_FILEADDR		"./Resource/Button/"
#define BTN_ADDR_SPRITE		".bmp"
#define BTN_ADDR_MOUSEOVER	"_mOver.bmp"
#define BTN_ADDR_CLICK		"_clk.bmp"

class Button : protected RenderableObject
{
private:
	SDL_Texture* mouseOver;
	SDL_Texture* click;
	std::function<void()> ButtonBehavior;
	enum ButtonState
	{
		DEFAULT,MOUSEOVER,CLICK
	};
	ButtonState e_bState;

public:
	//주소의 경우, 이미지 이름만 작성. 경로와 서식(마지막 언더바 이후 단어)은 내부에서 처리함
	void Init(SDL_Renderer* pRender, std::string addr, SDL_Rect posit, std::function<void()> behavior);
	void Update();
	void Render(SDL_Renderer* pRender);
	void Destroy();
};