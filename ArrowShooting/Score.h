#pragma once
#include "GlovalScore.h"

class Score
{
public:
	Score();
	~Score();
	void Init();
	void Update();
	void Draw();
	int GetScore() { return glovalScore; }
private:
	int m_score;
	int m_scoreFrameCount;// スコアの上昇
	int m_fontHandle;
	int m_numFrameCount;// 秒数ごとにボーナススコアが上がる
};

