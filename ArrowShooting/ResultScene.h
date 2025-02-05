#pragma once
#include "Score.h"


class ResultScene
{
public:
	ResultScene();
	~ResultScene();
	void Init();
	int Update();
	void Draw();
private:
	int m_handle;
	int m_fontHandle;
};