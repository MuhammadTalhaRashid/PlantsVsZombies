#pragma once
#include <iostream>
#include <sfml\Graphics.hpp>

using namespace std;
using namespace sf;

class Pea
{
private:
	string type;
	int x;
	int y;
	sf::Clock peaClock;
	float timeLim = 0.00000001f;

public:
	Pea();
	Pea(string, int, int);
	void drawPea(RenderWindow& window);
	void movePea();
	int getx();
	int gety();

};

