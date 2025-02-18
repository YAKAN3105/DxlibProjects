#include "Map.h"
#include "DxLib.h"
#include <cassert>


Map::Map()
{
}

Map::~Map()
{
	DeleteGraph(_blockHandle);
	DeleteGraph(_ceilingHandle);
	DeleteGraph(_wallHandle);
	DeleteGraph(_backgroundHandle);
	DeleteGraph(_goalHandle);
}

void Map::Init()
{
	_blockHandle = LoadGraph("block.jpg");
	_ceilingHandle = LoadGraph("ceiling.jpg");
	_wallHandle = LoadGraph("wall.jpg");
	_backgroundHandle = LoadGraph("background.jpg");
	_goalHandle = LoadGraph("Goal.jpg");
	
}

void Map::Draw()
{
	for (int y = 0; y < Mapdata::kChipIndexX; y++)//s
	{
		for (int x = 0; x < Mapdata::kChipIndexY; x++)//—ñ
		{
			/*•`‚­‰æ‘œ‚Ìƒnƒ“ƒhƒ‹*/
			int tempHandle = -1;

			/*‰æ‘œ‚Ì•`‰æ*/
			if (Mapdata::mapData1[x][y] == -1) { continue; }
			if (Mapdata::mapData1[x][y] == 1) { tempHandle = _ceilingHandle; }
			if (Mapdata::mapData1[x][y] == 2) { tempHandle = _blockHandle; }
			if (Mapdata::mapData1[x][y] == 7) { tempHandle = _goalHandle; }
			if (Mapdata::mapData1[x][y] == 67) { tempHandle = _wallHandle; }
			if (Mapdata::mapData1[x][y] == 82) { tempHandle = _backgroundHandle; }

			/*‰æ‘œ‚Ì•`‰æ*/
			assert(tempHandle != -1);
			DrawGraph(y * 32, x * 32, tempHandle, true);
			
			
#if _DEBUG
			DrawFormatString(y * 32, x * 32, 0xffffff, "%d", Mapdata::mapData1[x][y]);
#endif // _DEBUG

			
		}
	}
}

void Map::End()
{
	DeleteGraph(_blockHandle);
	DeleteGraph(_ceilingHandle);
	DeleteGraph(_wallHandle);
	DeleteGraph(_backgroundHandle);
	DeleteGraph(_goalHandle);
}

