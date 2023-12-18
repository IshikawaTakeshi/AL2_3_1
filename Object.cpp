#include "Object.h"

unsigned int Object::GetColor(int red, int green, int blue, int alpha) {
	unsigned int result;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	result = (red | green | blue | alpha);

	return result;
}

void Object::Update(char* keys) {
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

void Object::Draw(BlendMode blendMode, unsigned int color) {
	Novice::SetBlendMode(blendMode);
	Novice::DrawSprite(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		gh_,
		1, 1, 0.0f,
		color
	);
}

