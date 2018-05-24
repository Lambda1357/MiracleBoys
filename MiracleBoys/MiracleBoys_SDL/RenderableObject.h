#pragma once

class RenderableObject : protected GameObject
{
private:
	SDL_Texture* sprite;
	SDL_Rect clipRect;

protected:
	inline void SetClipRect(SDL_Rect rct) { clipRect = rct; }
	inline void SetClipRect(SDL_Point pt1, SDL_Point pt2)
	{
		pt1.x > pt2.x ? Swap(pt1, pt2) : NULL;
		pt1.y > pt2.y ? Swap(pt1.y, pt2.y) : NULL;
		SDL_Rect temp = { pt1.x,pt1.y,pt1.x - pt2.x,pt1.y - pt2.y };
		SetClipRect(temp);
	}
	inline void SetClipRect(int x1, int y1, int x2, int y2)
	{
		x1 > x2 ? Swap(x1, x2) : NULL;
		y1 > y2 ? Swap(y1, y2) : NULL;
		SDL_Rect temp = { x1,y1,x1 - x2,y1 - y2 };
		SetClipRect(temp);
	}

	inline void MoveClipRect(int x, int y)
	{
		clipRect.x = x;
		clipRect.y = y;
	}
	inline void MoveClipRect(SDL_Point pt)
	{
		MoveClipRect(pt.x, pt.y);
	}

	void LoadSprite(SDL_Renderer* pRender, char* str);
	void DrawSprite(SDL_Renderer* pRender) const;
	void DestroySprite();
};