#pragma once

#define ANIMATEDATA_FILEADDR	"./Resource/AnimateData/"

enum E_CharaList
{
	ANGEL,HEART,MINO,UNICORN,YONGHU,CHARALIST_END
};

class AnimateData
{
public:
	bool isMoveNow[CHARALIST_END] = { 0 };
	AnimateData(bool angel, bool heart, bool mino, bool unicorn, bool yonghu)
	{
		isMoveNow[ANGEL] = angel, isMoveNow[HEART] = heart, isMoveNow[MINO] = mino,
			isMoveNow[UNICORN] = unicorn, isMoveNow[YONGHU] = yonghu;
	}
};

class PlayScene : public IScene
{
private:
	SDL_Texture*							bg;
	ListButton*								musicList[MUSIC_END];
	std::vector<Button*>					btnArray;
	Character*								CharaList[CHARALIST_END];

	std::map<int, AnimateData>				aniData[MUSIC_END];
	std::map<int, AnimateData>::iterator	curNode, prvNode;

	void SetAniData();
	void ApplyCurNode();
	void ApplyPrvNode();
	void StopAnimate();

public:
	virtual void Init(CSystem* perent, SDL_Renderer* pRender);
	virtual void Update();
	virtual void Render(SDL_Renderer* pRender);
	virtual void Destroy();

	virtual void OnChangeScene();
};