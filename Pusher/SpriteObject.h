#pragma once
#include <memory>
#include "IObject.h"

class SpriteObject : public IObject
{
private:
	Image* m_image;
public:
	SpriteObject();
	~SpriteObject();
	void Render(Graphics*) override;
	void SetImage(Image*);
	unsigned int GetWidth() override;
	unsigned int GetHeight() override;
};