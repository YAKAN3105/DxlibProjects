#pragma once
#include "SceneBase.h"
#include "Map.h"

class Map;
class Player;
class Arrow;
class Rect;
class button;

class SceneGame : public SceneBase
{
public:
	SceneGame();
	virtual ~SceneGame();

	void Init() override;
	void Update() override;
	void Draw() override;


private:
	/// <summary>
	/// 
	/// </summary>
	

	/// <summary>
	/// rect1���v���C���[rect2�����Ƃ��}�b�v�`�b�v
	/// </summary>
	/// <param name="rect1">�����蔻��1</param>
	/// <param name="rect2">�����蔻��2</param>
	/// <returns>�����������ǂ���</returns>
	bool IsBoxHit(const Rect& rect1, const Rect& rect2);
	 
	// ������
	Player* m_pPlayer;
	Arrow* m_pArrow;
	Map* m_map;
	button* m_button;
};