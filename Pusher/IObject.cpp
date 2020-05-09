#include "IObject.h"

IObject::IObject() :
	m_position(Vector2(0.0f, 0.0f)),
	m_velocity(Vector2(0.0f, 0.0f))
{
}


IObject::~IObject()
{
}

void IObject::SetPosition(float x, float y)
{
	m_position = Vector2(x, y);
}

void IObject::SetPosition(Vector2 position)
{
	m_position = position;
}

void IObject::SetVelocity(float x, float y)
{
	m_velocity = Vector2(x, y);
}

void IObject::SetVelocity(Vector2 velocity)
{
	m_velocity = velocity;
}

Vector2 IObject::GetPosition() const
{
	return m_position;
}

void IObject::Update()
{
	float dt = GameTime::GetFrameTime();
	m_position = m_position + m_velocity * dt;
}

void IObject::SetCollider()
{ 
	// Default: did not have collider
}

Collider* IObject::GetCollider()
{
	return m_collider.get();
}