#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Pea.h"

using namespace std;
using namespace sf;

class Plants
{
protected:
	string type;
	int x;
	int y;
	double dropTime;

public:
	int peaCount;

	Plants();
	Plants(string, int, int);
	virtual void drawPlant(RenderWindow& window, int &) = 0;
	virtual void destroyPea(int ) = 0;
	virtual void Fire() = 0; 

	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getXOfPea(int index) = 0;
	virtual int getYOfPea(int index) = 0;
};

