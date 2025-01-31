#include "Enemy.h"]
#include "DxLib.h"

Enemy::Enemy() :
	m_isTrigger(false)
{
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	// enemyÇÃèâä˙à íu
	m_pos = Vec2(1000, 700);
}

void Enemy::End()
{
}

void Enemy::Update()
{
	Move();
}

void Enemy::Draw()
{

	DrawCircle(m_pos.x, m_pos.y, 10,GetColor(255, 255, 255), TRUE,TRUE);
}

void Enemy::Move()
{
	if (m_pos.x == 50 )
	{
		m_isTrigger = false;
	}
	else if (m_pos.x == 1230)
	{
		m_isTrigger = true;
	}
	if (m_isTrigger)
	{
		m_pos.x -= 5;
	}
	else
	{
		m_pos.x += 5;
	}
}
