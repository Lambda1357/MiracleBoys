#pragma once

class StartScene : public IScene
{
private:
	SDL_Texture* bg;
	std::vector<Button*> btnArray;
	FloatImage* curFloat = nullptr;
	SDL_Renderer* pRender;

public:
	virtual void Init(CSystem* perent, SDL_Renderer* pRender);
	virtual void Update();
	virtual void Render(SDL_Renderer* pRender);
	virtual void Destroy();
};