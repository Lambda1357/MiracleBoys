#pragma once

class IScene
{
public:
	virtual void OnChangeScene() {};

	virtual void Init(SDL_Renderer*) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*) = 0;
	virtual void Destroy() = 0;
};