#pragma once

class ListButton : protected SplittableObject
{
private:
	std::function<void()> ButtonBehavior;
	enum ButtonState
	{
		DEFAULT, MOUSEOVER, CLICK
	};
	ButtonState e_bState;
	bool isSelect;
public:
	void Init(SDL_Renderer* pRender, std::string addr, SDL_Rect posit, std::function<void()> behavior);
	void Update();
	void Render(SDL_Renderer* pRender);
	void Destroy();

	inline void SetSelected(bool tf)
	{
		isSelect = tf;
	}
};