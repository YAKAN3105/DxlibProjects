#include "DxLib.h"
#include "game.h"
#include "TitleScene.h"
#include "GameScene.h"



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	// �ꕔ��DxLib�֐���DxLib_Init()�̑O�ɌĂԕK�v������
	// �t���X�N���[���ł͂Ȃ��A�E�B���h�E���[�h�ŊJ��
	ChangeWindowMode(Game::kDefaultWindowMode);
	// ��ʂ̃T�C�Y��ύX����
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);
	// �c�w���C�u��������������
	SetWindowText("ArrowShooting");
	if (DxLib_Init() == -1)		
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	// �ϐ��̍쐬
	TitleScene titleScene;
	titleScene.Init();
	GameScene gameScene;
	gameScene.Init();
	int nextScene = 0;


	// �Q�[�����[�v
	while (ProcessMessage() == 0) // Windows���s��������҂�
	{
		
		// ����̃��[�v���n�܂������Ԃ��o���Ă���
		LONGLONG time = GetNowHiPerformanceCount();

		// ��ʑS�̂��N���A����
		ClearDrawScreen();

		// �����ɃQ�[���̏���������
		if (nextScene == 0)
		{
			nextScene = titleScene.Update();
			titleScene.Draw();
		}
		else if(nextScene == 1)
		{
			nextScene == gameScene.Update();
			gameScene.Draw();
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