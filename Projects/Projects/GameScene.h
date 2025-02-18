#pragma once
#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include"Score.h"
class GameScene
{
public:
	GameScene();
	~GameScene();
	void Init();
	int Update();
	void Draw();
	void End();
	bool IsColision();
private:
	Map m_map;
	Player m_player;
	Enemy m_enemy;
	Score m_score;
};

