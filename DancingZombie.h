#pragma once
#include<iostream>
#include"Zombie.h"
#include"SimpleZombie.h"
using namespace std;
class DancingZombie : public Zombie
{
private:
	Texture dancingZombieTexture;
	Sprite dancingZombieSprite;
	Clock dancingZombieClock;
	SimpleZombie** simplezombie;
	float timeLimit = 5.0f;

	int thisy;
	int thisx;

public:
	DancingZombie(string, int, int);
	int moveZombie() override;
	void callZombie(RenderWindow& window) override;
	void decreaseHealth();
	void summonZombie(RenderWindow& window);
	void moveDiagonal();

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

