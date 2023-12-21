#pragma once
#include "Vector2.h"
#include "Novice.h"
class Object{
public:

	struct Color {
		int red;
		int green;
		int blue;
		int alpha;
	};
	
	int gh;
	BlendMode blendMode = kBlendModeNormal;

	virtual unsigned int GetColor(Color color);
	virtual void Update(char *keys);
	virtual void Draw();

protected:
	Vector2 pos_;
	Color color_;
};

