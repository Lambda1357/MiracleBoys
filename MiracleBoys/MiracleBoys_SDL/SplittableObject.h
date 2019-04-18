#pragma once

class SplittableObject : protected RenderableObject
{
private:
	int			splitLength;		//스프라이트를 splitLength만큼 일정하게 자름
	bool		isDiractionHorizon;	//가로로 이미지를 자른다면 true, 세로로 자른다면 false
	int			splitCount;			//스프라이트를 자르는 개수
	SDL_Rect	splitOrigin;		//스프라이트의 첫 프레임, 스크롤링이 아닌 변의 폭은 이 변수로 정해진다.

protected:
	inline int GetSplitCount() const { return splitCount; }

	//SplittableObject의 인자를 초기화함. length 인자는 미지정시 rtOrigin의 지정된 종/횡 방향 변의 길이를 따라감.
	void SetSpriteSplit(SDL_Rect rtOrigin, bool isHorizonScr, int FrameCnt, int length = 0);

	//배열 첨자에 넣은 값과 같은 프레임으로 이동 후, 자기 자신을 반환
	virtual const SplittableObject& operator[] (int index);
};