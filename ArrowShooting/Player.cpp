#include "Player.h"
#include "DxLib.h"
namespace
{
	// �v���C���[�̃O���t�B�b�N�̃T�C�Y
	int kGraphWidth = 78;
	int kGraphHeight = 58;

	// �v���C���[���_���[�W���󂯂����̓_�Ŏ���
	constexpr int kDamageBlink = 30;

	// �v���C���[�̏���HP
	constexpr int kMaxHp = 3;

	constexpr int kDeadStopFrame = 30; // ���񂾌�Ɏ~�܂鎞��
}

Player::Player():
	i(0),
	m_handle(0),
	m_animHandle(0),
	m_runHandle(0),
	m_idleHandle(0),
	m_jumpHandle(-1),
	maxAnimNum(0),
	m_isDirLeft(false),
	m_isJump(false),
	m_blinkFrameCount(0),
	m_hp(kMaxHp)
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
	// ���G���Ԃ̍X�V
	m_blinkFrameCount--;
	if (m_blinkFrameCount < 0)
	{
		m_blinkFrameCount = 0;
	}
	AnimRoop();
	Move();
	Jump();
	Gravity();
	if (m_hp <= 0)
	{
		UpdateDead();
	}
}

void Player::Draw()
{
	//DrawGraph(0, 0, m_handle, TRUE);
	// �_�ł��鎞��
	if (m_hp != 0)
	{
		if (m_blinkFrameCount / 2 % 2)
		{
			return;
			
		}
	}
	
	// ���񂾂�㉺���]������
	bool isDead = false;
	if (m_hp <= 0)
	{
		isDead = true;
	}
	// �v���C���[�̕`��
	DrawRectGraph(m_pos.x, m_pos.y, 78*i, 0, kGraphWidth, kGraphHeight, m_handle, TRUE, m_isDirLeft,isDead);
#if _DEBUG
	DrawCircle(m_pos.x, m_pos.y, 5, 0x0000ff, 1, 1);
	//�����蔻��̉��\��
	DrawBox(GetLeft(), GetTop(), GetRigth(), GetBottom(),0xff0000,FALSE);
#endif // _DEBUG

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
	if (m_hp == 0)
	{
		return;
	}
	// �p�b�h�̓��͏�Ԃ��擾
	int padState = GetJoypadInputState(DX_INPUT_PAD1);

	if (padState == PAD_INPUT_RIGHT && m_pos.x < 1280 -80)
	{
		m_isDirLeft = FALSE;
		m_pos.x += m_speed;
		m_handle = m_runHandle;
		maxAnimNum=7;
	}
	else if (padState ==  PAD_INPUT_LEFT&& m_pos.x > 20)
	{
		m_isDirLeft = TRUE;
		m_pos.x -= m_speed;
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
		m_pos.y += 3;
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
		m_pos.y -= m_jumpSpeed;
		m_handle = m_jumpHandle;
		maxAnimNum = 0;
	}
}

float Player::GetLeft()
{
	return (m_pos.x);
}

float Player::GetRigth()
{
	return (m_pos.x + kGraphWidth/2);
}

float Player::GetTop()
{
	return (m_pos.y - kGraphHeight +70);
}

float Player::GetBottom()
{
	return (m_pos.y + kGraphHeight -10 );
}

void Player::OnDamage()
{
	if (m_blinkFrameCount > 0)
	{
		return;
	}
	// ���G����(�_�ł��鎞��)��ݒ肷��
	m_blinkFrameCount = kDamageBlink;
	m_hp--;
	if (m_hp <= 0)
	{
		
		m_deadFrameCount;
	}
}

void Player::UpdateDead()
{
	// ���S���u�~�܂�
	m_deadFrameCount++;
	if (m_deadFrameCount < kDeadStopFrame)
	{
		return;
	}
	m_pos.y += 4;

}