#pragma once
#include "Plants.h"

class Cherrybomb : public Plants
{
private:
	int peaCount;

public:
	Cherrybomb();
	Cherrybomb(string, int, int);
	void Fire();
	void drawPlant(RenderWindow& window, int&);
	void destroyPea(int);
	Clock cherryClock;
	int timeLimit = 5.0f;

	int getPeaCount();
	int getX() override;
	int getY() override;
	int getXOfPea(int index);
	int getYOfPea(int index);
};

