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
	//�}�b�v�`�b�v�S�Ă�`��
	for (auto temp : Mapdata::mapData1)
	{
		/*�`���摜�̃n���h��*/
		int tempHandle=-1;

		/*�`���摜�̑I��*/
		//�`���Ȃ��ꍇ�̓��[�v�𔲂���
		if (*temp == -1) { break; }
		//n�Ԃ̉摜�̃n���h�����擾
		if (*temp == 1) { tempHandle = _blockHandle; }
		if (*temp == 2) {}
		if (*temp == 7) {}
		if (*temp == 67) {}
		if (*temp == 82) {}

		/*�摜�̕`��*/
		DrawGraph(100,100,tempHandle,true);
	}
}
