#pragma once
#include "Object.h"
class Light : public Object{
public:

	Light(Vector2 pos, BlendMode blendMode, int red, int green, int blue, int alpha);
	unsigned int GetColor(int red, int green, int blue, int alpha) override;
	virtual void Update(char* keys);
	void Draw(BlendMode blendMode, unsigned int color) override;

};

