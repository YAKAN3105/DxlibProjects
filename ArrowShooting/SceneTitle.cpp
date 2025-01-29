#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>

SceneTitle::SceneTitle():
m_handle(-1),
m_handle2(-1)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	// グラフィックの読み込みをする
	m_handle = LoadGraph("data/Title.png");
	assert(m_handle != -1);
	m_handle2 = LoadGraph("data/block1.jpg");
	assert(m_handle2 != -1);
}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN)) // Enterキーを押すと
	{
		ChangeScene(new SceneGame);// ゲームシーンに引っ越しするよー
		return;
	}
}

void SceneTitle::Draw()
{
	// 画面全体を紫で塗りつぶす
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
	// タイトル画面の描画
	DrawGraph(0, 0, m_handle2, true);
	DrawGraph(0, 0, m_handle, true);
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");// いまタイトルシーンにいるよー
}
