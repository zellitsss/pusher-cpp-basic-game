#include "PreGameState.h"
#include "GameplayState.h"
#include "ResourceManager.h"
#include "StateMachine.h"
#include "settings.h"

PreGameState::PreGameState()
{
}


PreGameState::~PreGameState()
{
}

void PreGameState::OnExit()
{
}

void PreGameState::OnInit()
{
	m_playButton = ResourceManager::GetInstance()->GetButton("play_button");
	m_playButton->SetPositionButton(Vector2(SCREEN_WIDTH / 2.0f - m_playButton->GetWidth() / 2.0f, SCREEN_HEIGHT / 2.0f - m_playButton->GetHeight() / 2.0f));
	m_playButton->SetOnClickCallBack([]() {
		StateMachine::GetInstance()->SwitchState(new GameplayState());
	});
}

void PreGameState::OnUpdate()
{
	m_playButton->Update();
}

void PreGameState::OnRender(Graphics* graphics)
{
	graphics->SetColor(0.28f, 0.859f, 0.984f); // Just a Cyan
	graphics->FillRect(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	graphics->DrawUIButton(m_playButton);
}