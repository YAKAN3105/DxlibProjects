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
	//マップチップ全てを描画
	for (auto temp : Mapdata::mapData1)
	{
		/*描く画像のハンドル*/
		int tempHandle=-1;

		/*描く画像の選択*/
		//描かない場合はループを抜ける
		if (*temp == -1) { break; }
		//n番の画像のハンドルを取得
		if (*temp == 1) { tempHandle = _blockHandle; }
		if (*temp == 2) {}
		if (*temp == 7) {}
		if (*temp == 67) {}
		if (*temp == 82) {}

		/*画像の描画*/
		DrawGraph(100,100,tempHandle,true);
	}
}
