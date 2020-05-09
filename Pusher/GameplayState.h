#pragma once
#include <memory>
#include <unordered_map>
#include <GameEngine.h>
#include "IState.h"
#include "SpriteObject.h"
#include "MinionObject.h"
#include "Lane.h"
#include "Collider.h"

class GameplayState :
	public IState
{
private:
	std::unordered_map < std::string,  std::unique_ptr<SpriteObject >> m_staticObjects;
	std::vector<std::unique_ptr<Lane>> m_lanes;

	float m_botCountDown;
	float m_botLoadingBarWidth;
	float m_botScoreHeight;
	MinionWeight m_botNextWeight;

	float m_playerCountDown;
	float m_playerLoadingBarWidth;
	float m_playerScoreHeight;
	bool m_isPlayerSpawnAble;
	MinionWeight m_playerNextWeight;

	int m_score;
public:
	GameplayState();
	~GameplayState();
	void OnExit() override;
	void OnInit() override;
	void OnRender(Graphics*) override;
	void OnUpdate() override;
	int GenerateRandom(int, int);
	bool SpawnMinion(int, MinionType, MinionWeight);
	Image* GetIcon(MinionType, MinionWeight);
};