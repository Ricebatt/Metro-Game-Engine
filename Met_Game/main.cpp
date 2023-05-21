#include "Metro.h"
#include <iostream>
#include <functional>

class Met_Game_App : public Metro::MetroApp
{
public:
	Met_Game_App()
	{
		SetKeyPressedCallback([this](const Metro::KeyPressed& e) {MyKeyPressedFunc(e); });

	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(unit);
	}

	void MyKeyPressedFunc(const Metro::KeyPressed& e)
	{
		if (e.GetKeyCode() == METRO_KEY_RIGHT)
			unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == METRO_KEY_LEFT)
			unit.UpdateYCoord(-20);
	}
	
private:
	Metro::Renderer renderer;

	Metro::Unit unit{ "../Assets/Images/test.png", {100,100} };
	Metro::Image back{ "../Assets/Images/back.png" };
};

METRO_GAME_START(Met_Game_App);