#pragma once
#include <memory>
#include <GameEngine.h>
#include "Collider.h"

class IObject
{
protected:
	Vector2 m_position;
	Vector2 m_velocity;
	std::unique_ptr<Collider> m_collider;
public:
	IObject();
	virtual ~IObject();
	virtual void SetPosition(float, float);
	virtual void SetPosition(Vector2);
	virtual void SetVelocity(float, float);
	virtual void SetVelocity(Vector2);
	virtual Vector2 GetPosition() const;
	virtual void Update();
	virtual void Render(Graphics*) = 0;
	virtual unsigned int GetWidth() = 0;
	virtual unsigned int GetHeight() = 0;
	virtual void SetCollider();
	virtual Collider* GetCollider();
};