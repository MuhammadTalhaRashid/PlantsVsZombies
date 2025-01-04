#include "Snowpea.h"


//implementation of Class Snowpea
Snowpea::Snowpea() : Plants("", 0, 0), peaCount(1), pea(NULL) {}
Snowpea::Snowpea(string type, int x, int y) : Plants(type, x, y), pea(NULL) {}
void Snowpea::drawPlant(RenderWindow& window, int& sunCurrency) {
    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\HDplus_snowpea.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x + 15, y + 15);
    s_map.setScale(0.5f, 0.5f);

    window.draw(s_map);

    if (pea != NULL)
        pea->drawPea(window);
}
void Snowpea::Fire() {
    if (pea != NULL)
        pea->movePea();
    if (snowPeaClock.getElapsedTime().asSeconds() >= timeLimit) {
        // Reset the clock
        snowPeaClock.restart();
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
void Snowpea::destroyPea(int index) {
    delete pea;
    pea = NULL;
}
int Snowpea::getPeaCount() {
    return peaCount;
}
int Snowpea::getXOfPea(int index) {
    if (index == 0 && pea != NULL)
        return pea[0].getx() * -1;
    else
        return -1;
}
int Snowpea::getYOfPea(int index) {
    if (index == 0 && pea != NULL)
        return pea[0].gety() * -1;
    else
        return -1;
}
int Snowpea::getX() {
    return this->x;
}
int Snowpea::getY() {
    return this->y;
}
