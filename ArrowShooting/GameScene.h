#pragma once
#include"Map.h"
#include"Player.h"
#include"Enemy.h"
class GameScene
{
public:
	GameScene();
	~GameScene();
	void Init();
	int Update();
	void Draw();
private:
	Map m_map;
	Player m_player;
	Enemy m_enemy;
};

