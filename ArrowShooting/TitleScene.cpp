#include "TitleScene.h"
#include "DxLib.h"


TitleScene::TitleScene():
	m_handle1(0),
	m_handle2(0)
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_handle1 = LoadGraph("data/Title.png");
	m_handle2 = LoadGraph("data/block1.jpg");
}

int TitleScene::Update()
{
	// パッドの入力状態を取得
	int padState = GetJoypadInputState(DX_INPUT_PAD1);
	if (padState == PAD_INPUT_A)
	{
		// ゲーム画面に遷移
		return 1;
	}

	return 0;
}

void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(255, 255, 255));
	DrawGraph(0, 0, m_handle2, TRUE);
	DrawGraph(0, 0, m_handle1, TRUE);
}
