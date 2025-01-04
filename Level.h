#pragma once
#include<iostream>
#include"Sun.h"
#include"PlantsFactory.h"
#include"ZombieFactory.h"
#include"LawnMover.h"
#include "FileHandling.h"

using namespace std;
class Level
{
protected:
	int zombieKilled;
	int lives;
	int playerInfoIndex;
	int playerScore;
	int suncurrency;
	int currentLevel;
	Clock levelClock;
	Clock levelClock1;
	int timeLimit = 20.0f;
	int timeLimit1 = 20.0f;
	PlantsFactory* plants;
	Plants* newPlants;
	Zombie* newzombie;
	ZombieFactory* zombie;
	FileHandling filehandling;
	LawnMover** lawnmover;

public:
	Level();
	Level(int cLevel, int);
	int play(int(*gameGrid)[11]);
	
	void checkCollision();
	void draw(RenderWindow& window, int(*gameGrid)[11]);
	void setLevel(int );

	~Level();
};

