#pragma once

class GameObject
{
private:
	SDL_Rect posit;

protected:
	inline void SetPosit(SDL_Rect rct) { posit = rct; }
	inline void SetPosit(SDL_Point pt1, SDL_Point pt2)
	{
		pt1.x < pt2.x ? Swap(pt1, pt2)		: NULL;
		pt1.y < pt2.y ? Swap(pt1.y, pt2.y)	: NULL;
		SDL_Rect temp = { pt1.x,pt1.y,pt1.x - pt2.x,pt1.y - pt2.y };
		SetPosit(temp);
	}
	inline void SetPosit(int x1, int y1, int x2, int y2)
	{
		x1 < x2 ? Swap(x1, x2) : NULL;
		y1 < y2 ? Swap(y1, y2) : NULL;
		SDL_Rect temp = { x1,y1,x1 - x2,y1 - y2 };
		SetPosit(temp);
	}

	inline void MovePosit(int x, int y)
	{
		posit.x = x;
		posit.y = y;
	}
	inline void MovePosit(SDL_Point pt)
	{
		MovePosit(pt.x, pt.y);
	}


	inline SDL_Rect GetPosit() const { return posit; }
};