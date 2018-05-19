#include "stdafx.h"

void RenderableObject::LoadSprite(SDL_Renderer* pRender, _TCHAR* str)
{
	SDL_Surface* tmp;

	tmp = SDL_LoadBMP(_T(str));
	SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
	sprite = SDL_CreateTextureFromSurface(pRender, tmp);
	SDL_FreeSurface(tmp);
}

void RenderableObject::DrawSprite(SDL_Renderer* pRender)
{
	SDL_RenderCopy(pRender, sprite, &GetPosit(), &clipRect);
}

void RenderableObject::DestroySprite()
{
	if (sprite != NULL) SDL_DestroyTexture(sprite);
}
