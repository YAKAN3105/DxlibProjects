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
	int	m_AnimHandle;
	int m_RunHandle;
	int m_IdleHandle;
	int i = 0;
	int maxAnimNum;
	int	AnimInterval = 0;
	Vec2 m_pos;
};

