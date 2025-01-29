#include "TitleScene.h"
#include "DxLib.h"

TitleScene::TitleScene():
	m_handle(0)
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	m_handle = LoadGraph("Title.png");
}

void TitleScene::Update()
{

}

void TitleScene::Draw()
{
	DrawString(0, 0, "TitleScene", GetColor(255, 255, 255));
	DrawGraph(0, 0, m_handle, TRUE);
}
