#pragma once

enum SCENENUMBER
{
	STARTSCENE,
	MAINGAME,
	SCENECOUNT
};

class SceneManager : public Singleton<SceneManager>
{
private:
	SCENENUMBER sc;

public:
	SCENENUMBER GetCurrentScene() { return sc; }
	void SetCurrentScene(SCENENUMBER sn)
	{
		if (0 <= sn < SCENECOUNT) sc = sn;
		else SDL_Log("SceneManager: %d is wrong Scene Number!", sn);
	}
};

#define SCENEMANAGER SceneManager::GetInstance()