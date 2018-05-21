#include "stdafx.h"

void EventHandler::HandleEvent()
{
	m_MousePrv = m_MouseCur;	//���� �������� ������ �Է� ������ �������� �Ѱ���

	SDL_Event evnt;
	SDL_PollEvent(&evnt);		//�� �̺�Ʈ�� �޾ƿ�

	bool isButtonHandled[MOUSEBUTTON_LAST] = { 0 };		//DOWN Ȥ�� UP �̺�Ʈ �߻� ���θ� �����ϴ� ����
	
	if		(evnt.button.button == SDL_BUTTON_LEFT)		isButtonHandled[E_MouseButton::LEFT]	= true;
	else if (evnt.button.button == SDL_BUTTON_MIDDLE)	isButtonHandled[E_MouseButton::MIDDLE]	= true;
	else if (evnt.button.button == SDL_BUTTON_RIGHT)	isButtonHandled[E_MouseButton::RIGHT]	= true;
	
	for (int i = 0; i < MOUSEBUTTON_LAST; i++)			//�巡�� ���¸� �����ϱ� ���� �̺�Ʈ�� �߻����� �ʾ��� ���, ���� ���¸� ���� ���·� ������
	{
		if (isButtonHandled[i])	m_MouseCur.btn[i] = (evnt.button.type == SDL_MOUSEBUTTONDOWN);
		else m_MouseCur.btn[i] = m_MousePrv.btn[i];
	}
	
	//���콺 ��ǥ�� �޾ƿ� ����
	int x, y;
	SDL_GetMouseState(&x, &y);
	m_MouseCur.x = x;
	m_MouseCur.y = y;

}
