﻿#pragma once
//STL.
#include <memory>
//origin.
#include "MyDxlib2DGame/MyDxlib2DGame.h"
#include "GameSetting.h"

class PlatformScene : public _baseGameScene
{
public:
	/*コンストラクタデストラクタ*/ 
	//コンストラクタ
	PlatformScene()
		: _nextScene()
	{
		Init();
	}
	//デストラクタ
	~PlatformScene() = default;

	/*定型メンバ関数*/
	//初期化
	void Init() override;
	//更新
	int Update() override;
	//描画
	void Draw() override;
private:
	/*処理変数*/
	//nextScene.
	GameSetting::SceneState _nextScene;
};

