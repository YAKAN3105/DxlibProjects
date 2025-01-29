#include "SceneTitle.h"
#include "SceneGame.h"
#include "DxLib.h"
#include "game.h"
#include <cassert>

SceneTitle::SceneTitle():
m_handle(-1),
m_handle2(-1)
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
	m_handle2 = LoadGraph("data/block1.jpg");
	assert(m_handle2 != -1);
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
	// ��ʑS�̂����œh��Ԃ�
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
	// �^�C�g����ʂ̕`��
	DrawGraph(0, 0, m_handle2, true);
	DrawGraph(0, 0, m_handle, true);
	DrawFormatString(0, 0, 0xffffff, "SceneTitle");// ���܃^�C�g���V�[���ɂ����[
}
