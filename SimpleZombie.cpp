#include "SimpleZombie.h"
#include<iostream>
using namespace std;

const int ScreenWidth = 1366;
const int ScreenHeight = 768;
const int GridWidth = 11;
const int GridHeight = 5;
const int BoxWidth = ScreenWidth / GridWidth;
const int BoxHeight = ScreenHeight / GridHeight;

SimpleZombie::SimpleZombie(string name, int start_x, int start_y) : Zombie(name, start_x, start_y) 
{
    thisy = start_y;
    thisx = start_x;
    zombieSpeed = 5;
    stop = 0;
    zombieHealth = 3;

    if (!simpleZombieTexture.loadFromFile("D:\\Oop Project\\images\\Zombie_healthy.png")) {
        cerr << "Error loading zombie texture!" << endl;
    }

    simpleZombieSprite.setTexture(simpleZombieTexture);
    simpleZombieSprite.setPosition(start_x , start_y);
    simpleZombieSprite.setScale(0.28f, 0.28f);


}

int SimpleZombie::moveZombie()
{
    if (!stop) {
        if (simpleZombieClock.getElapsedTime().asMilliseconds() < 0)
            return -1;
        simpleZombieClock.restart();

        if (thisx > 400)
        {
            simpleZombieSprite.setPosition(this->thisx -= zombieSpeed, thisy);
        }
        else
            return ((thisy - 100) / 125);
    }
    return -1;
}
void SimpleZombie::decreaseHealth()
{
    zombieHealth -= 1;
}

int SimpleZombie::reachedEnd() {
    if (thisx <= 400 + zombieSpeed + zombieSpeed)
        return ((thisy - 100) / 125);
    else
        return -1;
}
int SimpleZombie::getHealth() {
    return zombieHealth;
}
void SimpleZombie::callZombie(RenderWindow& window)
{
    window.draw(simpleZombieSprite);
}
string SimpleZombie::getType()
{
    return type;
}
int SimpleZombie::getX()
{
    return this->thisx;
}
int SimpleZombie::getY()
{
    return this->thisy;
}
void SimpleZombie::setX(int val)
{
    this->thisx = val;
}

void SimpleZombie::shouldStop() {
    stop = 1;
}
void SimpleZombie::shouldStart() {
    stop = 0;
}