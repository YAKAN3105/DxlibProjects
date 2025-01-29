#include "Player.h"
#include "DxLib.h"

Player::Player():
	i(0),
	m_handle(0),
	m_AnimHandle(0),
	m_RunHandle(0),
	m_IdleHandle(0),
	maxAnimNum(0)
{
	m_handle = 0;
}

Player::~Player()
{
}

void Player::Init()
{
	m_IdleHandle = LoadGraph("data/image1/Sprites/King/Idle.png");
	m_RunHandle = LoadGraph("data/image1/Sprites/King/Run.png");
	m_handle = m_IdleHandle;
	i = 0;
	maxAnimNum = 10;
	m_pos = Vec2(500, 500);//�����ʒu
}

void Player::Update()
{
	AnimRoop();
	Move();
	Gravity();
}

void Player::Draw()
{
	//DrawGraph(0, 0, m_handle, TRUE);
	DrawRectGraph(m_pos.x, m_pos.y, 78*i, 0, 78, 58, m_handle, TRUE, FALSE);
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
	if (i == maxAnimNum)
	{
		i = 0;
	}
}

void Player::Move()
{

	if (CheckHitKey(KEY_INPUT_RIGHT) && m_pos.x < 1280 -80)
	{
		m_pos.x += 4;
		m_handle = m_RunHandle;
		maxAnimNum=7;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT) && m_pos.x > 20)
	{
		m_pos.x -= 4;

	}
	else
	{
		m_handle = m_IdleHandle;
	}

}

void Player::Gravity()
{
	if (m_pos.y < 720 -58)
	{
		m_pos.y += 4;
	}
}
