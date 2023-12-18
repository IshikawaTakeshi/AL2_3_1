#include <Novice.h>
#include "Object.h"
#include "Player.h"
#include "Light.h"

const char kWindowTitle[] = "LC1B_02_イシカワタケシ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Light* light1 = new Light({ 320.0f, 360.0f }, kBlendModeNormal, 255, 255, 255, 255);
	
	Light *light2 = new Light({ 640.0f, 360.0f }, kBlendModeNormal, 255, 255, 255, 255);
	Light* light3 = new Light({ 960.0f, 360.0f }, kBlendModeNormal, 255, 255, 255, 255);

	Player* flashLight = new Player(0,0, kBlendModeNormal, 255, 255, 255, 255);
	int mouseX = 0;
	int mouseY = 0;

	

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition(&mouseX, &mouseY);

		

		///
		/// ↓更新処理ここから
		///

		flashLight->SetMousePos(mouseX, mouseY);
		flashLight->Update(keys);
		light1->Update(keys);
		light2->Update(keys);
		light3->Update(keys);


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		light1->Draw()

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
