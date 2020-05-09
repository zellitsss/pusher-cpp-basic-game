#include "Score.h"
#include <GameEngine.h>

Score* Score::s_instance = nullptr;

Score::Score()
{
	m_score = 50;
}

Score::~Score()
{

}

Score* Score::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new Score();
	}
	return s_instance;
}

void Score::DestroyInstance()
{
	delete s_instance;
}

void Score::SetScore(MinionType type, MinionWeight weight)
{
	if (type == MinionType::Player)
	{
		m_score += weight * SCORE_MULTIPLIER;
	}
	else if (type == MinionType::Bot)
	{
		m_score -= weight * SCORE_MULTIPLIER;
	}
}

int Score::GetScore(MinionType type)
{
	if (type == MinionType::Player)
	{
		return m_score;
	}
	else if (type == MinionType::Bot)
	{
		return 100 - m_score;
	}
}

void Score::Reset()
{
	m_score = 50;
}