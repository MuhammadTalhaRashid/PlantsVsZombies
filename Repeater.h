#pragma once
#include "Plants.h"

class Repeater : public Plants
{
private:
	bool shooted;
	Pea** pea;
	sf::Clock repeaterClock;
	float timeLimit = 3.0f;
	float timeLimit1 = 1.5f;
	int peaCount;

public:
	Repeater();
	Repeater(string, int, int);
	void Fire();
	void drawPlant(RenderWindow& window, int&);
	void destroyPea(int);

	int getPeaCount();
	int getX() override;
	int getY() override;
	int getXOfPea(int index) override;
	int getYOfPea(int index) override;
};

