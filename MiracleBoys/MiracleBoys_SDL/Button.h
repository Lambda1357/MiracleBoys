#pragma once

	/*
	*	�̺�Ʈ �ڵ鷯 �̱��� ��ü�� �����Ͽ�
	*	���콺�ø�, Ŭ�� �� �̺�Ʈ�� �����Ͽ� �۵��ϴ� ��ü
	*	Auther : ������
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
	//�ּ��� ���, �̹��� �̸��� �ۼ�. ��ο� ����(������ ����� ���� �ܾ�)�� ���ο��� ó����
	void Init(SDL_Renderer* pRender, std::string addr, SDL_Rect posit, std::function<void()> behavior);
	void Update();
	void Render(SDL_Renderer* pRender);
	void Destroy();
};