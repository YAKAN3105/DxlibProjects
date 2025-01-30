#pragma once
#include "Vec2.h"
class Player
{
public:
	Player();
	~Player();
	void Init();
	void Update();
	void Draw();
	void AnimRoop();
	void Move();
	void Gravity();
private:
	int m_handle;
	int	m_animHandle;
	int m_runHandle;
	int m_idleHandle;
	int m_jumpHandle;
	int m_speed = 0;
	int m_jumpSpeed = 0;
	int i = 0;
	int maxAnimNum;
	int	AnimInterval = 0;
	bool m_isDirLeft;
	bool m_isJump;
	Vec2 m_pos;
	Vec2 m_velocity;
};

