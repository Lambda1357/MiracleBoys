#include "stdafx.h"

void SplittableObject::SetSpriteSplit(SDL_Rect rtOrigin, bool isHorizonScr, int FrameCnt, int length)
{
	splitOrigin		=	rtOrigin;
	isHorizonScroll	=	isHorizonScr;
	splitCount		=	FrameCnt;
	if (!length) splitLength = (isHorizonScroll ? splitOrigin.w : splitOrigin.h);
	else splitLength = length;

	SetClipRect(splitOrigin);
}

const SplittableObject& SplittableObject::operator[](int index) 
{
	if ((0 <= index) && (index < splitCount))
	{
		SDL_Rect temp;
		if (isHorizonScroll)	temp.x = splitLength * index;
		else					temp.y = splitLength * index;

		SetClipRect(temp);
	}
	else
	{
		SDL_Log("Splittable Object out of range.");
	}

	return *this;
}
