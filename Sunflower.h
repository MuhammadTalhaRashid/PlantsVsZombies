#pragma once
#include <SFML/Graphics.hpp>
#include "Plants.h"
#include "Sun.h"

using namespace sf;
class Sunflower : public Plants {
private:
	Sun* sun;
	sf::Clock sunflowerClock;
	float timeLimit = 10.0f;
	int peaCount;

public:
	Sunflower();
	Sunflower(string, int, int);
	void Fire();
	void drawPlant(RenderWindow& window, int&);
	void destroyPea(int);
	int collectSun(RenderWindow& window, int& );

	int getPeaCount();
	int getX() override;
	int getY() override;
	int getXOfPea(int index);
	int getYOfPea(int index);
};

