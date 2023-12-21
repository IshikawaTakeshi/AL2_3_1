#include "Player.h"

/*-----------コンストラクタ---------------*/
Player::Player(int posX, int posY, BlendMode blendMode, Color color) {
	mouseX_ = posX;
	mouseY_ = posY;
	blendMode = blendMode;
	color_ = color;
	gh = Novice::LoadTexture("./Resources/particle.png");
}

/*------マウスの座標を初期化させる関数-------------*/
void Player::SetMousePos(int x, int y) {
	pos_.x = (float)x;
	pos_.y = (float)y;
}

/*----------------カラーを取得する関数-------------*/
unsigned int Player::GetColor(Color color) {
	unsigned int result;
	color.red <<= 24;
	color.green <<= 16;
	color.blue <<= 8;
	result = (color.red | color.green | color.blue | color.alpha);

	return result;
}

/*------------------更新処理-----------------*/
void Player::Update(char* keys) {
	//ブレンドモード変更
	if (keys[DIK_1]) {
		blendMode = kBlendModeNormal;
	}
	if (keys[DIK_2]) {
		blendMode = kBlendModeAdd;
	}
	if (keys[DIK_3]) {
		blendMode = kBlendModeSubtract;
	}
	if (keys[DIK_4]) {
		blendMode = kBlendModeNone;
	}

	//透明度変更
	if (keys[DIK_RIGHT]) {
		color_.alpha += 0x01;
		if (color_.alpha >= 255) {
			color_.alpha = 255;
		}
	}
	if (keys[DIK_LEFT]) {
		color_.alpha -= 0x01;
		if (color_.alpha <= 0) {
			color_.alpha = 0;
		}
	}
}

/*-----------------------描画処理----------------------*/
void Player::Draw() {
	Novice::SetBlendMode(blendMode);
	Novice::DrawSprite(
		static_cast<int>(pos_.x - 300),
		static_cast<int>(pos_.y - 300),
		gh,
		1, 1, 0.0f,
		GetColor(color_)
	);

	//デバッグ用文字列
	Novice::ScreenPrintf(10, 100, "RIGHT/LEFT:change alpha:%d", color_.alpha);
}
