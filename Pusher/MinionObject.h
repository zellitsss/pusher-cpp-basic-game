#pragma once
#include "IObject.h"
#include <memory>
#include <GameEngine.h>
#include "settings.h"

class MinionObject : public IObject
{
private:
	Animation* m_animation;
	MinionType m_type;
	MinionWeight m_weight;
public:
	MinionObject();
	MinionObject(MinionType, MinionWeight);
	~MinionObject();
	void SetAnimation(Animation*);
	void SetAnimation();
	void Render(Graphics*) override;
	unsigned int GetWidth() override;
	unsigned int GetHeight() override;
	void SetCollider() override;
	void Update() override;
	void SetType(MinionType);
	void SetWeight(MinionWeight);
	MinionType GetType();
	int GetWeight();
};