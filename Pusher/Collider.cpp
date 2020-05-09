#include "Collider.h"



Collider::Collider() :
	m_topLeft(Vector2(0.0f, 0.0f)),
	m_bottomRight(Vector2(0.0f, 0.0f)),
	m_paddingTop(0.0f),
	m_paddingRight(0.0f),
	m_paddingBottom(0.0f),
	m_paddingLeft(0.0f)
{
}

Collider::Collider(Vector2 topLeft, Vector2 bottomRight) :
	m_topLeft(topLeft),
	m_bottomRight(bottomRight)
{
}

Collider::~Collider()
{
}

void Collider::SetCollider(Vector2 topLeft, Vector2 bottomRight)
{
	m_topLeft = topLeft;
	m_bottomRight = bottomRight;
}

void Collider::SetTopLeft(Vector2 topLeft)
{
	m_topLeft = topLeft;
}

void Collider::SetBottomRight(Vector2 bottomRight)
{
	m_bottomRight = bottomRight;
}

float Collider::GetTopEdge() const
{
	return m_topLeft.y + m_paddingTop;
}

float Collider::GetRightEdge() const
{
	return m_bottomRight.x - m_paddingRight;
}

float Collider::GetBottomEdge() const
{
	return m_bottomRight.y - m_paddingBottom;
}

float Collider::GetLeftEdge() const
{
	return m_topLeft.x + m_paddingLeft;
}

// Anchor is top-left point
void Collider::SetColliderFromAnchor(Vector2 anchor, unsigned int width, unsigned int height)
{
	m_topLeft = anchor;
	m_bottomRight = Vector2(m_topLeft.x + width, m_topLeft.y + height);
}

bool Collider::IsPointInside(Vector2 point) const
{
	bool ret = false;
	if (point.x < GetRightEdge() && point.x >= GetLeftEdge() && point.y >= GetTopEdge() && point.y < GetBottomEdge())
	{
		ret = true;
	}
	return ret;
}

void Collider::SetPadding(float padding)
{
	m_paddingBottom = padding;
	m_paddingTop = padding;
	m_paddingLeft = padding;
	m_paddingRight = padding;
}

void Collider::SetPaddingTop(float padding)
{
	m_paddingTop = padding;
}

void Collider::SetPaddingRight(float padding)
{
	m_paddingRight = padding;
}

void Collider::SetPaddingBottom(float padding)
{
	m_paddingBottom = padding;
}

void Collider::SetPaddingLeft(float padding)
{
	m_paddingLeft = padding;
}