#include "Peashooter.h"

//implementation of Class Peashooter
Peashooter::Peashooter() : Plants("", 0, 0), pea(NULL) {}
Peashooter::Peashooter(string type, int x, int y) : Plants(type, x, y), peaCount(1), pea(NULL) {}
void Peashooter::drawPlant(RenderWindow& window, int& sunCurrency) {
    if (pea != NULL)
        pea->drawPea(window);

    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\Peashooternewnew.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x + 15, y + 15);
    s_map.setScale(0.5f, 0.5f);

    window.draw(s_map);


}
void Peashooter::Fire() {
    if (pea != NULL)
        pea->movePea();
    if (peashooterClock.getElapsedTime().asSeconds() >= timeLimit) {
        // Reset the clock
        peashooterClock.restart();
        //cout << "fired" << endl;
        //cout << "x = " << x << "     and y = " << y << endl;
        if (pea != NULL) {
            if (pea->getx() >= 1366) {
                delete pea;
                pea = NULL;
            }
        }
        if (pea == NULL)
            pea = new Pea("pea", x, y);
    }
}
void Peashooter::destroyPea(int index) {
    delete pea;
    pea = NULL;
}
int Peashooter::getPeaCount() {
    return peaCount;
}
int Peashooter::getXOfPea(int index) {
    if (index == 0 && pea != NULL)
        return pea[0].getx();
    else
        return -1;
}
int Peashooter::getYOfPea(int index) {
    if (index == 0 && pea != NULL)
        return pea[0].gety();
    else
        return -1;
}
int Peashooter::getX() {
    return this->x;
}
int Peashooter::getY() {
    return this->y;
}
