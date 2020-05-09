#pragma once
#include <deque>
#include <memory>
#include <GameEngine.h>
#include "MinionObject.h"
#include "Collider.h"

class Lane
{
private:
	std::deque<std::shared_ptr<MinionObject>> m_bottomObjects;
	std::deque<std::shared_ptr<MinionObject>> m_topObjects;
	std::deque<std::shared_ptr<MinionObject>> m_combinedObjects;
	Vector2 m_topSpawnPosition;
	Vector2 m_bottomSpawnPosition;
	std::shared_ptr<Collider> m_collider;
	bool m_isBotBlocked;
	bool m_isPlayerBlocked;
public:
	Lane();
	~Lane();
	void SetArea(Vector2, Vector2);
	void SetTopSpawn(Vector2);
	void SetTopSpawn(float, float);
	void SetBottomSpawn(Vector2);
	void SetBottomSpawn(float, float);
	void Update();
	void Render(Graphics*);
	bool AddToTop(std::shared_ptr<MinionObject>&&);
	bool AddToBottom(std::shared_ptr<MinionObject>&&);
	bool IsClickedIn(Vector2);
};
