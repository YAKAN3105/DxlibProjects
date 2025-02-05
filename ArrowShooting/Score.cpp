#include "Score.h"
#include <DxLib.h>

namespace
{
}
Score::Score():
	m_scoreFrameCount(60),
	m_numFrameCount(0)
{
}

Score::~Score()
{
}

void Score::Init()
{
	m_fontHandle = CreateFontToHandle("Bernard MT Condensed", 40, 2, DX_FONTTYPE_ANTIALIASING_EDGE_16X16);
	glovalScore = 0;
}

void Score::Update()
{
	--m_scoreFrameCount;
	++m_numFrameCount;
	if (m_scoreFrameCount == 0)
	{
		glovalScore += 1;
		m_scoreFrameCount = 60;
	}
	if (m_numFrameCount % 300 == 0)
	{
		glovalScore += 10000;
	}
	

}

void Score::Draw()
{
	DrawFormatStringToHandle(30, 30, 0xcd5937, m_fontHandle, "SCORE:%d", glovalScore);
}

