#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class Sun
{
private:
	int x;
	int y;
	bool staticSun;
	sf::Clock sunClock;
	float timeLimit = 1.0f;

public:
	Sun(int, int, bool);
	void move();
	void draw(RenderWindow& window);
	int getx();
	int gety();

};

