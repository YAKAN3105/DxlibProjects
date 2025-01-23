#pragma once
class button
{
public:
	button();
	~button();
	void Init();
	void Update();
	void Draw();
private:
	int m_backHandle;
	int m_musicHandle;
	int m_startHandle;
	int m_stopHandle;

	button* m_button;
};

