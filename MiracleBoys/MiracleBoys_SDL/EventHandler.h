#pragma once

enum E_MouseButton
{
	LEFT, RIGHT, MIDDLE , MOUSEBUTTON_LAST
};

typedef struct _MOUSESTATE
{
	int x;		//���콺�� x��ǥ
	int y;		//���콺�� y��ǥ
	bool btn[MOUSEBUTTON_LAST];//���콺 ��ư�� ����
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