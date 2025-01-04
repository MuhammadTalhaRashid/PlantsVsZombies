#pragma once
#include "Plants.h"

class WallNut : public Plants
{
private:
	int health;
	int peaCount;

public:
	WallNut();
	WallNut(string, int, int);
	void Fire();
	void drawPlant(RenderWindow& window, int&);
	void destroyPea(int);

	int getPeaCount();
	int getX() override;
	int getY() override;
	int getXOfPea(int index);
	int getYOfPea(int index);
};

