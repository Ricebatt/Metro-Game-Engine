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
		
		dino.UpdateYCoord(dino.GetVelo());

		if (dino.GetCoords().yCoord >= 90)
		{
			dino.UpdateYVelo(-2);
		}
		else
		{
			dino.SetVelo(0);
			dino.SetCoords({ 100,90 });
		}

		if (cactus.GetCoords().xCoord >= 10)
		{
			cactus.UpdateXCoord(-5);
		}
		else
		{
			cactus.SetCoords({ 300,90 });
		}
		


		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(dino);
		renderer.Draw(cactus);
	}

	void MyKeyPressedFunc(const Metro::KeyPressed& e)
	{	
		if (e.GetKeyCode() == METRO_KEY_UP)
		{
			dino.SetVelo(30);
		}	
		if (e.GetKeyCode() == METRO_KEY_DOWN)
		{
			dino.SetVelo(-10);
		}
	}



private:
	Metro::Renderer renderer;

	Metro::Unit dino{ "../Assets/Images/dino.png", {100,90} };
	Metro::Unit cactus{ "../Assets/Images/cactus.png", {300,90} };
	Metro::Unit bird{ "../Assets/Images/bird.png", {300,200} };
	Metro::Image back{ "../Assets/Images/back.png" };
};

METRO_GAME_START(Met_Game_App);