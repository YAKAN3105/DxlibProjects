#include "Enemy.h"
#include "DxLib.h"
namespace 
{
	// グラフィックのサイズ
	int kGraphWidth = 128;
	int kGraphHeight = 128;
	int kHitBoxW = 70;
	int kHitBoxH = 50;

	// enemyの初期速度
	int speed = 5;
}


Enemy::Enemy() :
	m_isTrigger(false),
	m_handle(0),
	m_AccelerationCount(0)
{
	m_handle = 0;
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// enemyの初期位置
	m_pos = Vec2(1000, 670);
	m_handle = LoadGraph("data/Arrow/Right.png");
}

void Enemy::End()
{
}

void Enemy::Update()
{
	++m_AccelerationCount;
	if (m_AccelerationCount % 300 == 0)
	{
		speed = 10;
	}
	if(m_AccelerationCount % 600 == 0)
	{
		speed = 15;
	}
	if (m_AccelerationCount % 900 == 0)
	{
		speed = 20;
	}
	if (m_AccelerationCount % 1200 == 0)
	{
		speed = 25;
	}
	if (m_AccelerationCount % 1500 == 0)
	{
		speed = 30;
	}
	if (m_AccelerationCount % 1800 == 0)
	{
		speed = 35;
	}
	if (m_AccelerationCount % 2100 == 0)
	{
		speed = 40;
	}
	Move();
}

void Enemy::Draw()
{
	DrawRotaGraph(m_pos.x, m_pos.y, 1.0f, 0.0f, m_handle, TRUE, m_isTrigger);
#ifdef _DEBUG
	DrawCircle(m_pos.x, m_pos.y, 5, 0xff0000, 1, 1);
	DrawBox(m_pos.x - kHitBoxW / 2, m_pos.y + kHitBoxH / 2, m_pos.x + kHitBoxW / 2, m_pos.y - kHitBoxH / 2, 0xff00ff, FALSE);
#endif // _DEBUG
}

void Enemy::Move()
{
	if (m_pos.x <= 50 )
	{
		m_isTrigger = false;
	}
	else if (m_pos.x >= 1230)
	{
		m_isTrigger = true;
	}
	if (m_isTrigger)
	{
		m_pos.x -= speed;
	}
	else
	{
		m_pos.x += speed;
	}
}

float Enemy::GetLeft()
{
	return (m_pos.x - kHitBoxW / 2);
}

float Enemy::GetRight()
{
	return (m_pos.x + kHitBoxW / 2);
}

float Enemy::GetTop()
{
	return (m_pos.y - kHitBoxH / 2);
}

float Enemy::GetBottom()
{
	return (m_pos.y + kHitBoxH / 2);
}
