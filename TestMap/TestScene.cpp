#include "TestScene.h"

void TestScene::Init()
{
	_map.Init();
}

void TestScene::Draw()
{
	/*�V�[�����̕\�L*/
	DrawString(0,0,"TestScene\n",GetColor(255,255,255));

	// �t���[�����[�g
	DrawFormatString(0, 0,GetColor(255,255,255),"FrameLate%f\n",GetFPS());

	/*map�̕`��*/
	_map.Draw();
}
