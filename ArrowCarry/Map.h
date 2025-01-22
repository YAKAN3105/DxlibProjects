#pragma once
#include "MapData.h"
#include "DxLib.h"
#include "Rect.h"

class Map
{
public:
	Map();
	virtual ~Map();

	void Init();
	void Update();
	void Draw();

	Rect GetRect() const { return m_rect; }
private:
	int _blockHandle;
	int _ceilingHandle;
	int _wallHandle;
	int _backgroundHandle;
	int _goalHandle;

	Rect m_rect;
};


