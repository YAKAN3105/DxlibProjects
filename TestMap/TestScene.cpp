#include "TestScene.h"

void TestScene::Init()
{
	_map.Init();
}

void TestScene::Draw()
{
	/*�V�[�����̕\�L*/
	DrawString(0,0,"TestScene",GetColor(255,255,255));

	/*map�̕`��*/
	_map.Draw();
}
