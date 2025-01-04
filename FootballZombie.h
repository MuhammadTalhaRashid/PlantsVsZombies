#pragma once
#include<iostream>
#include"Zombie.h"
using namespace std;
class FootballZombie : public Zombie
{
private:
	Texture footballZombieTexture;
	Sprite footballZombieSprite;
	Clock footballZombieClock;
	int thisy;
	int thisx;
public:
	FootballZombie(string, int, int);
	int moveZombie() override;
	void callZombie(RenderWindow& window) override;
	void moveLeft();
	void moveRight();
	void decreaseHealth();

	int reachedEnd();
	int getHealth();
	int getX() override;
	int getY() override;
	void setX(int) override;
	string getType() override;

	void shouldStop();
	void shouldStart();
};

