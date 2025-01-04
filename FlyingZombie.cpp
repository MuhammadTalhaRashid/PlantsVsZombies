#include "FlyingZombie.h"
#include<iostream>
using namespace std;

const int ScreenWidth = 1366;
const int ScreenHeight = 768;
const int GridWidth = 11;
const int GridHeight = 5;
const int BoxWidth = ScreenWidth / GridWidth;
const int BoxHeight = ScreenHeight / GridHeight;

FlyingZombie::FlyingZombie(string name, int start_x, int start_y) : Zombie(name, start_x, start_y)
{
    thisy = start_y;
    thisx = start_x;
    zombieSpeed = 7;
    stop = 0;
    zombieHealth = 3;

    if (!flyingZombieTexture.loadFromFile("D:\\Oop Project\\images\\BallonZombieHD.png")) {
        cerr << "Error loading zombie texture!" << endl;
    }

    flyingZombieSprite.setTexture(flyingZombieTexture);
    flyingZombieSprite.setPosition(start_x, start_y);
    flyingZombieSprite.setScale(0.28f, 0.28f);


}

int FlyingZombie::moveZombie()
{
    if (flyingZombieClock.getElapsedTime().asMilliseconds() < 0)
        return -1;
    flyingZombieClock.restart();

    if(thisx>400)
    {
        flyingZombieSprite.setPosition(this->thisx -= zombieSpeed, thisy);
    }
    else
        return ((thisy - 100) / 125);
    return -1;
}

void FlyingZombie::callZombie(RenderWindow& window)
{
    window.draw(flyingZombieSprite);
}
void FlyingZombie::decreaseHealth()
{
    zombieHealth -= 1;
}

int FlyingZombie::reachedEnd() {
    if (thisx <= 400 + zombieSpeed + zombieSpeed)
        return ((thisy - 100) / 125);
    else
        return -1;
}
int FlyingZombie::getHealth() {
    return zombieHealth;
}
string FlyingZombie::getType()
{
    return this->type;
}
int FlyingZombie::getX()
{
    return this->thisx;
}
int FlyingZombie::getY()
{
    return this->thisy;
}
void FlyingZombie::setX(int val)
{
    this->thisx = val;
}

void FlyingZombie::shouldStop() {
    stop = 1;
}
void FlyingZombie::shouldStart() {
    stop = 0;
}