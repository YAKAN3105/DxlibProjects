#pragma once
#include "Game.h"
class TitleScene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	int Update();
	void Draw();
private:
	int m_handle1;
	int m_handle2;
};

