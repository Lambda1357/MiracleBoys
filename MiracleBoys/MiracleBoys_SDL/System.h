#pragma once

class CSystem : public CBaseWindow,
			    public CTimeManager
{	
private:
	CFrameSkip*		m_pGameFrame;

public:
	CSystem(void);
	~CSystem(void);

private:
	void Pulse();

public:
	bool Initialize();
	void Terminate();
	void Run();
};
