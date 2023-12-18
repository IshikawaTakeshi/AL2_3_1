#include "light.h"

Light::Light(Vector2 pos, BlendMode blendMode, int red, int green, int blue, int alpha){
	pos_ = pos;
	blendMode_ = blendMode;
	red_ = red;
	green_ = green;
	blue_ = blue;
	alpha_ = alpha;
}

unsigned int Light::GetColor(int red, int green, int blue, int alpha) {
	unsigned int result;
	red <<= 24;
	green <<= 16;
	blue <<= 8;
	result = (red | green | blue | alpha);

	return result;
}

void Light::Update(char* keys) {
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

void Light::Draw(BlendMode blendMode, unsigned int color) {
	Novice::SetBlendMode(blendMode);
	Novice::DrawSprite(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		gh_,
		1, 1, 0.0f,
		color
	);
}
