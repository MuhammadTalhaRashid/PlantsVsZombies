#include "ZombieFactory.h"
#include<iostream>
#include<cstdlib>
#include"Zombie.h"
#include"SimpleZombie.h"
#include"FlyingZombie.h"
#include"FootballZombie.h"
#include"DancingZombie.h"
using namespace std;

//const int ScreenWidth = 1366;
//const int ScreenHeight = 768;
//const int GridWidth = 11;
//const int GridHeight = 5;
//const int BoxWidth = ScreenWidth / GridWidth;
//const int BoxHeight = ScreenHeight / GridHeight;

ZombieFactory::ZombieFactory(int clevel) : currentLevel(clevel)
{
	zombie = new Zombie * [zombieCount];
	for (int i = 0; i < zombieCount; i++) {
		zombie[i] = NULL;
 	}
}

void ZombieFactory::spawZombies(int currLevel)
{
	if (shouldSpaw) {
		shouldSpaw = 0;

		srand(time(NULL));
		for (int i = 0; i < zombieCount; i++)
		{
			int chooseZombie;
			if (currentLevel == 1)
			{
				chooseZombie = 1;
			}
			else if (currentLevel == 2)
			{
				chooseZombie = (rand() % 4) + 1;
			}
			else if (currentLevel == 3)
			{
				chooseZombie = (rand() % 4) + 1;
			}
			else
			{
				chooseZombie = (rand() % 4) + 1;
			}

			int randNum = (rand() % 10) + 1;
			int randNumRow = (rand() % 5) + 1;
			if (randNumRow == 1)
			{
				switch (chooseZombie)
				{
				case 1:
					zombie[i] = new SimpleZombie("simplezombie", 1365 + (randNum * i * 50) + (i * 20), 100);
					break;
				case 2:
					zombie[i] = new FlyingZombie("flyingzombie", 1365 + (randNum * i * 50) + (i * 20), 100);
					break;
				case 3:
					zombie[i] = new FootballZombie("footballzombie", 1365 + (randNum * i * 50) + (i * 20), 100);
					break;
				case 4:
					zombie[i] = new DancingZombie("dancingzombie", 1365 + (randNum * i * 50) + (i * 20), 100);
					break;
				}
			}
			else if (randNumRow == 2)
			{
				switch (chooseZombie)
				{
				case 1:
					zombie[i] = new SimpleZombie("simplezombie", 1365 + (randNum * i * 50) + (i * 20), 225);
					break;
				case 2:
					zombie[i] = new FlyingZombie("flyingzombie", 1365 + (randNum * i * 50) + (i * 20), 225);
					break;
				case 3:
					zombie[i] = new FootballZombie("footballzombie", 1365 + (randNum * i * 50) + (i * 20), 225);
					break;
				case 4:
					zombie[i] = new DancingZombie("dancingzombie", 1365 + (randNum * i * 50) + (i * 20), 225);
					break;
				}

			}
			else if (randNumRow == 3)
			{
				switch (chooseZombie)
				{
				case 1:
					zombie[i] = new SimpleZombie("simplezombie", 1365 + (randNum * i * 50) + (i * 20), 350);
					break;
				case 2:
					zombie[i] = new FlyingZombie("flyingzombie", 1365 + (randNum * i * 50) + (i * 20), 350);
					break;
				case 3:
					zombie[i] = new FootballZombie("footballzombie", 1365 + (randNum * i * 50) + (i * 20), 350);
					break;
				case 4:
					zombie[i] = new DancingZombie("dancingzombie", 1365 + (randNum * i * 50) + (i * 20), 350);
					break;
				}
			}
			else if (randNumRow == 4)
			{
				switch (chooseZombie)
				{
				case 1:
					zombie[i] = new SimpleZombie("simplezombie", 1365 + (randNum * i * 50) + (i * 20), 475);
					break;
				case 2:
					zombie[i] = new FlyingZombie("flyingzombie", 1365 + (randNum * i * 50) + (i * 20), 475);
					break;
				case 3:
					zombie[i] = new FootballZombie("footballzombie", 1365 + (randNum * i * 50) + (i * 20), 475);
					break;
				case 4:
					zombie[i] = new DancingZombie("dancingzombie", 1365 + (randNum * i * 50) + (i * 20), 475);
					break;
				}
			}
			else
			{
				switch (chooseZombie)
				{
				case 1:
					zombie[i] = new SimpleZombie("simplezombie", 1365 + (randNum * i * 50) + (i * 20), 600);
					break;
				case 2:
					zombie[i] = new FlyingZombie("flyingzombie", 1365 + (randNum * i * 50) + (i * 20), 600);
					break;
				case 3:
					zombie[i] = new FootballZombie("footballzombie", 1365 + (randNum * i * 50) + (i * 20), 600);
					break;
				case 4:
					zombie[i] = new DancingZombie("dancingzombie", 1365 + (randNum * i * 50) + (i * 20), 600);
					break;
				}
			}
		}
	}
}

int ZombieFactory::moveAllZombies()
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (zombie[i] != NULL)
			zombie[i]->moveZombie();
	}
	return -1;
}

void ZombieFactory::renderAllZombies(RenderWindow& window)
{
	for (int i = 0; i < zombieCount; i++) {
		if (zombie[i] != NULL)
			zombie[i]->callZombie(window);
	}
}

void ZombieFactory::destroyZombie(int index) {
	for (int i = 0; i < zombieCount; i++) {
		if (i == index) {
			delete zombie[i];
			zombie[i] = NULL;
		}
	}
}

int ZombieFactory::reachedEnd() {
	for (int i = 0; i < zombieCount; i++) {
		if (zombie[i] != NULL)
			if (zombie[i]->reachedEnd() != -1)
				return zombie[i]->reachedEnd();
			else
				return -1;
	}
}
int ZombieFactory::getZombieCount() {
	return zombieCount;
}
int ZombieFactory::getX(int index)
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index && zombie[i] != NULL)
		{
			return zombie[i]->getX();
		}
	}
}
int ZombieFactory::getY(int index)
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index && zombie[i] != NULL)
		{
			return zombie[i]->getY();
		}
	}
}

void ZombieFactory::setX(int index1, int index2)
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index1 && zombie[i] != NULL)
		{
			zombie[i]->setX(index2);
		}
	}
}
string ZombieFactory::getType(int index)
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index && zombie[i] != NULL)
		{
			return zombie[i]->getType();
		}
	}
}
void ZombieFactory::decreaseHealth(int index , int& killed)
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index && zombie[i] != NULL)
		{
			zombie[i]->decreaseHealth();
			if (zombie[i]->getHealth() == 0) {
				killed++;
				delete zombie[i];
				zombie[i] = NULL;
			}
		}
	}
}

void ZombieFactory::shouldStop(int index) {
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index && zombie[i] != NULL)
		{
			zombie[i]->shouldStop();
		}
	}
}
void ZombieFactory::shouldStart(int index) {
	for (int i = 0; i < zombieCount; i++)
	{
		if (i == index && zombie[i] != NULL)
		{
			zombie[i]->shouldStart();
		}
	}
}

ZombieFactory::~ZombieFactory()
{
	for (int i = 0; i < zombieCount; i++)
	{
		if (zombie[i] != NULL) {
			delete zombie[i];
		}
	}
	delete[] zombie;
}
