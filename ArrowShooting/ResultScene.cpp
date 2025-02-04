#include "ResultScene.h"
#include "DxLib.h"
#include "game.h"


ResultScene::ResultScene()
{
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
	m_fontHandle = CreateFontToHandle("Bernard MT Condensed", 40, 2, DX_FONTTYPE_ANTIALIASING_EDGE_16X16);
	m_handle = LoadGraph("YouLose.png");
}

int ResultScene::Update()
{
	return 2;
}

void ResultScene::Draw(Score& score)
{
	DrawGraph(0, 0, m_handle,FALSE);

	DrawFormatStringToHandle(30, 30, 0xcd5937, m_fontHandle, "SCORE:%d", score.GetScore());
}
