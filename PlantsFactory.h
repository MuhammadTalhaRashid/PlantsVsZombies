#pragma once
#include <SFML/Graphics.hpp>
#include "Plants.h"
#include "Sun.h"

using namespace sf;
class PlantsFactory
{
private:
	Plants** plants;
	int totalPlants;
	int currentLevel;
	int sunCount;
	Sun** sun;
	sf::Clock sunClock;
	float timeLimit = 20.0f;

public:
	PlantsFactory(int );
	int play(int& );
	void callSun();
	void drawPlant(RenderWindow& window, int& sunCurrency);
	void harvestPlant(Plants* plants);
	bool destroyPlant(Plants* ,int );
	void destroyPea(int, int);
	void Fire();
	int collectSun(RenderWindow& window, int& sunCurrency);

	int getPlantsCount();
	int getX(int index);
	int getY(int index);
	int getXOfPea(int index, int index1) ;
	int getYOfPea(int index, int index1) ;

	~PlantsFactory();
};

