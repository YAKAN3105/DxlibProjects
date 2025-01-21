#include "TestScene.h"

void TestScene::Init()
{
	_map.Init();
}

void TestScene::Draw()
{
	/*シーン名の表記*/
	DrawString(0,0,"TestScene\n",GetColor(255,255,255));

	// フレームレート
	DrawFormatString(0, 0,GetColor(255,255,255),"FrameLate%f\n",GetFPS());

	/*mapの描画*/
	_map.Draw();
}
