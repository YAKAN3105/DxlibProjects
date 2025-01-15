#pragma once
#include "Rect.h"
#include "Vec2.h"

class Map;
class MapChip
{
public:
	MapChip();
	~MapChip();

	void Init(Vec2 pos,int handle);
	void End();
	void Update();
	void Draw();

private:

	

	Rect m_rect;// ��`���
	Vec2 m_pos;	// ���S���W

	int m_chipKind;

	int m_handle1;
};

