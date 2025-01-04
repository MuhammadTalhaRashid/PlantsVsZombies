#include "Cherrybomb.h"

//implementation of Class Cherrybomb
Cherrybomb::Cherrybomb() : Plants("", 0, 0), peaCount(0) {}
Cherrybomb::Cherrybomb(string type, int x, int y) : Plants(type, x, y) {}
void Cherrybomb::drawPlant(RenderWindow& window, int& sunCurrency) {
    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\cherry2.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x + 4, y + 20);
    s_map.setScale(0.18f, 0.18f);

    window.draw(s_map);

    Fire();
}
void Cherrybomb::Fire() {
    if (cherryClock.getElapsedTime().asSeconds() >= timeLimit) {
        // Reset the clock
        cherryClock.restart();

        this->x = -1843;
    }
}
void Cherrybomb::destroyPea(int index) {}
int Cherrybomb::getPeaCount() {
    return peaCount;
}
int Cherrybomb::getXOfPea(int index) {
    return -1;
}
int Cherrybomb::getYOfPea(int index) {
    return -1;
}
int Cherrybomb::getX() {
    return this->x;
}
int Cherrybomb::getY() {
    return this->y;
}
