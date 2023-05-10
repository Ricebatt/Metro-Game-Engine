#include "Metro.h"
#include <iostream>

class Met_Game_App : public Metro::MetroApp
{
public:
	Met_Game_App()
	{
		Metro::GameWindow::Init();
		Metro::GameWindow::CreateWindow(800, 600, "Test Name");
	}

	virtual void OnUpdate() override
	{

	}
};

METRO_GAME_START(Met_Game_App);