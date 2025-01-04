#include "Zombie.h"
#include"SimpleZombie.h"
#include<iostream>
using namespace std;

const int ScreenWidth = 1366;
const int ScreenHeight = 768;
const int GridWidth = 11;
const int GridHeight = 5;
const int BoxWidth = ScreenWidth / GridWidth;
const int BoxHeight = ScreenHeight / GridHeight;

Zombie::Zombie()
{
	type = "";
	x = 0;
	y = 0;
}

Zombie::Zombie(string name_type, int start_x, int start_y) 
{
	type = name_type;
	x = start_x;
	y = start_y;
	zombieHealth = 3;
}

//bool Zombie::isExist() const
//{
  //  return exist;
//}

//void Zombie::setExist(bool res)
//{
	//exist = res;
//}

//int Zombie::getX()
//{
//	//return this->x;
//}
//
//int Zombie::getY()
//{
//	//return this->y;
//}



