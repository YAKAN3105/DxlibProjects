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

	// �G�l�~�[�̏����擾
	float GetLeft();
	float GetRight();
	float GetTop();
	float GetBottom();

private:
	int m_handle;
	bool m_isTrigger;
	Vec2 m_pos;
};

