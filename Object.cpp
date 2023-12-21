#include "Object.h"

unsigned int Object::GetColor(Color color) {
	unsigned int result;
	color.red <<= 24;
	color.green <<= 16;
	color.blue <<= 8;
	result = (color.red | color.green | color.blue | color.alpha);

	return result;
}

void Object::Update(char* keys) {
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
}

void Object::Draw() {
	Novice::SetBlendMode(blendMode);
	Novice::DrawSprite(
		static_cast<int>(pos_.x),
		static_cast<int>(pos_.y),
		gh,
		1, 1, 0.0f,
		GetColor(color_)
	);
}

