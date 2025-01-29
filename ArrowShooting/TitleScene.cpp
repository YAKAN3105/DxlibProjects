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
	m_handle1 = LoadGraph("Title.png");
	m_handle2 = LoadGraph("data/block1.jpg");
}

int TitleScene::Update()
{
	if (CheckHitKeyAll() > 0)
	{
		// ƒQ[ƒ€‰æ–Ê‚É‘JˆÚ
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
