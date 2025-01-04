#pragma once
#include <SFML/Graphics.hpp>
#include "Plants.h"
#include "Zombie.h"
#include "SimpleZombie.h"
#include "Peashooter.h"

using namespace sf;

class LawnMover
{
private:
	bool running;
	int x;
	int y;

public:
	LawnMover(int, int);
	int move(int gameGrid[][11], Plants* newplant, Zombie* newzombie);
	void startMoving();
	void draw(RenderWindow& window);

	int getx();
	int gety();
};

