#include "Repeater.h"

//implementation of Class Repeater
Repeater::Repeater() : Plants("", 0, 0), peaCount(2), pea(NULL) {}
Repeater::Repeater(string type, int x, int y) : Plants(type, x, y), pea(NULL) {
    pea = new Pea*;
    pea[0] = NULL;
    pea[1] = NULL;
    shooted = 0;
}
void Repeater::drawPlant(RenderWindow& window, int& sunCurrency) {
    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\HD_Repeater.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x, y);
    s_map.setScale(0.5f, 0.5f);

    window.draw(s_map);

    if (pea[0] != NULL)
        pea[0]->drawPea(window);
    if (pea[1] != NULL)
        pea[1]->drawPea(window);

}
void Repeater::Fire() {
    if (repeaterClock.getElapsedTime().asSeconds() >= timeLimit1) {
        if (!shooted) {
            shooted = 1;
            
            if(pea[0]==NULL)
            {
                pea[0] = new Pea("pea", x, y);
            }
        }

        if (repeaterClock.getElapsedTime().asSeconds() >= timeLimit) {
            repeaterClock.restart();
            shooted = 0;
            if(pea[1]==NULL)
            {
                pea[1] = new Pea("pea", x, y);
            }
        }
    }
}
void Repeater::destroyPea(int index) {
    delete pea[index];
    pea[index] = NULL;
}
int Repeater::getPeaCount() {
    return peaCount;
}
int Repeater::getXOfPea(int index) {
    if ((index == 0 || index == 1) && pea[index] != NULL)
        return pea[index]->getx();
    else
        return -1;
}
int Repeater::getYOfPea(int index) {
    if ((index == 0 || index == 1) && pea[index] != NULL)
        return pea[index]->gety();
    else
        return -1;
}
int Repeater::getX() {
    return this->x;
}
int Repeater::getY() {
    return this->y;
}
