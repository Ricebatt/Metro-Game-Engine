#include "Metro.h"
#include <iostream>
#include <functional>
#include <random>

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
			dino.UpdateYVelo(-3);
		}
		else
		{
			dino.SetVelo(0);
			dino.SetCoords({ 100,90 });
		}



		if (cactus.GetCoords().xCoord >= -100)
		{
			cactus.UpdateXCoord(-20);
		}
		else if ((rand() % 100) == 1)
		{
			cactus.SetCoords({ 1000,90 });
		}


		if (cactus2.GetCoords().xCoord >= -100)
		{
			cactus2.UpdateXCoord(-20);
		}
		else if ((rand() % 100) == 1)
		{
			cactus2.SetCoords({ 1000,90 });
		}


		if (cactus3.GetCoords().xCoord >= -100)
		{
			cactus3.UpdateXCoord(-20);
		}
		else if ((rand() % 150) == 1)
		{
			cactus3.SetCoords({ 1000,90 });
		}


		if (bird.GetCoords().xCoord >= -100)
		{
			bird.UpdateXCoord(-35);
		}
		else if ((rand() % 100) == 1)
		{
			bird.SetCoords({ 1000,200 });
		}
		

		
		if (Metro::UnitsOverlap(dino, cactus) || Metro::UnitsOverlap(dino, cactus2) || Metro::UnitsOverlap(dino, cactus3) || Metro::UnitsOverlap(dino, bird))
		{
			gameEnd = true;
		}
		

		
		renderer.Clear();

		renderer.Draw(back, { 0,0 });

		if (!gameEnd)
		{
			renderer.Draw(dino);
			renderer.Draw(cactus);
			renderer.Draw(cactus2);
			renderer.Draw(cactus3);
			renderer.Draw(bird);
		}
		else
		{
			renderer.Draw(gameOver);
		}

		
		
	}

	void MyKeyPressedFunc(const Metro::KeyPressed& e)
	{	
		if (e.GetKeyCode() == METRO_KEY_UP && dino.GetCoords().yCoord <= 90)
		{
			dino.SetVelo(30);
		}	
		if (e.GetKeyCode() == METRO_KEY_DOWN)
		{
			dino.SetVelo(-35);
		}
	}



private:
	Metro::Renderer renderer;

	Metro::Unit dino{ "../Assets/Images/dino.png", {100,90} };
	Metro::Unit cactus{ "../Assets/Images/cactus.png", {1000,90} };
	Metro::Unit cactus2{ "../Assets/Images/cactus.png", {1000,90} };
	Metro::Unit cactus3{ "../Assets/Images/cactusGroup.png", {1500,90} };
	Metro::Unit bird{ "../Assets/Images/bird.png", {1000,200} };

	Metro::Unit gameOver{ "../Assets/Images/gameEnd.png", { 0,0 } };
	Metro::Image back{ "../Assets/Images/back.png" };
	

	bool gameEnd = false;
};

METRO_GAME_START(Met_Game_App);