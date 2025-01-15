#include "TestScene.h"

void TestScene::Init()
{
	_map.Init();
}

void TestScene::Draw()
{
	/*シーン名の表記*/
	DrawString(0,0,"TestScene",GetColor(255,255,255));

	/*mapの描画*/
	_map.Draw();
}
