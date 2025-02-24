 #include "DxLib.h"
#include "game.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	// 一部のDxLib関数はDxLib_Init()の前に呼ぶ必要がある
	// フルスクリーンではなく、ウィンドウモードで開く
	ChangeWindowMode(Game::kDefaultWindowMode);
	// 画面のサイズを変更する
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorBitNum);
	// ＤＸライブラリ初期化処理
	SetWindowText("ArrowShooting");
	if (DxLib_Init() == -1)		
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// 変数の作成
	TitleScene titleScene;
	titleScene.Init();
	GameScene gameScene;
	gameScene.Init();
	ResultScene resultScene;
	resultScene.Init();
	int nextScene = 0;

	//Score* score = new Score;


	// ゲームループ
	while (ProcessMessage() == 0) // Windowsが行う処理を待つ
	{
		
		// 今回のループが始まった時間を覚えておく
		LONGLONG time = GetNowHiPerformanceCount();

		// 画面全体をクリアする
		ClearDrawScreen();

		// ここにゲームの処理を書く
		
		if (nextScene == 0)
		{
			nextScene = titleScene.Update();
			titleScene.Draw();
		}
		if(nextScene == 1)
		{
			nextScene = gameScene.Update();
			gameScene.Draw();
		}
		if (nextScene == 2)
		{
			nextScene = resultScene.Update();
			resultScene.Draw();
		}

		// 画面の切り替わりを待つ必要がある
		ScreenFlip();

		// FPS60に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}

		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}