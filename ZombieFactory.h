#pragma once
#include<iostream>
#include<cstdlib>
#include <SFML/Graphics.hpp>
#include"Zombie.h"
using namespace std;
using namespace sf;

//const int ScreenWidth = 1366;
//const int ScreenHeight = 768;
//const int GridWidth = 11;
//const int GridHeight = 5;
//const int BoxWidth = ScreenWidth / GridWidth;
//const int BoxHeight = ScreenHeight / GridHeight;

class ZombieFactory
{
protected:
	bool shouldSpaw = 1;
	const int zombieCount = 30;
	Zombie** zombie;
	string type;
	int currentLevel;

public:
	ZombieFactory(int );
	 int moveAllZombies();
	void spawZombies(int);
	void renderAllZombies(RenderWindow& window);
	void destroyZombie(int);

	int reachedEnd();
	int getZombieCount();
	int getX(int);
	int getY(int);
	void setX(int, int);
	string getType(int);
	void decreaseHealth(int, int&);

	void shouldStop(int);
	void shouldStart(int);

	 ~ZombieFactory();
};

