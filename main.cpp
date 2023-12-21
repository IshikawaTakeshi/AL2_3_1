#include <Novice.h>
#include "Object.h"
#include "Player.h"
#include "Light.h"

const char kWindowTitle[] = "LC1B_02_イシカワタケシ_AL2_3_1_確認課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Light* light1 = new Light({ 320.0f, 360.0f }, kBlendModeNormal, { 0xff,0xff,0xff,0xff });
	Light *light2 = new Light({ 640.0f, 360.0f }, kBlendModeNormal, { 0xff,0xff,0xff,0xff });
	Light* light3 = new Light({ 960.0f, 360.0f }, kBlendModeNormal, { 0xff,0xff,0xff,0xff });

	Player* flashLight = new Player(0,0, kBlendModeNormal, { 255, 255, 255, 255 });
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

		//背景
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000ff, kFillModeSolid);
		Novice::DrawLine(640, 0, 640, 720, 0xffffffff);
		Novice::DrawLine(0, 360, 1280, 360, 0xffffffff);

		light1->Draw();
		light2->Draw();
		light3->Draw();

		//プレイヤー描画
		flashLight->Draw();

		//デバッグ用文字列
		Novice::ScreenPrintf(10, 0, "1:Normal");
		Novice::ScreenPrintf(10, 20, "2:Add");
		Novice::ScreenPrintf(10, 40, "3:Subtruct");
		Novice::ScreenPrintf(10, 60, "4:None");

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
