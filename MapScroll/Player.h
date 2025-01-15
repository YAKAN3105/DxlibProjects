#pragma once
#include "Vec2.h"
class Player
{
public:
	Player();
	virtual ~Player();

	// �g�p����O���t�B�b�N��ݒ肷��
	void SetHandle(int handle) { m_handle = handle; }

	void Init();
	void Update();
	void Draw();

	Vec2 GetPos() const { return m_pos; }

private:
	enum Dir
	{
		kDirDown,	// ������
		kDirLeft,	// ������
		kDirRight,	// �E����
		kDirUp,		// �����
	};

private:
	int m_handle;

	Vec2 m_pos;
	Dir m_dir;

	int m_walkFrameCount;
};

