#pragma once

	/*	
	*	외부와 소통하여 스프라이트 시트의 애니메이션을 다양한 속도로 돌거나
	*	애니메이션을 정지한 상태로 다른 이미지를 가질 수 있는 객체
	*	Auther : 배준형
	*/

#define CHARACTER_FILEADDR		"./Resource/Character/"
#define CHARACTER_ADDR_SPRITE	".bmp"
#define CHARACTER_ADDR_STANDIMG	"_stand.bmp"

class Character : protected SplittableObject
{
private:
	SDL_Texture* standImg;
	int frameDelay;
	bool isAnimate;
	
public:
	inline void SetAnimate(bool input)	{ isAnimate = input; }
	inline bool IsAnimate() const		{ return isAnimate;	 }

	inline void SetFrameDelay(int cnt)	{ frameDelay = cnt;	 }

	//주소의 경우, 이미지 이름만 작성. 경로와 서식(마지막 언더바 이후 단어)은 내부에서 처리함
	void Init(SDL_Renderer* pRender, SDL_Rect posit, std::string imgaddr, int frameCnt, int isMoveNow = false, int delay = 0, int framelngth = 0);
	void Update();
	void Render(SDL_Renderer* pRender) const;
	void Destroy();
};