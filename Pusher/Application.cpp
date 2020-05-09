#include "Application.h"
#include <list>
#include "ResourceManager.h"
#include "StateMachine.h"
#include "PreGameState.h"
#include "settings.h"

Application* Application::s_instance = nullptr;

Application::Application()
{
}


Application::~Application()
{
}

Application* Application::GetInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new Application();
	}
	return s_instance;
}

void Application::DestroyInstance()
{
	Device::DestroyInstance();
	StateMachine::DestroyInstance();
	ResourceManager::DestroyInstance();
	InputManager::DestroyInstance();
	delete s_instance;
}

void Application::Init()
{
	m_device = Device::GetInstance();
	m_device->InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_graphics = m_device->GetGraphics();
	InitData();
	m_stateMachine = StateMachine::GetInstance();
	m_stateMachine->SetStartupState(new PreGameState());
	m_stateMachine->Init();
}

void Application::InitData()
{
	// Data will be initialized with text file later
	ResourceManager* rm = ResourceManager::GetInstance();

	rm->LoadData("../Data/images.bin");
	rm->LoadData("../Data/animations.bin");
	rm->LoadData("../Data/buttons.bin");

}

void Application::Run()
{
	while (m_device->IsRunning())
	{
		m_stateMachine->Update();
		m_stateMachine->Render();
	}
}