#pragma once
#include<math.h>
#include "Vec2.h"
#include"map.h"
#include "Rect.h"

class Map;

class Player
{
public:
	Player();
	~Player();

	//�v���C���[�̏����擾����
	float GetLeft() const;
	float GetTop() const;
	float GetRight() const;
	float GetBottom() const;

	void Init();
	void End();
	void Update();
	void AnimationUpdate();
	void Draw();

	Rect GetRect() const { return m_playerRect; }

	void IsHitArrow();
	
	void OnArrow(Vec2 vec);

	
	// ���x��0�ɂ���
	void InitVelocity(); 
	void CheckPosMapHit(Map* map);



private:

	Vec2  m_pos;
	Vec2 m_backPos;
	Vec2 m_velocity;
	
	float m_speed;

	float m_jumpPower;

	bool m_isJumpNow;	//�W�����v�����u�Ԃ��ǂ���
	bool m_isFalling; //���������ǂ���
	bool m_isMapHit;//�}�b�v�ɂ������Ă��邩�ǂ���

	bool m_lastJump;

	// �A�j���[�V�����֘A
	int m_animFrame; // �t���[�����𐔂���
	// ���ݍĐ����̃A�j���[�V����
	// true:�����Ă��� false:�ҋ@
	bool m_isRun;	// �ϐ�

	// player�����������Ă��邩�ǂ���
	// true:�������@false:�E����
	bool m_isDirLeft;	// �ϐ�
 
	// �O���t�B�b�N�n���h��
	int m_handleIdle;
	int m_handleRun;

	int m_playerNowPos;

	Rect m_playerRect;

	Map* m_map;

};

