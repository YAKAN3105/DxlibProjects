#include "Player.h"
#include "DxLib.h"

Player::Player():
	i(0),
	m_handle(0),
	m_animHandle(0),
	m_runHandle(0),
	m_idleHandle(0),
	m_jumpHandle(-1),
	maxAnimNum(0),
	m_isDirLeft(false),
	m_isJump(false)
{
	m_handle = 0;
}

Player::~Player()
{
}

void Player::Init()
{
	m_idleHandle = LoadGraph("data/image1/Sprites/King/Idle.png");
	m_runHandle = LoadGraph("data/image1/Sprites/King/Run.png");
	m_jumpHandle = LoadGraph("data/image1/Sprites/King/Jump.png");
	m_handle = m_idleHandle;
	i = 0;
	maxAnimNum = 10;
	m_pos = Vec2(500, 500);//�����ʒu    
}

void Player::Update()
{
	AnimRoop();
	Move();
	Jump();
	Gravity();
}

void Player::Draw()
{
	//DrawGraph(0, 0, m_handle, TRUE);
	DrawRectGraph(m_pos.x, m_pos.y, 78*i, 0, 78, 58, m_handle, TRUE, m_isDirLeft);
}

void Player::AnimRoop()
{
	//�C���^�[�o���̍X�V
	AnimInterval++;

	//�C���^�[�o����10�t���[���o�߂�����
	if (AnimInterval == 10)
	{
		//���̃A�j���[�V�����Ɉڍs
		i++;
		//�C���^�[�o�������Z�b�g
		AnimInterval = 0;
	}

	//�A�j���[�V�����̃��[�v���Z�b�g
	if (i >= maxAnimNum)
	{
		i = 0;
	}
}

void Player::Move()
{
	// �p�b�h�̓��͏�Ԃ��擾
	int padState = GetJoypadInputState(DX_INPUT_PAD1);

	if (padState == PAD_INPUT_RIGHT && m_pos.x < 1280 -80)
	{
		m_isDirLeft = FALSE;
		m_pos.x += 4;
		m_handle = m_runHandle;
		maxAnimNum=7;
	}
	else if (padState ==  PAD_INPUT_LEFT&& m_pos.x > 20)
	{
		m_isDirLeft = TRUE;
		m_pos.x -= 4;
		m_handle = m_runHandle;
		maxAnimNum = 7;
	}
	else
	{
		m_handle = m_idleHandle;
	}
}

void Player::Gravity()
{
	if (m_pos.y < 720 -58)
	{
		m_pos.y += 4;
	}
}

void Player::Jump()
{
	// �p�b�h�̓��͏�Ԃ��擾
	int padState = GetJoypadInputState(DX_INPUT_PAD1);
	// ���ݒn�ʂɂ��邩
	bool isGround = (m_pos.y >= 660);
	// A�{�^����������Ă��邩
	bool pushA = (padState == PAD_INPUT_A);

	if (pushA && isGround)
	{
		m_isJump = TRUE;
		m_pos.y -= 80;
		m_handle = m_jumpHandle;
		maxAnimNum = 0;
	}
}