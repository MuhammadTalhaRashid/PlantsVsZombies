#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Zombie
{
protected:
	bool stop;
	int x;
	int y;
	int zombieHealth;
	int zombieSpeed;
	string type;
	bool exist;

public:
	Zombie();
	Zombie(string,int, int);
	virtual int moveZombie() = 0;
	virtual void callZombie(RenderWindow& window) = 0;

	virtual int reachedEnd() = 0;
	virtual int getHealth() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual void setX(int) = 0;
	virtual string getType() = 0;

	virtual void shouldStop() = 0;
	virtual void shouldStart() = 0;

	//virtual string get_type() = 0;
	//bool isExist() const;
	//void setExist(bool);
	virtual void decreaseHealth() = 0;
};

