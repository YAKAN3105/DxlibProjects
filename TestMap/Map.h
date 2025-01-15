#pragma once
#include "MapData.h"
#include "DxLib.h"

class Map
{
public:
	Map();
	virtual ~Map();

	void Init();
	void Update();
	void Draw();
private:
	int _blockHandle;
};

