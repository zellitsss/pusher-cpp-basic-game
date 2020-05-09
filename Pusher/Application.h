#pragma once
#include <GameEngine.h>
#include "StateMachine.h"

class Application
{
private:
	Application();
	~Application();
	static Application* s_instance;
	Device* m_device;
	Graphics* m_graphics;
	StateMachine* m_stateMachine;

public:

	static Application* GetInstance();
	static void DestroyInstance();
	void Init();
	void Run();
	void InitData();
};