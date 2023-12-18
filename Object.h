#pragma once
#include "Vector2.h"
#include "Novice.h"
class Object{
public:

	virtual unsigned int GetColor(int red, int green, int blue, int alpha);
	virtual void Update(char *keys);
	virtual void Draw(BlendMode blendMode, unsigned int color);

protected:
	Vector2 pos_;
	BlendMode blendMode_;

	int red_;
	int green_;
	int blue_;
	int alpha_;

	int gh_;
};

