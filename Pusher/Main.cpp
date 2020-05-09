#include <GameEngine.h>
#include <stdlib.h>
#include "Application.h"


const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 800;
const float RADIUS = 60.0f;
const float BAR_WIDTH = 100.0f;
const float BAR_HEIGHT = 100.0f;

/**
* The main Program
**/
int main()
{
	// Init Game 
	Application* app = Application::GetInstance();
	app->Init();
	InputManager *inputManager = InputManager::GetInstance();
	// Game Loop
	app->Run();

	// Exit Game
	Application::DestroyInstance();

    return 0;
}