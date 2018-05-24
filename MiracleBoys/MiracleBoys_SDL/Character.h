#pragma once

	/*	
	*	�ܺο� �����Ͽ� ��������Ʈ ��Ʈ�� �ִϸ��̼��� �پ��� �ӵ��� ���ų�
	*	�ִϸ��̼��� ������ ���·� �ٸ� �̹����� ���� �� �ִ� ��ü
	*	Auther : ������
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

	//�ּ��� ���, �̹��� �̸��� �ۼ�. ��ο� ����(������ ����� ���� �ܾ�)�� ���ο��� ó����
	void Init(SDL_Renderer* pRender, SDL_Rect posit, std::string imgaddr, int frameCnt, int isMoveNow = false, int delay = 0, int framelngth = 0);
	void Update();
	void Render(SDL_Renderer* pRender) const;
	void Destroy();
};