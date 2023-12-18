#include "Player.h"

Player::Player(int posX , int posY, BlendMode blendMode, int red, int green, int blue, int alpha){
	mouseX_ = posX;
	mouseY_ = posY;
	pos_.x = mouseX_;
	pos_.y = mouseY_;

	blendMode_ = blendMode;
	red_ = red;
	green_ = green;
	blue_ = blue;
	alpha_ = alpha;
}

void Player::SetMousePos(int x, int y) {
	mouseX_ = x;
	mouseY_ = y;
}

unsigned int Player::GetColor(int red, int green, int blue, int alpha){
	unsigned int result;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	result = (red | green | blue | alpha);

	return result;
}

void Player::Update(char* keys) {
	if (keys[DIK_1]) {
		blendMode_ = kBlendModeNormal;
	}
	if (keys[DIK_2]) {
		blendMode_ = kBlendModeAdd;
	}
	if (keys[DIK_3]) {
		blendMode_ = kBlendModeSubtract;
	}
	if (keys[DIK_4]) {
		blendMode_ = kBlendModeNone;
	}
}

void Player::Draw(BlendMode blendMode, unsigned int color){
	Novice::SetBlendMode(blendMode);
	Novice::DrawSprite(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		gh_,
		1, 1, 0.0f,
		color
	);
}
