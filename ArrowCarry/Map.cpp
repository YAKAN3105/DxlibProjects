#include "Map.h"
#include <cassert>

Map::Map()
{
}

Map::~Map()
{
}

void Map::Init()
{
	_blockHandle = LoadGraph("block.jpg");
	_ceilingHandle = LoadGraph("ceiling.jpg");
	_wallHandle = LoadGraph("wall.jpg");
	_backgroundHandle = LoadGraph("background.jpg");
	_goalHandle = LoadGraph("Goal.jpg");
}

void Map::Update()
{

}

void Map::Draw()
{
	for (int i = 0; i < Mapdata::kChipIndexX; i++)//s
	{
		for (int s = 0; s < Mapdata::kChipIndexY; s++)//—ñ
		{
			/*•`‚­‰æ‘œ‚Ìƒnƒ“ƒhƒ‹*/
			int tempHandle = -1;

			/*‰æ‘œ‚Ì•`‰æ*/
			if (Mapdata::mapData1[s][i] == -1) { continue; }
			if (Mapdata::mapData1[s][i] == 1) { tempHandle = _ceilingHandle; }
			if (Mapdata::mapData1[s][i] == 2) { tempHandle = _blockHandle; }
			if (Mapdata::mapData1[s][i] == 7) { tempHandle = _goalHandle; }
			if (Mapdata::mapData1[s][i] == 67) { tempHandle = _wallHandle; }
			if (Mapdata::mapData1[s][i] == 82) { tempHandle = _backgroundHandle; }

			/*‰æ‘œ‚Ì•`‰æ*/
			assert(tempHandle != -1);
			DrawGraph(i * 32, s * 32, tempHandle, true);
		}
	}
}
