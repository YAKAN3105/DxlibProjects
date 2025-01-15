#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>

SceneTitle::SceneTitle():
m_handle(-1)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	// �O���t�B�b�N�̓ǂݍ��݂�����
	m_handle = LoadGraph("data/Title.png");
	assert(m_handle != -1);
}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[��������
	{
		ChangeScene(new SceneGame);// �Q�[���V�[���Ɉ����z�������[
		return;
	}
}

void SceneTitle::Draw()
{
	// �^�C�g����ʂ̕`��
	DrawGraph(Game::kScreenWidth, Game::kScreenHeight, m_handle, false);
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");// ���܃^�C�g���V�[���ɂ����[
}
