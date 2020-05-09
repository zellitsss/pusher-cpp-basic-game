#pragma once
#include "settings.h"

class Score
{
private:
	static Score* s_instance;
	Score();
	~Score();
	int m_score;
public:
	static Score* GetInstance();
	static void DestroyInstance();
	void SetScore(MinionType, MinionWeight);
	int GetScore(MinionType);
	void Reset();
};

