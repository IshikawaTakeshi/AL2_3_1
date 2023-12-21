#pragma once
#include "Object.h"
class Light : public Object{
public:

	Light(Vector2 pos, BlendMode blendMode,Color color);
	unsigned int GetColor(Color color) override;
	virtual void Update(char* keys);
	void Draw() override;

};

