#pragma once

class CSystem : public CBaseWindow,
			    public CTimeManager
{	
private:
	CFrameSkip*		m_pGameFrame;
	std::vector<IScene*> sceneArray;

public:
	CSystem(void);
	~CSystem(void);

private:
	void Pulse();

public:
	bool Initialize();
	void Terminate();
	void Run();

	void ChangeScene(SCENENUMBER sn);
};
