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
	inline bool IsClick(E_MouseButton btn)  const
	{ 
		if (0 <= btn&&btn < MOUSEBUTTON_LAST)
			return m_MouseCur.btn[btn] && (!m_MousePrv.btn[btn]); 
		else
		{
			SDL_Log("EventHandler: Can't Get MouseCode %d.\n", btn);
			return false;
		}
	}
	inline bool IsPress(E_MouseButton btn)	const
	{
		if (0 <= btn&&btn < MOUSEBUTTON_LAST)
			return m_MouseCur.btn[btn];
		else
		{
			SDL_Log("EventHandler: Can't Get MouseCode %d.\n", btn);
			return false;
		}
	}
	inline SDL_Point GetMousePosition()
	{
		SDL_Point pt = { m_MouseCur.x,m_MouseCur.y };
		return pt;
	}
};

#define EVENTHANDLER EventHandler::GetInstance()