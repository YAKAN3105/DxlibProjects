#include "SceneResult.h"
#include "SceneTitle.h"
#include "DxLib.h"

SceneResult::SceneResult()
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Init()
{
}

void SceneResult::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))// Enter�L�[��������
	{
		ChangeScene(new SceneTitle); // �^�C�g���V�[���Ɉ����z�������
		return;
	}
}

void SceneResult::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "SceneResult"); // ���܃��U���g�V�[���ɂ����[
}
