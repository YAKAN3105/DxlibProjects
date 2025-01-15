#include "MapChip.h"
#include <DxLib.h>
namespace 
{
	// �}�b�v�`�b�v1�̃T�C�Y
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;
}

MapChip::MapChip()
{
}

MapChip::~MapChip()
{
}

void MapChip::Init(Vec2 pos, int handle)
{
	// ������
	m_pos = pos;
	m_rect.Init( m_pos ,kChipWidth, kChipHeight);
	m_handle1 = handle;
}

void MapChip::End()
{
}

void MapChip::Update()
{
}

void MapChip::Draw()
{
	// ���u���b�N�ƕǃu���b�N�̏��擾�Ɛ���
	if (map.data[map.kChipIndexY][map.kChipIndexX] == 67) // ���u���b�N
	{
		DrawGraph(kChipWidth, kChipHeight, m_handle1, false);
	}
	if (map.data[map.kChipIndexY][map.kChipIndexX] == 82) // �ǃu���b�N
	{
		DrawGraph(kChipWidth, kChipHeight, m_handle1, false);
	}
}
