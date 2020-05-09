#pragma once
#include <GameEngine.h>
#include "IState.h"


class StateMachine
{
private:
	StateMachine();
	static StateMachine* s_instance;
	IState* m_currentState;
	IState* m_nextState;
	bool m_isExitCurrentState;
	Device* m_device;
	Graphics* m_graphics;
public:
	~StateMachine();
	static StateMachine* GetInstance();
	static void DestroyInstance();
	void SwitchState(IState*);
	void Init();
	void Update();
	void Render();
	void SetStartupState(IState*);
};