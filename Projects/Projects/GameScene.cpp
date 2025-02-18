#include "GameScene.h"
#include "DxLib.h"
#include"Map.h"
#include"game.h"


GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_map.Init();
	m_score.Init();
	m_player.Init();
	m_enemy.Init();
}

int GameScene::Update()
{
	if (m_player.GetPosY()>Game::kScreenHeight)
	{
		m_enemy.EnemySetUp();
		m_player.PlayerSetUp();
		m_score.ScoreSetUp();
		return 2;
	}
	m_score.Update();
	m_player.Update();
	m_enemy.Update();
	IsColision();
	return 1;
}

void GameScene::Draw()
{
	DrawString(0, 0, "GameScene", GetColor(255, 255, 255));
	m_map.Draw();
	m_score.Draw();
	m_player.Draw();
	m_enemy.Draw();
}

void GameScene::End()
{
	m_map.End();
}

bool GameScene::IsColision()
{
	// プレイヤーとエネミーが当たった判定をとる
	bool isHit = true;
	if (m_player.GetLeft() > m_enemy.GetRight())
	{
		isHit = false;
	}
	if (m_player.GetTop() > m_enemy.GetBottom())
	{
		isHit = false;
	}
	if (m_player.GetRigth() < m_enemy.GetLeft())
	{
		isHit = false;
	}
	if (m_player.GetBottom() < m_enemy.GetTop())
	{
		isHit = false;
	}

	if (isHit)
	{
#ifdef _DEBUG
		printfDx("当たった!\n");
#endif // _DEBUG
		m_player.OnDamage();
	}
	return false;
}
