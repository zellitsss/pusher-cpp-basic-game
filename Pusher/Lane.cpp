#include "Lane.h"
#include <algorithm>
#include "Score.h"

Lane::Lane()
{
	m_collider = std::make_unique<Collider>();
	m_isBotBlocked = false;
	m_isPlayerBlocked = false;
}

Lane::~Lane()
{

}

void Lane::SetTopSpawn(Vector2 position)
{
	m_topSpawnPosition = position;
}

void Lane::SetTopSpawn(float x, float y)
{
	m_topSpawnPosition = Vector2(x, y);
}

void Lane::SetBottomSpawn(Vector2 position)
{
	m_bottomSpawnPosition = position;
}

void Lane::SetBottomSpawn(float x, float y)
{
	m_bottomSpawnPosition = Vector2(x, y);
}

void Lane::SetArea(Vector2 topLeft, Vector2 bottomRight)
{
	m_collider->SetCollider(topLeft, bottomRight);
	SetTopSpawn((topLeft.x + bottomRight.x) / 2, topLeft.y);
	SetBottomSpawn((topLeft.x + bottomRight.x) / 2, bottomRight.y);
}

void Lane::Update()
{
	std::for_each(m_topObjects.begin(), m_topObjects.end(), [](std::shared_ptr<MinionObject>& minion)
	{
		minion->Update();
	});
	std::for_each(m_bottomObjects.begin(), m_bottomObjects.end(), [](std::shared_ptr<MinionObject>& minion)
	{
		minion->Update();
	});

	// Collision detecting
	if (!m_bottomObjects.empty() && !m_topObjects.empty())
	{
		if (m_bottomObjects.front()->GetCollider()->GetTopEdge() <= m_topObjects.front()->GetCollider()->GetBottomEdge())
		{
			m_bottomObjects.front()->SetVelocity(0.0f, 0.0f);
			m_topObjects.front()->SetVelocity(0.0f, 0.0f);
			m_combinedObjects.push_back(std::move(m_bottomObjects.front()));
			m_bottomObjects.pop_front();
			m_combinedObjects.push_front(std::move(m_topObjects.front()));
			m_topObjects.pop_front();
		}
	}

	if (!m_bottomObjects.empty() && !m_combinedObjects.empty())
	{
		if (m_bottomObjects.front()->GetCollider()->GetTopEdge() <= m_combinedObjects.back()->GetCollider()->GetBottomEdge())
		{
			m_bottomObjects.front()->SetVelocity(0.0f, 0.0f);
			m_combinedObjects.push_back(std::move(m_bottomObjects.front()));
			m_bottomObjects.pop_front();
		}
	}
	
	if (!m_topObjects.empty() && !m_combinedObjects.empty())
	{
		if (m_topObjects.front()->GetCollider()->GetBottomEdge() >= m_combinedObjects.front()->GetCollider()->GetTopEdge())
		{
			m_topObjects.front()->SetVelocity(0.0f, 0.0f);
			m_combinedObjects.push_front(std::move(m_topObjects.front()));
			m_topObjects.pop_front();
		}
	}

	if (!m_bottomObjects.empty())
	{
		float topEdge = m_bottomObjects.front()->GetCollider()->GetTopEdge();
		m_isBotBlocked = (topEdge <= m_topSpawnPosition.y + SPAWN_AREA_HEIGHT);
		
		if (topEdge <= m_topSpawnPosition.y)
		{
			Score::GetInstance()->SetScore(MinionType::Player, static_cast<MinionWeight>(m_bottomObjects.front()->GetWeight()));
			m_bottomObjects.pop_front();
		}
	}

	if (!m_topObjects.empty())
	{
		float bottomEdge = m_topObjects.front()->GetCollider()->GetBottomEdge();
		m_isPlayerBlocked = (bottomEdge >= m_bottomSpawnPosition.y - SPAWN_AREA_HEIGHT);
		if (bottomEdge >= m_bottomSpawnPosition.y)
		{
			Score::GetInstance()->SetScore(MinionType::Bot, static_cast<MinionWeight>(m_topObjects.front()->GetWeight()));
			m_topObjects.pop_front();
		}
	}

	if (!m_combinedObjects.empty())
	{
		float topEdge = m_combinedObjects.front()->GetCollider()->GetTopEdge();
		float bottomEdge = m_combinedObjects.back()->GetCollider()->GetBottomEdge();
		m_isBotBlocked = topEdge <= m_topSpawnPosition.y + SPAWN_AREA_HEIGHT;
		m_isPlayerBlocked = bottomEdge >= m_bottomSpawnPosition.y - SPAWN_AREA_HEIGHT;
		if (topEdge <= m_topSpawnPosition.y)
		{
			if (m_combinedObjects.front()->GetType() == MinionType::Player)
			{
				Score::GetInstance()->SetScore(MinionType::Player, static_cast<MinionWeight>(m_combinedObjects.front()->GetWeight()));
			}
			m_combinedObjects.pop_front();
		}
		if (bottomEdge >= m_bottomSpawnPosition.y)
		{
			if (m_combinedObjects.back()->GetType() == MinionType::Bot)
			{
				Score::GetInstance()->SetScore(MinionType::Bot, static_cast<MinionWeight>(m_combinedObjects.front()->GetWeight()));
			}
			m_combinedObjects.pop_back();
		}
	}

	if (m_combinedObjects.empty() && m_bottomObjects.empty() && m_topObjects.empty())
	{
		m_isBotBlocked = false;
		m_isPlayerBlocked = false;
	}

	// TODO: re-calculate combined-objects velocity
	int totalWeight = 0;
	std::for_each(m_combinedObjects.begin(), m_combinedObjects.end(), [&totalWeight](std::shared_ptr<MinionObject>& minion)
	{
		switch (minion->GetType())
		{
		case MinionType::Bot:
		{
			totalWeight += minion->GetWeight();
			break;
		}
		case MinionType::Player:
		{
			totalWeight -= minion->GetWeight();
			break;
		}
		default:
			break;
		}
	});
	int direction = 0;
	if (totalWeight > 0)
	{
		direction = 1;
	}
	else if (totalWeight < 0)
	{
		direction = -1;
	}
	std::for_each(m_combinedObjects.begin(), m_combinedObjects.end(), [direction](std::shared_ptr<MinionObject>& minion)
	{
		minion->SetVelocity(0.0f, SPEED * direction);
		minion->Update();
	});

}

void Lane::Render(Graphics* graphics)
{
	std::for_each(m_topObjects.begin(), m_topObjects.end(), [graphics](std::shared_ptr<MinionObject>& minion)
	{
		minion->Render(graphics);
	});
	std::for_each(m_bottomObjects.begin(), m_bottomObjects.end(), [graphics](std::shared_ptr<MinionObject>& minion)
	{
		minion->Render(graphics);
	});
	std::for_each(m_combinedObjects.begin(), m_combinedObjects.end(), [graphics](std::shared_ptr<MinionObject>& minion)
	{
		minion->Render(graphics);
	});
}

// Spawn from top (AI)
bool Lane::AddToBottom(std::shared_ptr<MinionObject>&& minion)
{
	if (!m_isPlayerBlocked)
	{
		minion->SetPosition(m_bottomSpawnPosition.x - minion->GetWidth() / 2, m_bottomSpawnPosition.y - minion->GetHeight());
		m_bottomObjects.push_back(std::move(minion));
	}
	return !m_isPlayerBlocked;
}

// Spawn from bottom (Player)
bool Lane::AddToTop(std::shared_ptr<MinionObject>&& minion)
{
	if (!m_isBotBlocked)
	{
		minion->SetPosition(m_topSpawnPosition.x - minion->GetWidth() / 2, m_topSpawnPosition.y);
		m_topObjects.push_back(std::move(minion));
	}
	return !m_isBotBlocked;
}

bool Lane::IsClickedIn(Vector2 position)
{
	return m_collider->IsPointInside(position);
}