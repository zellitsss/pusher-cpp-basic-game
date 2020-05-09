#include "StateMachine.h"
#include <GameEngine.h>


StateMachine* StateMachine::s_instance = nullptr;

StateMachine::StateMachine()
{
}


StateMachine::~StateMachine()
{
	delete m_currentState;
}

StateMachine* StateMachine::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new StateMachine();
	}
	return s_instance;
}

void StateMachine::DestroyInstance()
{
	delete s_instance;
}

void StateMachine::SwitchState(IState* nextState)
{
	m_nextState = nextState;
	m_isExitCurrentState = true;
}

void StateMachine::Init()
{
	m_isExitCurrentState = false;
	m_device = Device::GetInstance();
	m_graphics = m_device->GetGraphics();
	m_currentState->OnInit();
}

void StateMachine::Update()
{
	if (m_isExitCurrentState)
	{
		m_isExitCurrentState = false;
		m_currentState->OnExit();
		delete m_currentState;
		m_currentState = m_nextState;
		m_currentState->OnInit();
	}
	m_currentState->OnUpdate();
}

void StateMachine::Render()
{
	m_graphics->ClearScreen();
	m_currentState->OnRender(m_graphics);
}

void StateMachine::SetStartupState(IState* state)
{
	m_currentState = state;
}