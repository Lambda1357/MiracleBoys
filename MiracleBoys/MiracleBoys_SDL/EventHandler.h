#pragma once

enum E_MouseButton
{
	LEFT, RIGHT, MIDDLE , MOUSEBUTTON_LAST
};

typedef struct _MOUSESTATE
{
	int x;		//마우스의 x좌표
	int y;		//마우스의 y좌표
	bool btn[MOUSEBUTTON_LAST];//마우스 버튼의 상태
}MOUSESTATE;

class EventHandler : public Singleton<EventHandler>
{
private:
	MOUSESTATE m_MouseCur = { 0 };
	MOUSESTATE m_MousePrv = { 0 };
public:
	void HandleEvent();

};

#define EVENTHANDLER EventHandler::GetInstance()