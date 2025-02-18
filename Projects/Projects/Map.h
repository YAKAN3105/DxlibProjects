#pragma once
#include "MapData.h"
#include "DxLib.h"
#include "Rect.h"

class Player;
class Map 
{
public:
	Map();
	virtual ~Map();

	void Init();
	void Update();
	void Draw();
	void End();

	Rect GetRect() const { return m_rect; }
private:
	int _blockHandle;
	int _ceilingHandle;
	int _wallHandle;
	int _backgroundHandle;
	int _goalHandle;
	
	

	bool m_isGroundHit;
	bool m_isBlockHit;
	bool m_isGoalHit;
	bool m_isWallHit;
	Rect m_rect;

	Player* m_player;
};


