#include "FootballZombie.h"
#include<iostream>
using namespace std;

const int ScreenWidth = 1366;
const int ScreenHeight = 768;
const int GridWidth = 11;
const int GridHeight = 5;
const int BoxWidth = ScreenWidth / GridWidth;
const int BoxHeight = ScreenHeight / GridHeight;

FootballZombie::FootballZombie(string name, int start_x, int start_y) : Zombie(name, start_x, start_y)
{
    thisy = start_y;
    thisx = start_x;
    zombieSpeed = 10;
    stop = 0;
    zombieHealth = 3;

    if (!footballZombieTexture.loadFromFile("D:\\Oop Project\\images\\FootballZombieHD.png")) {
        cerr << "Error loading zombie texture!" << endl;
    }

    footballZombieSprite.setTexture(footballZombieTexture);
    footballZombieSprite.setPosition(start_x, start_y);
    footballZombieSprite.setScale(0.23f, 0.23f);


}

void FootballZombie::moveLeft()
{
    if (thisy < 730)
    {
        footballZombieSprite.setPosition(thisx, this->thisy += 150);
    }

}

void FootballZombie::moveRight()
{
    if (thisy > 0)
    {
        footballZombieSprite.setPosition(thisx, this->thisy -= 150);
    }
}

int FootballZombie::moveZombie()
{
    if (!stop) {
        if (footballZombieClock.getElapsedTime().asMilliseconds() < 0)
            return -1;
        footballZombieClock.restart();

        int randval = 0;
        bool exist = false;
        if (thisx > 400)
        {
            footballZombieSprite.setPosition(this->thisx -= zombieSpeed, thisy);
        }
        else
            return ((thisy - 100) / 125);
    }
    return -1;
}

void FootballZombie::callZombie(RenderWindow& window)
{
    window.draw(footballZombieSprite);
}
void  FootballZombie::decreaseHealth()
{
    zombieHealth -= 1;
}

int FootballZombie::reachedEnd() {
    if (thisx <= 400 + zombieSpeed + zombieSpeed)
        return ((thisy - 100) / 125);
    else
        return -1;
}
string FootballZombie::getType()
{
    return this->type;
}
int FootballZombie::getHealth() {
    return zombieHealth;
}
void FootballZombie::setX(int val)
{
    this->thisx = val;
}
int FootballZombie::getX()
{
        return this->thisx;
}
int FootballZombie::getY()
{
      return this->thisy;
}
//string SimpleZombie::get_type()
//{
//        return this->type;
//}

void FootballZombie::shouldStop() {
    stop = 1;
}
void FootballZombie::shouldStart() {
    stop = 0;
}