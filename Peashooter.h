#pragma once
#include "Plants.h"

class Peashooter : public Plants {
private:
	Pea* pea;
	sf::Clock peashooterClock;
	float timeLimit = 2.0f;
	int peaCount;

public:
	Peashooter();
	Peashooter(string, int, int);
	void Fire();
	void drawPlant(RenderWindow& window, int&);
	void destroyPea(int);

	int getPeaCount();
	int getX() override;
	int getY() override;
	int getXOfPea(int index) override;
	int getYOfPea(int index) override;
};

