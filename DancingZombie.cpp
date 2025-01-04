#include "DancingZombie.h"
#include<iostream>
using namespace std;

//const int ScreenWidth = 1366;
//const int ScreenHeight = 768;
//const int GridWidth = 11;
//const int GridHeight = 5;
//const int BoxWidth = ScreenWidth / GridWidth;
//const int BoxHeight = ScreenHeight / GridHeight;

DancingZombie::DancingZombie(string name, int start_x, int start_y) : Zombie(name, start_x, start_y)
{
    thisy = start_y;
    thisx = start_x;
    zombieSpeed = 5;
    stop = 0;
    zombieHealth = 3;

    simplezombie = new SimpleZombie*;
    simplezombie[0] = NULL;
    //simplezombie[1] = NULL;
    //simplezombie[2] = NULL;

    if (!dancingZombieTexture.loadFromFile("D:\\Oop Project\\images\\HD_Disco_Zombie.png")) {
        cerr << "Error loading zombie texture!" << endl;
    }

    dancingZombieSprite.setTexture(dancingZombieTexture);
    dancingZombieSprite.setPosition(start_x, start_y);
    dancingZombieSprite.setScale(0.2f, 0.2f);


}

int DancingZombie::moveZombie()
{
    if (!stop) {

        if (dancingZombieClock.getElapsedTime().asMilliseconds() < 0)
            return -1;
        dancingZombieClock.restart();

        if (thisx > 400)
        {
            dancingZombieSprite.setPosition(this->thisx -= zombieSpeed, thisy);
        }
    }

    return -1;
}

void DancingZombie::callZombie(RenderWindow& window)
{
    window.draw(dancingZombieSprite);
    summonZombie(window);
}
void DancingZombie::summonZombie(RenderWindow& window)
{
    if (dancingZombieClock.getElapsedTime().asMilliseconds() > timeLimit)
    {
        simplezombie[0] = new SimpleZombie("simplezombie", thisx + 100, thisy);
        simplezombie[0]->callZombie(window);
        simplezombie[0]->moveZombie();

        dancingZombieClock.restart();
    }
}
void DancingZombie::decreaseHealth()
{
    zombieHealth -= 1;
}

int DancingZombie::reachedEnd() {
    if (thisx <= 400 + zombieSpeed + zombieSpeed)
        return ((thisy - 100) / 125);
    else
        return -1;
}
int DancingZombie::getHealth() {
    return zombieHealth;
}

string DancingZombie::getType()
{
    return this->type;
}
int DancingZombie::getX()
{
    return this->thisx;
}
int DancingZombie::getY()
{
    return this->thisy;
}
void DancingZombie::setX(int val)
{
    this->thisx = val;
}

void DancingZombie::shouldStop() {
    stop = 1;
}
void DancingZombie::shouldStart() {
    stop = 0;
}
