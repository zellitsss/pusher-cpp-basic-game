#pragma once
#include "IState.h"
#include <memory>

class PreGameState :
	public IState
{
private:
	UIButton* m_playButton;
public:
	PreGameState();
	~PreGameState();
	void OnExit() override;
	void OnInit() override;
	void OnRender(Graphics*) override;
	void OnUpdate() override;
};

