#pragma once
#include <GameEngine.h>

// Rectangle collider
class Collider
{
private:
	Vector2 m_topLeft;
	Vector2 m_bottomRight;
	float m_paddingTop;
	float m_paddingBottom;
	float m_paddingLeft;
	float m_paddingRight;

public:
	Collider();
	Collider(Vector2, Vector2);
	~Collider();
	void SetTopLeft(Vector2);
	void SetBottomRight(Vector2);
	void SetCollider(Vector2, Vector2);
	void SetColliderFromAnchor(Vector2, unsigned int, unsigned int);
	float GetTopEdge() const;
	float GetRightEdge() const;
	float GetBottomEdge() const;
	float GetLeftEdge() const;
	bool IsPointInside(Vector2) const;
	void SetPadding(float);
	void SetPaddingTop(float);
	void SetPaddingRight(float);
	void SetPaddingBottom(float);
	void SetPaddingLeft(float);
};