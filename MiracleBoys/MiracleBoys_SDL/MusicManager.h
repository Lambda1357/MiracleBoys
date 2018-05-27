#pragma once

#define MUSIC_ADDRESS(name)	(std::string("./resource/Music/")+name+".mp3")
#define MUSIC_END 5

enum E_PlayState
{
	PLAY,
	PAUSE,
	STOP
};

class MusicManager : public Singleton<MusicManager>
{
private:	
	int ElipseTime;

	int curTrackNum;
	E_PlayState playState;

public:
	void SetUp()
	{
		playState = STOP;
		ElipseTime = 0;
		curTrackNum = 0;
		for (int i = 0; i < MUSIC_END; i++)
		{
			mciSendString(("stop " + MUSIC_ADDRESS(std::to_string(i))).c_str(), NULL, 0, NULL);
		}
	}
	void Play()
	{
		if ((playState == PAUSE) || (playState == STOP))
		{
			mciSendString(("play " + MUSIC_ADDRESS(std::to_string(curTrackNum))).c_str(), NULL, 0, NULL);
			playState = PLAY;
			if (playState == STOP)
			{
				ElipseTime = 0;
			}
		}
	}

	void Stop()
	{
		if ((playState == PLAY)||(playState==PAUSE))
		{
			mciSendString(("stop " + MUSIC_ADDRESS(std::to_string(curTrackNum))).c_str(), NULL, 0, NULL);
			ElipseTime = 0;
			playState = STOP;
		}
	}
	void Pause()
	{
		if (playState == PLAY)
		{
			mciSendString(("pause " + MUSIC_ADDRESS(std::to_string(curTrackNum))).c_str(), NULL, 0, NULL);
			playState = PAUSE;
		}
	}

	void ChangeTrackTo(int num)
	{
		if (0 <= num&&num < MUSIC_END)
		{
			if ((playState == PLAY) || (playState == PAUSE))
			{
				mciSendString(("stop " + MUSIC_ADDRESS(std::to_string(curTrackNum))).c_str(), NULL, 0, NULL);
				ElipseTime = 0;
				playState = STOP;
				curTrackNum = num;
			}
		}
		else
			SDL_Log("MusicManager: Change Track Failed. %d is not Music code!", num);
	}

	void UpdateTime()
	{
		if(playState==PLAY)
			ElipseTime++;
	}

	//지난 시간을 초 단위로 버림하여 알려줌
	int GetElipseTime()
	{
		float temp = ElipseTime / 60.0f;
		return (int)floor(temp);
	}

	int GetCurTrack()
	{
		return curTrackNum;
	}

	E_PlayState GetState()
	{
		return playState;
	}
};

#define MUSICMANAGER MusicManager::GetInstance()