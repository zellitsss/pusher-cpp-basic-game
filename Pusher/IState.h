#pragma once
#include <GameEngine.h>


class IState
{
public:
	IState();
	virtual ~IState();
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender(Graphics*) = 0;
	virtual void OnExit() = 0;
};