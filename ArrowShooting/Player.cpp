#include "Player.h"
#include "DxLib.h"
namespace
{
	// プレイヤーのグラフィックのサイズ
	int kGraphWidth = 78;
	int kGraphHeight = 58;

	// プレイヤーがダメージを受けた時の点滅時間
	constexpr int kDamageBlink = 30;

	// プレイヤーの初期HP
	constexpr int kMaxHp = 3;

	constexpr int kDeadStopFrame = 30; // 死んだ後に止まる時間
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
	m_pos = Vec2(500, 500);//初期位置    
}

void Player::Update()
{
	// 無敵時間の更新
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
	// 点滅する時間
	if (m_hp != 0)
	{
		if (m_blinkFrameCount / 2 % 2)
		{
			return;
			
		}
	}
	
	// 死んだら上下反転させる
	bool isDead = false;
	if (m_hp <= 0)
	{
		isDead = true;
	}
	// プレイヤーの描画
	DrawRectGraph(m_pos.x, m_pos.y, 78*i, 0, kGraphWidth, kGraphHeight, m_handle, TRUE, m_isDirLeft,isDead);
#if _DEBUG
	DrawCircle(m_pos.x, m_pos.y, 5, 0x0000ff, 1, 1);
	//当たり判定の仮表示
	DrawBox(GetLeft(), GetTop(), GetRigth(), GetBottom(),0xff0000,FALSE);
#endif // _DEBUG

}

void Player::AnimRoop()
{
	//インターバルの更新
	AnimInterval++;

	//インターバルが10フレーム経過したら
	if (AnimInterval == 10)
	{
		//次のアニメーションに移行
		i++;
		//インターバルをリセット
		AnimInterval = 0;
	}

	//アニメーションのループリセット
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
	// パッドの入力状態を取得
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
	// パッドの入力状態を取得
	int padState = GetJoypadInputState(DX_INPUT_PAD1);
	// 現在地面にいるか
	bool isGround = (m_pos.y >= 660);
	// Aボタンが押されているか
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
	// 無敵時間(点滅する時間)を設定する
	m_blinkFrameCount = kDamageBlink;
	m_hp--;
	if (m_hp <= 0)
	{
		
		m_deadFrameCount;
	}
}

void Player::UpdateDead()
{
	// 死亡後一瞬止まる
	m_deadFrameCount++;
	if (m_deadFrameCount < kDeadStopFrame)
	{
		return;
	}
	m_pos.y += 4;

}