#pragma once

class CBaseWindow
{
protected:
	SDL_Window*		m_pWnd;
	SDL_Renderer*	m_pRender;

	SDL_bool		m_bIsGameRun;

	int originW;
	int originH;

public:
	CBaseWindow(void);
	~CBaseWindow(void);

	bool Initialize();
	void Terminate();

	__inline SDL_Window* GetHandle() const;

	__inline void StopGameRun();
};

__inline SDL_Window* CBaseWindow::GetHandle() const
{
	return m_pWnd;
}

__inline void CBaseWindow::StopGameRun()
{
	m_bIsGameRun = SDL_FALSE;
}

