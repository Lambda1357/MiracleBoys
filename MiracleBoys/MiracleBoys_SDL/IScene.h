#pragma once
class CSystem;

class IScene
{
protected:
	CSystem* perent;

public:
	virtual void OnChangeScene() {};

	virtual void Init(CSystem* perent, SDL_Renderer*) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*) = 0;
	virtual void Destroy() = 0;
};