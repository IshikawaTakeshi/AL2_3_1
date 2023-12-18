#pragma once
#include "Object.h"
#include "Novice.h"
class Player :public Object{
public:
	Player(int posX , int posY, BlendMode blendMode, int red, int green, int blue, int alpha);

	void SetMousePos(int x, int y);

	unsigned int GetColor(int red, int green, int blue, int alpha) override;
	virtual void Update(char* keys);
	void Draw(BlendMode blendMode, unsigned int color) override;

private:
	int mouseX_;
	int mouseY_;
};

