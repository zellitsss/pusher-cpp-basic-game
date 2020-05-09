#include "MinionObject.h"
#include "ResourceManager.h"
#include "settings.h"

MinionObject::MinionObject()
{
	m_collider = std::make_unique<Collider>();
}

MinionObject::MinionObject(MinionType type, MinionWeight weight) :
	m_type(type),
	m_weight(weight)
{

}

MinionObject::~MinionObject()
{
	m_animation = nullptr;
}

void MinionObject::SetAnimation(Animation* animation)
{
	m_animation = animation;
}

// Set animation based on type and weight
void MinionObject::SetAnimation()
{
	std::string type;
	std::string size;
	switch (m_type)
	{
	case Bot:
		type = "bot";
		break;
	case Player:
		type = "player";
		break;
	default:
		break;
	}
	switch (m_weight)
	{
	case Small:
		size = "small";
		m_collider->SetPaddingTop(OBJECT_PADDING_SMALL);
		m_collider->SetPaddingBottom(OBJECT_PADDING_SMALL);
		break;
	case Medium:
		size = "medium";
		m_collider->SetPaddingTop(OBJECT_PADDING_MEDIUM);
		m_collider->SetPaddingBottom(OBJECT_PADDING_MEDIUM);
		break;
	case Big:
		size = "big";
		m_collider->SetPaddingTop(OBJECT_PADDING_BIG);
		m_collider->SetPaddingBottom(OBJECT_PADDING_BIG);
		break;
	default:
		break;
	}
	std::string str = type + "_" + size + "_anim";
	SetAnimation(ResourceManager::GetInstance()->GetAnimation(str));
}

void MinionObject::Update()
{
	float dt = GameTime::GetFrameTime();
	m_position = m_position + m_velocity * dt;
	m_collider->SetColliderFromAnchor(m_position, m_animation->GetWidth(), m_animation->GetHeight());
}

void MinionObject::Render(Graphics* graphics)
{
	graphics->DrawAnimation(m_animation, m_position.x, m_position.y);
}

unsigned int MinionObject::GetWidth()
{
	return m_animation->GetWidth();
}

unsigned int MinionObject::GetHeight()
{
	return m_animation->GetHeight();
}

void MinionObject::SetCollider()
{
	m_collider->SetColliderFromAnchor(m_position, m_animation->GetWidth(), m_animation->GetHeight());
}

void MinionObject::SetType(MinionType type)
{
	m_type = type;
}

MinionType MinionObject::GetType()
{
	return m_type;
}

void MinionObject::SetWeight(MinionWeight weight)
{
	m_weight = weight;
}

int MinionObject::GetWeight()
{
	return (int)m_weight;
}