#pragma once
class Score
{
public:
	Score();
	~Score();
	void Init();
	void Update();
	void Draw();
	int GetScore()const { return m_score; }
private:
	int m_score;
	int m_scoreFrameCount;// �X�R�A�̏㏸
	int m_fontHandle;
	int m_numFrameCount;// �b�����ƂɃ{�[�i�X�X�R�A���オ��
};

