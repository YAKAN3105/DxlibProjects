#pragma once
#include "Vec2.h"
class Enemy
{
public:
	Enemy();
	~Enemy();
	void Init();
	void End();
	void Update();
	void Draw();
	void Move();
	void EnemySetUp();

	// エネミーの情報を取得
	float GetLeft();
	float GetRight();
	float GetTop();
	float GetBottom();

private:
	int m_handle;
	bool m_isTrigger;
	int m_AccelerationCount;
	int m_speed;
	Vec2 m_pos;
};

