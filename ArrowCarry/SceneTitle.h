#pragma once
#include "SceneBase.h"
class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	~SceneTitle();

	void Init()override;
	void Update()override;
	void Draw()override;
private:

	// �O���t�B�b�N�̃n���h��
	int m_handle;
};

