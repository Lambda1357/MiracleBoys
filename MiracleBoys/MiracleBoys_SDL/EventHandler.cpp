#include "stdafx.h"

void EventHandler::HandleEvent()
{
	//이전 루프에서 가져온 입력 정보를 저장
	m_MousePrv = m_MouseCur;	

	//새 이벤트를 받아옴
	SDL_Event evnt;
	SDL_PollEvent(&evnt);		

	//DOWN 혹은 UP 이벤트 발생 여부를 저장하는 변수
	bool isButtonHandled[MOUSEBUTTON_LAST] = { 0 };		
	
	if		(evnt.button.button == SDL_BUTTON_LEFT)		isButtonHandled[E_MouseButton::LEFT]	= true;
	else if (evnt.button.button == SDL_BUTTON_MIDDLE)	isButtonHandled[E_MouseButton::MIDDLE]	= true;
	else if (evnt.button.button == SDL_BUTTON_RIGHT)	isButtonHandled[E_MouseButton::RIGHT]	= true;
	
	//드래그 상태를 검출하기 위해 이벤트가 발생하지 않은 경우 이전 상태를 유지함 (SDL에서는 누르거나 뗄 때만 이벤트 발생함)
	for (int i = 0; i < MOUSEBUTTON_LAST; i++)			
	{
		if (isButtonHandled[i])	m_MouseCur.btn[i] = (evnt.button.type == SDL_MOUSEBUTTONDOWN);
		else m_MouseCur.btn[i] = m_MousePrv.btn[i];
	}
	
	//마우스 좌표를 받아와 저장
	int x, y;
	SDL_GetMouseState(&x, &y);
	m_MouseCur.x = x;
	m_MouseCur.y = y;

}
