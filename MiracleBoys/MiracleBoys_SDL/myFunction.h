#pragma once

template<typename T>
inline void Swap(T& v1, T& v2)
{
	T temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

SDL_Texture* MyLoadTextureFromAddress(SDL_Renderer* pRender, std::string addr);