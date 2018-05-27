#include "stdafx.h"

void Character::Init(SDL_Renderer* pRender, SDL_Rect posit, std::string imgaddr, int frameCnt, int isMoveNow, int delay, int framelngth)
{
	//GameObject ��� �ʱ�ȭ
	SetPosit(posit);

	//Renderable+SpittableObject ��� �ʱ�ȭ
	LoadSprite(pRender, (CHARACTER_FILEADDR + imgaddr + CHARACTER_ADDR_SPRITE).c_str());
	if (framelngth == 0)	SetSpriteSplit(GetPosit(), true, frameCnt);
	else					SetSpriteSplit(GetPosit(), true, frameCnt, framelngth);

	//Character ��ü ��� �ʱ�ȭ
	standImg = MyLoadTextureFromAddress(pRender, CHARACTER_FILEADDR + imgaddr + CHARACTER_ADDR_STANDIMG);
	frameDelay = frameCnt;
	isAnimate = isMoveNow;
}

void Character::Update()
{
	static bool isFirstAnimationStop = true;		//�ִϸ��̼� ��ȯ �� ����̹����� ��ȯ�� ���� ����
	static int	curFrameDelay = frameDelay;			//�ִϸ��̼��� �����̸� ���� ������ ī��Ʈ���ִ� ����
	static int	index = 0;							//���� ����Ű�� �ִ� ��������Ʈ �����ӹ�ȣ

	if (isAnimate)
	{
		if (!isFirstAnimationStop)									//�ִϸ��̼� ���� ���·� ó�� ������ ��
		{
			isFirstAnimationStop = true;

			curFrameDelay = frameDelay;	//�����ӵ����� �ʱ�ȭ
			index = 0;					//�ִϸ��̼� ������ �ε��� 0���� �ʱ�ȭ
		}

		if (curFrameDelay-- <= 0)									//������ �����̰� ���� �����Ǿ����� �˻��ϰ�, ������ �����̸� ���ҽ�Ŵ 
		{
			if (index < GetSplitCount())	index++;				//�ε����� �ִϸ��̼� �ִ������ӿ� �������� �ʾҴٸ�
			else							index = 0;				//�ƴ϶�� �ε����� ù �ε���(0��)���� ��ȯ��

			(*this)[index];											//���� ��ü�� ��������Ʈ ��Ʈ index��°�� Ŭ������ �̵�
		}
	}
	else
	{
		if (isFirstAnimationStop)									//�ִϸ��̼� ���� ���·� ó�� ������ ��
		{
			isFirstAnimationStop = false;
			//���⿡ �ִϸ��̼� ���� �� ó���ؾ� �� �ڵ带 �Է�
		}
	}
}

void Character::Render(SDL_Renderer* pRender) const
{
	//������Ʈ���� ó���� ���´�� ���
	if (isAnimate)	DrawSprite(pRender);
	else			SDL_RenderCopy(pRender, standImg, NULL, &GetPosit());
}

void Character::Destroy()
{
	if (standImg != NULL) SDL_DestroyTexture(standImg);
	DestroySprite();
}
