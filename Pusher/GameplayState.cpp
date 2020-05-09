#include <algorithm>
#include <random>
#include "GameplayState.h"
#include "PreGameState.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "settings.h"
#include "Score.h"

GameplayState::GameplayState()
{
}


GameplayState::~GameplayState()
{
	Score::DestroyInstance();
}

void GameplayState::OnInit()
{	
	m_botNextWeight = static_cast<MinionWeight>(GenerateRandom(MinionWeight::Small, MinionWeight::Big));
	m_playerNextWeight = static_cast<MinionWeight>(GenerateRandom(MinionWeight::Small, MinionWeight::Big));
	m_botCountDown = SPAWN_COOLDOWN;
	m_playerCountDown = SPAWN_COOLDOWN;
	m_botLoadingBarWidth = COUNTDOWN_BAR_WIDTH;
	m_playerLoadingBarWidth = COUNTDOWN_BAR_WIDTH;
	m_isPlayerSpawnAble = false;

	{
		std::unique_ptr<Lane> lane = std::make_unique<Lane>();
		lane->SetArea(Vector2(LEFT_BORDER, TOP_BORDER), Vector2(DIVIDE_LINE_1, BOTTOM_BORDER));
		m_lanes.push_back(std::move(lane));

		lane = std::make_unique<Lane>();
		lane->SetArea(Vector2(DIVIDE_LINE_1, TOP_BORDER), Vector2(DIVIDE_LINE_2, BOTTOM_BORDER));
		m_lanes.push_back(std::move(lane));

		lane = std::make_unique<Lane>();
		lane->SetArea(Vector2(DIVIDE_LINE_2, TOP_BORDER), Vector2(RIGHT_BORDER, BOTTOM_BORDER));
		m_lanes.push_back(std::move(lane));
	}

	std::unique_ptr<SpriteObject> background = std::make_unique<SpriteObject>();
	background->SetImage(ResourceManager::GetInstance()->GetImage("background"));
	background->SetPosition(0.0f, 0.0f);
	m_staticObjects["background"] = std::move(background);

	std::unique_ptr<SpriteObject> botSpawm = std::make_unique<SpriteObject>();
	botSpawm->SetImage(GetIcon(MinionType::Bot, m_botNextWeight));
	botSpawm->SetPosition(SCREEN_WIDTH / 2.0f - botSpawm->GetWidth() / 2.0f, ICON_POSITION_PADDING - botSpawm->GetHeight() / 2.0f);
	m_staticObjects["bot_spawn"] = std::move(botSpawm);

	std::unique_ptr<SpriteObject> playerSpawn = std::make_unique<SpriteObject>();
	playerSpawn->SetImage(GetIcon(MinionType::Player, m_playerNextWeight));
	playerSpawn->SetPosition(SCREEN_WIDTH / 2.0f - playerSpawn->GetWidth() / 2.0f, SCREEN_HEIGHT - ICON_POSITION_PADDING - playerSpawn->GetHeight() / 2.0f);
	m_staticObjects["player_spawn"] = std::move(playerSpawn);

	std::unique_ptr<SpriteObject> playerBase = std::make_unique<SpriteObject>();
	playerBase->SetImage(ResourceManager::GetInstance()->GetImage("player_base"));
	playerBase->SetPosition(0.0f, SCREEN_HEIGHT - playerBase->GetHeight());
	m_staticObjects["player_base"] = std::move(playerBase);

	std::unique_ptr<SpriteObject> botBase = std::make_unique<SpriteObject>();
	botBase->SetImage(ResourceManager::GetInstance()->GetImage("bot_base"));
	botBase->SetPosition(0.0f, 0.0f);
	m_staticObjects["bot_base"] = std::move(botBase);

	
}

void GameplayState::OnUpdate()
{
	m_score = Score::GetInstance()->GetScore(MinionType::Player);
	if (m_score >= 100 || m_score <= 0)
	{
		StateMachine::GetInstance()->SwitchState(new PreGameState());
		Score::GetInstance()->Reset();
	}

	std::for_each(m_lanes.begin(), m_lanes.end(), [](std::unique_ptr<Lane>& lane)
	{
		lane->Update();
	});

	float dt = GameTime::GetFrameTime();
	m_botCountDown -= dt;
	
	if (!m_isPlayerSpawnAble)
	{
		m_playerCountDown -= dt;
	}

	if (m_botCountDown <= 0)
	{
		m_botCountDown = 0;
		SpawnMinion(GenerateRandom(0, 2), MinionType::Bot, m_botNextWeight);
		m_botNextWeight = static_cast<MinionWeight>(GenerateRandom(MinionWeight::Small, MinionWeight::Big));
		m_staticObjects["bot_spawn"]->SetImage(GetIcon(MinionType::Bot, m_botNextWeight));
		m_staticObjects["bot_spawn"]->SetPosition(SCREEN_WIDTH / 2.0f - m_staticObjects["bot_spawn"]->GetWidth() / 2.0f, ICON_POSITION_PADDING - m_staticObjects["bot_spawn"]->GetHeight() / 2.0f);
		m_botCountDown = SPAWN_COOLDOWN;
	}

	m_botLoadingBarWidth = m_botCountDown / SPAWN_COOLDOWN * COUNTDOWN_BAR_WIDTH;

	if (m_playerCountDown <= 0)
	{
		m_playerCountDown = 0;
		m_isPlayerSpawnAble = true;
	}
	m_playerLoadingBarWidth = m_playerCountDown / SPAWN_COOLDOWN * COUNTDOWN_BAR_WIDTH;
	
	m_botScoreHeight = (BOTTOM_BORDER - TOP_BORDER) * Score::GetInstance()->GetScore(MinionType::Bot) / 100;
	m_playerScoreHeight = (BOTTOM_BORDER - TOP_BORDER) * Score::GetInstance()->GetScore(MinionType::Player) / 100;

	TouchData* touch = InputManager::GetInstance()->GetTouch();
	if (touch != NULL && touch->state == TOUCH_UP)
	{
		if (m_isPlayerSpawnAble)
		{
			for (int i = 0; i < m_lanes.size(); i++)
			{
				if (m_lanes[i]->IsClickedIn(touch->position))
				{
					if (SpawnMinion(i, MinionType::Player, m_playerNextWeight))
					{
						m_playerNextWeight = static_cast<MinionWeight>(GenerateRandom(MinionWeight::Small, MinionWeight::Big));
						m_staticObjects["player_spawn"]->SetImage(GetIcon(MinionType::Player, m_playerNextWeight));
						m_staticObjects["player_spawn"]->SetPosition(SCREEN_WIDTH / 2.0f - m_staticObjects["player_spawn"]->GetWidth() / 2.0f, SCREEN_HEIGHT - ICON_POSITION_PADDING - m_staticObjects["player_spawn"]->GetHeight() / 2.0f);
						m_isPlayerSpawnAble = false;
						m_playerCountDown = SPAWN_COOLDOWN;
					}
					break;
				}
			}
		}
	}
}

void GameplayState::OnRender(Graphics* graphics)
{
	std::for_each(m_staticObjects.begin(), m_staticObjects.end(), [graphics](std::pair<const std::string, std::unique_ptr<SpriteObject>>& object)
	{
		object.second->Render(graphics);
	});

	graphics->SetColor(1.0f, 0.0f, 0.0f, 0.2f);
	graphics->FillRect(LEFT_BORDER - SCORE_PADDING_MASK, TOP_BORDER, RIGHT_BORDER - LEFT_BORDER + SCORE_PADDING_MASK, m_botScoreHeight);

	graphics->SetColor(0.0f, 0.0f, 1.0f, 0.2f);
	graphics->FillRect(LEFT_BORDER - SCORE_PADDING_MASK, TOP_BORDER + m_botScoreHeight, RIGHT_BORDER - LEFT_BORDER + SCORE_PADDING_MASK, m_playerScoreHeight);

	graphics->SetColor(1.0f, 0.0f, 0.0f);
	graphics->DrawRect(SCREEN_WIDTH / 2.0f - COUNTDOWN_BAR_WIDTH / 2.0f, COUNTDOWN_BAR_MARGIN, COUNTDOWN_BAR_WIDTH, COUNTDOWN_BAR_HEIGHT);
	graphics->FillRect(SCREEN_WIDTH / 2.0f - COUNTDOWN_BAR_WIDTH / 2.0f, COUNTDOWN_BAR_MARGIN, m_botLoadingBarWidth, COUNTDOWN_BAR_HEIGHT);

	graphics->SetColor(0.0f, 0.0f, 1.0f);
	graphics->DrawRect(SCREEN_WIDTH / 2.0f - COUNTDOWN_BAR_WIDTH / 2.0f, SCREEN_HEIGHT - COUNTDOWN_BAR_MARGIN - COUNTDOWN_BAR_HEIGHT, COUNTDOWN_BAR_WIDTH, COUNTDOWN_BAR_HEIGHT);
	graphics->FillRect(SCREEN_WIDTH / 2.0f - COUNTDOWN_BAR_WIDTH / 2.0f, SCREEN_HEIGHT - COUNTDOWN_BAR_MARGIN - COUNTDOWN_BAR_HEIGHT, m_playerLoadingBarWidth, COUNTDOWN_BAR_HEIGHT);

	std::for_each(m_lanes.begin(), m_lanes.end(), [graphics](std::unique_ptr<Lane>& lane)
	{
		lane->Render(graphics);
	});
	
}

void GameplayState::OnExit()
{

}

int GameplayState::GenerateRandom(int min, int max)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max);
	return distr(eng);
}

bool GameplayState::SpawnMinion(int index, MinionType type, MinionWeight weight)
{
	std::shared_ptr<MinionObject> minion = std::make_shared<MinionObject>();
	minion->SetType(type);
	minion->SetWeight(weight);
	minion->SetAnimation();
	switch (type)
	{
	case Bot:
		minion->SetVelocity(0.0f, SPEED);
		return m_lanes[index]->AddToTop(std::move(minion));
		break;
	case Player:
		minion->SetVelocity(0.0f, -SPEED);
		return m_lanes[index]->AddToBottom(std::move(minion));
		break;
	default:
		break;
	}
}

Image* GameplayState::GetIcon(MinionType type, MinionWeight weight)
{
	std::string typeStr;
	std::string size;
	switch (type)
	{
	case Bot:
		typeStr = "bot";
		break;
	case Player:
		typeStr = "player";
		break;
	default:
		break;
	}
	switch (weight)
	{
	case Small:
		size = "small";
		break;
	case Medium:
		size = "medium";
		break;
	case Big:
		size = "big";
		break;
	default:
		break;
	}
	std::string str = typeStr + "_" + size + "_icon";
	return ResourceManager::GetInstance()->GetImage(str);
}