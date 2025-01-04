#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <fstream>
#include "Plants.h"
#include "Peashooter.h"
#include "Repeater.h"
#include "Sunflower.h"
#include "Snowpea.h"
#include "WallNut.h"
#include "Cherrybomb.h"
#include "LawnMover.h"

using namespace sf;

class FileHandling
{
protected:
	int getLevelOfPlayer(int lineNum);

	void createWallnutCard(RenderWindow& window);
	void createPeaShooterCard(RenderWindow& window);
	void createSunFlowerCard(RenderWindow& window);
	void createRepeaterCard(RenderWindow& window);
	void createCherryBombCard(RenderWindow& window);
	void createShovelCard(RenderWindow& window);
	void createSunCard(RenderWindow& window);
	void createSnowPeaCard(RenderWindow& window);

	//Drawing the Screen 1
	void createScreen1(RenderWindow& window);
	void createScreen2(RenderWindow& window);
	void createScreen3(RenderWindow& window);
	void createScreen31(RenderWindow& window);


	

	


public:

	//Drawing the map
	void createMap(RenderWindow& window);

	void createScreens(RenderWindow& window, int);

	void getInputScreen1(RenderWindow& window);
	int getInputScreen2(RenderWindow& window);
	int getInputScreen3(RenderWindow& window, int playerIndex);
	int getInputGameScreen(RenderWindow& window, int& sunCurrency, int levelNo, int(*gameGrid)[11], Plants* (&newplants));

	void menuScreen(RenderWindow& window);
	void resumeScreen(RenderWindow& window);

	void DrawLawnmower(RenderWindow& window, int x, int y);


};

