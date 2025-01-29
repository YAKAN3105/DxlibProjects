#include "Map.h"
#include "DxLib.h"
#include <cassert>
#include"Player.h"


Map::Map(Player* pPlayer)
{
	m_player = pPlayer;
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
	m_isGroundHit = false;
	m_isBlockHit = false;
	m_isGoalHit = false;
	m_isWallHit = false;

	for (int y = 0; y < Mapdata::kChipIndexY; y++)//s
	{
		for (int x = 0; x < Mapdata::kChipIndexX; x++)//—ñ
		{
			int chipNo = Mapdata::mapData1[y][x];

			//int chipLeft = x * 32;
			int chipLeft = m_rect.GetLeft();
			//int chipTop = y * 32;
			int chipTop = m_rect.GetTop();
			//int chipRight = chipLeft + 32;
			int chipRight = m_rect.GetRight();
			//int chipBottom = chipTop + 32;
			int chipBottom = m_rect.GetBottom();
			// â‘Î“–‚½‚ç‚È‚¢ê‡@true‚É‚È‚é(ˆê‚Â‚Å‚àtrue‚È‚ç“–‚Á‚Ä‚¢‚È‚¢)
			bool isPlayerLeft =(m_player->GetRight() < chipLeft);
			bool isPlayerTop = (m_player->GetBottom() < chipTop);
			bool isPlayerRight = (chipRight < m_player->GetLeft());
			bool isPlayerBottom =  (chipBottom < m_player->GetTop());

			//’n–Ê‚É“–‚½‚Á‚½Žž‚Ìˆ—
			if (chipNo == 1)
			{
				if (!isPlayerLeft && !isPlayerTop && !isPlayerRight && !isPlayerBottom)
				{
					m_player->CheckPosMapHit(this);
					m_isGroundHit = true;
				}
			}
			if (chipNo == 2)
			{
				if (!(isPlayerLeft || isPlayerTop || isPlayerRight || isPlayerBottom))
				{
					m_isBlockHit = true;
				}
			}
			if (chipNo == 7)
			{
				if (!(isPlayerLeft || isPlayerTop || isPlayerRight || isPlayerBottom))
				{
					m_isGoalHit = true;
				}
			}
			if (chipNo == 67)
			{
				if (!(isPlayerLeft || isPlayerTop || isPlayerRight || isPlayerBottom))
				{
					m_isWallHit = true;
				}
			}
		}
	}
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

