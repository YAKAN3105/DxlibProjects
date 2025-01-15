#include "SceneGame.h"
#include "SceneTitle.h"
#include "DxLib.h"
#include "SceneResult.h"
#include"Player.h"
#include "Arrow.h"
#include "map.h"
#include "Rect.h"
#include "game.h"

namespace
{
	
}

SceneGame::SceneGame()
{
	m_pPlayer= new Player();
	m_pArrow = new Arrow();
	m_pMap = new Map();
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	m_pPlayer->Init();
	m_pArrow->Init();
	m_pMap->Init();
}

void SceneGame::Update()
{
	m_pPlayer->Update();
	m_pArrow->Update();
	m_pMap->Update();


	//m_pMap->CheckHit();
	//int i = 0;

	//m_pArrow->OnPlayerHit();

	if (CheckHitKey(KEY_INPUT_RETURN)) // Enter�L�[��������
	{
		//ChangeScene(new SceneResult); // ResultScene�Ɉ����z��
		return;
	}

}

void SceneGame::Draw()
{
	// ��ʑS�̂����œh��Ԃ�
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, GetColor(206, 128, 255), true);
	m_pMap->Draw();
	m_pArrow->Draw();
	m_pPlayer->Draw();
	DrawFormatString(0, 0, 0xffffff, "SceneGame");// ���܃Q�[���V�[���ɂ����[
}

//void SceneGame::CheckMapHit()
//{
//	for (int x = 0; x < m_pMap->GetChipIndexX(); x++)
//	{
//		for (int y = 0; y < m_pMap->GetChipIndexY(); y++)
//		{
//			// �v���C���[�ƑS�}�b�v�`�b�v�Ƃ̓����蔻��
//			if (IsBoxHit(m_pPlayer->GetRect(), m_pMap->GetRect(x, y)))
//			{
//				// �ǂ��̃}�b�v�̎��(Kind)�Ȃ̂����Ă�
//				const auto kind = m_pMap->GetKind(x, y); 
//
//				if (kind == MapKind::kGoal)
//				{
//					// �N���A����
//					ChangeScene(new SceneResult); // ResultScene�Ɉ����z��
//					return;
//				}
//				else if (kind == MapKind::kChip)
//				{
//					// �����o������
//
//				}
//
//			}
//		}
//	}
//	
//}

bool SceneGame::IsBoxHit(const Rect& rect1, const Rect& rect2)
{
	if (rect2.GetLeft() <= rect1.GetRight() &&
		rect2.GetRight() >= rect1.GetLeft() &&
		rect2.GetTop() <= rect1.GetBottom() &&
		rect2.GetBottom() >= rect1.GetTop())
	{
		return true;
	}
	else
	{
		return false;
	}
}
