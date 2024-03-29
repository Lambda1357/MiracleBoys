#include "stdafx.h"

void SplittableObject::SetSpriteSplit(SDL_Rect rtOrigin, bool isHorizonScr, int FrameCnt, int length)
{
	splitOrigin		=	rtOrigin;
	isDiractionHorizon	=	isHorizonScr;
	splitCount		=	FrameCnt;
	if (!length) splitLength = (isDiractionHorizon ? rtOrigin.w : rtOrigin.h);
	else splitLength = length;

	SetClipRect(rtOrigin);
}

const SplittableObject& SplittableObject::operator[](int index) 
{
	if ((0 <= index) && (index < splitCount))
	{
		SDL_Rect temp = { 0,0,splitOrigin.w,splitOrigin.h };
		if (isDiractionHorizon)	temp.x = splitOrigin.w * index;
		else					temp.y = splitOrigin.h * index;

		SetClipRect(temp);
	}
	else
	{
		SDL_Log("Splittable Object out of range.");
	}

	return *this;
}
