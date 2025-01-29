#include "GameScene.h"
#include "DxLib.h"
#include"Map.h"


GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_map.Init();
	m_player.Init();
}

int GameScene::Update()
{
	m_player.Update();
	return 1;
}

void GameScene::Draw()
{
	DrawString(0, 0, "GameScene", GetColor(255, 255, 255));
	m_map.Draw();
	m_player.Draw();
}
