#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

void Map::Init()
{
	_blockHandle = LoadGraph("block.jpg");
}

void Map::Update()
{

}

void Map::Draw()
{
	for (int i = 0; i < Mapdata::kChipIndexX; i++)//�s
	{
		for (int s = 0; s < Mapdata::kChipIndexY; s++)//��
		{
			/*�`���摜�̃n���h��*/
			int tempHandle = -1;

			/*�摜�̕`��*/
			if (Mapdata::mapData1[s][i] == -1) { continue; }
			if (Mapdata::mapData1[s][i] == 1) {  }
			if (Mapdata::mapData1[s][i] == 2) { tempHandle = LoadGraph("block.jpg"); }
			if (Mapdata::mapData1[s][i] == 7) {}
			if (Mapdata::mapData1[s][i] == 67) {}
			if (Mapdata::mapData1[s][i] == 82) {}

			/*�摜�̕`��*/
			DrawGraph(i * 32, s * 32, tempHandle, true);
		}
	}
}
