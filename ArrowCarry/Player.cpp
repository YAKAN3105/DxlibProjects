#pragma once
#include "Player.h"
#include <DxLib.h>
#include<cassert>

namespace
{
	unsigned int Color;

	constexpr float kPlayerRadius = 30; // �~�̔��a

	// �L�����N�^�[�̃O���t�B�b�N�̂̕��ƍ���
	constexpr int kGraphWidth = 78;
	constexpr int kGraphHeight = 58;

	// �A�j���[�V�����̃R�}��
	constexpr int kIdleAnimNum = 11;
	constexpr int kRunAnimNum = 8;

	// �A�j���[�V����1�R�}�̃t���[����
	constexpr int kSingleAnimFrame = 4;

	constexpr float kPlayerPosX = 250;
	constexpr float kPlayerPosY = 672;

	constexpr float kPlayerHitWidth = 40;
	constexpr float kPlayerHitHeight = 40;

	constexpr float kGravity = -0.1f;

	constexpr float kJumpSpeed = 10;

}

Player::Player():
	m_handleIdle(-1),
	m_handleRun(-1),
	m_animFrame(0),
	m_isRun(false),
	m_isDirLeft(false),
	m_isJumpNow(false),
	m_isFalling(false),
	m_isMapHit(false),
	m_lastJump(false)
{
	m_speed = 2;
	m_playerNowPos = kPlayerPosX;
	m_jumpPower = 0;
}

Player::~Player()
{
}

void Player::Init()
{
	m_handleIdle = LoadGraph("data/image1/Sprites/King/Idle.png");
	assert(m_handleIdle != -1);

	m_handleRun = LoadGraph("data/image1/Sprites/King/Run.png");
	assert(m_handleRun != -1);

	m_pos.x = kPlayerPosX;
	m_pos.y = kPlayerPosY;
	m_velocity.x = 0;
	m_velocity.y = 0;
}

void Player::End()
{
	// �O���t�B�b�N�̉��
	DeleteGraph(m_handleIdle);
	DeleteGraph(m_handleRun);
}

void Player::Update()
{ 
	
	//if (m_isMapHit)
	//{
	//	ChangePosMapHit();
	//	m_isMapHit = false;
	//	m_isFalling = false;
	//}

	//�O�̃t���[���̈ʒu�̕ۑ�
	m_backPos = m_pos;

	//�ʒu�̍X�V
	m_pos = m_pos + m_velocity;

	//�L�[���͂̊m�F
	// �X�y�[�X�L�[����������L�����N�^�[������悤�ɂ���
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_isRun = true;
		m_pos.x += m_speed;
	}
	else if (CheckHitKey(KEY_INPUT_0))
	{
		m_isRun = false;
		m_pos.x = m_playerNowPos;//�����ʒu�ɖ߂�
	}


#if _DEBUG
	// ��U�L�[�������ē�������悤�ɂ���
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_isRun = true;
		m_velocity.x = m_speed;
		m_isDirLeft = false;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_isRun = true;
		m_velocity.x = -m_speed;
		m_isDirLeft = true;
	}
#endif // DEBUG


	//�A�j���[�V�����̍X�V
	AnimationUpdate();

	//���x�̍X�V
	/*if (m_isRun)
	{
		m_velocity.x = m_speed;
	}*/

	//�W�����v
	if (m_isJumpNow)
	{
		m_velocity.y -= 0.4f;
		m_isJumpNow = false;
		m_isFalling = true;
	}
	//����
	if (m_isFalling)
	{
		m_velocity.y -= kGravity;
	}



}

void Player::AnimationUpdate()
{
	// �A�j���[�V�����̍X�V
	m_animFrame++;

	// �ҋ@���Ƃ��邢�Ă���Ƃ��̃t���[������0^78
	int totalFlame = kIdleAnimNum * kSingleAnimFrame;
	if (m_isRun)
	{
		totalFlame = kRunAnimNum * kSingleAnimFrame;
	}

	// �A�j���[�V�����̍��v�t���[�����𒴂�����ŏ��ɖ߂�
	if (m_animFrame >= totalFlame)
	{
		m_animFrame = 0;
	}
}





void Player::IsHitArrow()
{
	m_isJumpNow = true;

}

void Player::OnArrow(Vec2 vec)
{
	m_velocity = vec;
}

void Player::InitVelocity()
{
	Vec2 zero{0,0};
	m_velocity = zero;
}

void Player::ChangePosMapHit()
{
	//���x���~�߂�
	InitVelocity();
	//1�t���[���O�̈ʒu�ɖ߂�
	m_pos = m_backPos;
	m_isRun = true;
}

void Player::Draw()
{
	/*Color = GetColor(0, 0, 255);
	DrawCircle(m_pos.x, m_pos.y, radius, Color, TRUE);*/

	// �A�j���[�V�����̃t���[�����ƈ�R�}��R�}
	int animNo = m_animFrame / kSingleAnimFrame;

	// �g�p����O���t�B�b�N�̃n���h������U�ʂ�int�^�ϐ��Ɋi�[����
	int useHandle = m_handleIdle;
	if (m_isRun)
	{
		useHandle = m_handleRun;
	}

	// �`��Ɠ����蔻�������
	DrawRectGraph(static_cast<int>(m_pos.x - kGraphWidth *0.4f), static_cast<int>(m_pos.y - kGraphHeight * 0.5f),
		animNo * kGraphWidth, 0, kGraphWidth, kGraphHeight,
		useHandle, true, m_isDirLeft);

	// ������͂�Ă��̘g������
	DrawBox(m_pos.x - kPlayerHitWidth * 0.4f, m_pos.y - kPlayerHitHeight * 0.5f,
		m_pos.x + kPlayerHitWidth * 0.5f, m_pos.y + kPlayerHitHeight * 0.5f,
		0x0000ff, false);
}
