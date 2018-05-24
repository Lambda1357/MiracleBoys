#include "stdafx.h"

SDL_Texture* MyLoadTextureFromAddress(SDL_Renderer* pRender, std::string addr)
{
	SDL_Surface* tmp;
	SDL_Texture* sprite;

	if ((tmp = SDL_LoadBMP(addr.c_str())) != nullptr)
	{
		SDL_SetColorKey(tmp, SDL_TRUE, SDL_MapRGB(tmp->format, 255, 0, 255));
		sprite = SDL_CreateTextureFromSurface(pRender, tmp);
		SDL_FreeSurface(tmp);

		return sprite;
	}
	else
		return nullptr;
}
