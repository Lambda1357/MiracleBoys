#include "stdafx.h"

void RenderableObject::LoadSprite(SDL_Renderer* pRender, const char* str)
{
	SDL_Surface* tmp;
	SDL_Rect sizeTmp = { 0,0, };

	if ((tmp = SDL_LoadBMP(str)) != nullptr)
	{
		sizeTmp.w = tmp->w;
		sizeTmp.h = tmp->h;
		SetClipRect(sizeTmp);

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
	SDL_RenderCopy(pRender, sprite, &clipRect, &GetPosit());
}

void RenderableObject::DestroySprite()
{
	if (sprite != NULL) SDL_DestroyTexture(sprite);
}
