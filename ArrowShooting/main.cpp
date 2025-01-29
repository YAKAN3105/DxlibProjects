#include "DxLib.h"
#include "game.h"
#include "SceneTitle.h"
#include "SceneGame.h"
#include "SceneResult.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ��DxLib�֐���DxLib_Init()�̑O�ɌĂԕK�v������
	// �t���X�N���[���ł͂Ȃ��A�E�B���h�E���[�h�ŊJ��
	ChangeWindowMode(Game::kDefaultWindowMode);
	// ��ʂ̃T�C�Y��ύX����
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);

	SetWindowText("����������");
	

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// *�Ń|�C���^���w�肷��
	SceneBase* scene;

	scene = new SceneTitle; // �ŏ��ɏZ��ł���Ƃ���

	scene->Init();
	

	

	//scene = new SceneGame;

	//scene = new SceneResult;

	// �Q�[�����[�v
	while (ProcessMessage() == 0) // Windows���s��������҂�
	{
		
		// ����̃��[�v���n�܂������Ԃ��o���Ă���
		LONGLONG time = GetNowHiPerformanceCount();

		// ��ʑS�̂��N���A����
		ClearDrawScreen();

		// �����ɃQ�[���̏���������
		
		
		scene->Update(); // �����z��������߂�
		
		scene->Draw();
		

		if (scene != scene->m_next)
		{
			SceneBase* next = scene->m_next; // �����z����̏Z���̊m��

			delete scene; // ���Z��ł����Z����(delete)��
			scene = nullptr; // �����Z�ޏꏊ���Ȃ����

			scene = next; // ���̃V�[���Ɉ����z������
		}


		// ��ʂ̐؂�ւ���҂K�v������
		ScreenFlip();

		// FPS60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}