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
	int m_scoreFrameCount;// �X�R�A�̏㏸
	int m_fontHandle;
	int m_numFrameCount;// �b�����ƂɃ{�[�i�X�X�R�A���オ��
};

