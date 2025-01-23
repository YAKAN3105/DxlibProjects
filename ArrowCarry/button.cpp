#include "button.h"
#include <DxLib.h>

button::button()
{
}

button::~button()
{
}

void button::Init()
{
	m_backHandle = LoadGraph("data/image1/back.png");
	m_musicHandle = LoadGraph("data/image1/music.png");
	m_startHandle = LoadGraph("data/image1/start.png");
	m_stopHandle = LoadGraph("data/image1/stop.png");
}

void button::Update()
{
}

void button::Draw()
{
	DrawGraph(100, 0, m_backHandle, true);
	DrawGraph(100, 100, m_musicHandle, true);
	DrawGraph(0, 0, m_startHandle, true);
	DrawGraph(0, 0, m_stopHandle, true);
}
