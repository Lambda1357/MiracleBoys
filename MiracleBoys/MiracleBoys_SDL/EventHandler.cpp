#include "stdafx.h"

void EventHandler::HandleEvent()
{
	//���� �������� ������ �Է� ������ ����
	m_MousePrv = m_MouseCur;	

	//�� �̺�Ʈ�� �޾ƿ�
	SDL_Event evnt;
	SDL_PollEvent(&evnt);		

	//DOWN Ȥ�� UP �̺�Ʈ �߻� ���θ� �����ϴ� ����
	bool isButtonHandled[MOUSEBUTTON_LAST] = { 0 };		
	
	if		(evnt.button.button == SDL_BUTTON_LEFT)		isButtonHandled[E_MouseButton::LEFT]	= true;
	else if (evnt.button.button == SDL_BUTTON_MIDDLE)	isButtonHandled[E_MouseButton::MIDDLE]	= true;
	else if (evnt.button.button == SDL_BUTTON_RIGHT)	isButtonHandled[E_MouseButton::RIGHT]	= true;
	
	//�巡�� ���¸� �����ϱ� ���� �̺�Ʈ�� �߻����� ���� ��� ���� ���¸� ������ (SDL������ �����ų� �� ���� �̺�Ʈ �߻���)
	for (int i = 0; i < MOUSEBUTTON_LAST; i++)			
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
