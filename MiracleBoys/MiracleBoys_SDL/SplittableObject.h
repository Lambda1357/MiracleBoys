#pragma once

class SplittableObject : protected RenderableObject
{
private:
	int			splitLength;		//��������Ʈ�� splitLength��ŭ �����ϰ� �ڸ�
	bool		isDiractionHorizon;	//���η� �̹����� �ڸ��ٸ� true, ���η� �ڸ��ٸ� false
	int			splitCount;			//��������Ʈ�� �ڸ��� ����
	SDL_Rect	splitOrigin;		//��������Ʈ�� ù ������, ��ũ�Ѹ��� �ƴ� ���� ���� �� ������ ��������.

protected:
	inline int GetSplitCount() const { return splitCount; }

	//SplittableObject�� ���ڸ� �ʱ�ȭ��. length ���ڴ� �������� rtOrigin�� ������ ��/Ⱦ ���� ���� ���̸� ����.
	void SetSpriteSplit(SDL_Rect rtOrigin, bool isHorizonScr, int FrameCnt, int length = 0);

	//�迭 ÷�ڿ� ���� ���� ���� ���������� �̵� ��, �ڱ� �ڽ��� ��ȯ
	virtual const SplittableObject& operator[] (int index);
};