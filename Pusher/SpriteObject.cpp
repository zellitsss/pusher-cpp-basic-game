#include "SpriteObject.h"

SpriteObject::SpriteObject()
{
}


SpriteObject::~SpriteObject()
{
}

void SpriteObject::Render(Graphics* graphics)
{
	graphics->DrawImage(m_image, m_position.x, m_position.y);
}

void SpriteObject::SetImage(Image* image)
{
	m_image = image;
}

unsigned int SpriteObject::GetWidth()
{
	return m_image->GetWidth();
}

unsigned int SpriteObject::GetHeight()
{
	return m_image->GetHeight();
}