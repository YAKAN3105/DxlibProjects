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
	void Jump();
	float GetLeft();
	float GetRigth();
	float GetTop();
	float GetBottom();
	void OnDamage();
	void UpdateDead();
	float GetPosY()const { return m_pos.y; }
	void PlayerSetUp();
private:
	int m_handle;
	int	m_animHandle;
	int m_runHandle;
	int m_idleHandle;
	int m_jumpHandle;
	int m_speed = 4;
	int m_jumpSpeed = 200;
	int i = 0;
	int maxAnimNum;
	int	AnimInterval = 0;
	bool m_isDirLeft;
	bool m_isJump;
	Vec2 m_pos;
	Vec2 m_velocity;
	int m_blinkFrameCount;		// 点滅
	int m_hp;					// プレイヤーのHP
	int m_deadFrameCount;		// 死亡演出
};

