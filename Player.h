#pragma once
#include "Object.h"
#include "Novice.h"
class Player :public Object{
public:
	/*-----------コンストラクタ---------------*/
	Player(int posX , int posY, BlendMode blendMode, Color color);

	/*------マウスの座標を初期化させる関数-------------*/
	void SetMousePos(int x, int y);

	unsigned int GetColor(Color color) override;
	virtual void Update(char* keys);
	void Draw() override;

private:
	int mouseX_;
	int mouseY_;
};

