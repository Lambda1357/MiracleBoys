#include "stdafx.h"

void RenderableObject::LoadSprite(SDL_Renderer* pRender, const char* str)
{
	SDL_Surface* tmp;

	if ((tmp = SDL_LoadBMP(str)) != nullptr)
	{
		SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
		sprite = SDL_CreateTextureFromSurface(pRender, tmp);
		SDL_FreeSurface(tmp);
	}
	else
	{
		SDL_Log("Sprite Address \"%s\" is wrong!", str);
	}
}

void RenderableObject::DrawSprite(SDL_Renderer* pRender) const
{
	SDL_RenderCopy(pRender, sprite, &GetPosit(), &clipRect);
}

void RenderableObject::DestroySprite()
{
	if (sprite != NULL) SDL_DestroyTexture(sprite);
}
