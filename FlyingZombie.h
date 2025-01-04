#pragma once
#include<iostream>
#include"Zombie.h"
using namespace std;
class FlyingZombie : public Zombie
{
private:
	Texture flyingZombieTexture;
	Sprite flyingZombieSprite;
	Clock flyingZombieClock;
	int thisy;
	int thisx;

public:
	FlyingZombie(string, int, int);
	int moveZombie() override;
	void callZombie(RenderWindow& window) override;
	void decreaseHealth();

	int reachedEnd();
	int getHealth();
	int getX() override;
	int getY() override;
	void setX(int) override;
	string getType() override;
	//string get_type() override;

	void shouldStop();
	void shouldStart();

};

