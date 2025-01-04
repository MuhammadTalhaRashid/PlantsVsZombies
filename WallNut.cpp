#include "WallNut.h"

//implementation of Class WallNut
WallNut::WallNut() : Plants("", 0, 0), peaCount(0) {}
WallNut::WallNut(string type, int x, int y) : Plants(type, x, y), health(3) {}
void WallNut::drawPlant(RenderWindow& window, int& sunCurrency) {
    if (health == 3) {
        Image map_image;
        map_image.loadFromFile("D:\\Oop Project\\images\\Wallnut_body.png");//load the file for the map
        Texture map;
        map.loadFromImage(map_image);
        Sprite s_map;
        s_map.setTexture(map);
        s_map.setPosition(x + 15, y + 15);
        s_map.setScale(0.5f, 0.5f);

        window.draw(s_map);
    }
    else if (health == 2) {
        Image map_image;
        map_image.loadFromFile("D:\\Oop Project\\images\\Wallnut_body.png");//load the file for the map
        Texture map;
        map.loadFromImage(map_image);
        Sprite s_map;
        s_map.setTexture(map);
        s_map.setPosition(x + 15, y + 15);
        s_map.setScale(0.5f, 0.5f);

        window.draw(s_map);
    }
    else if (health == 1) {
        Image map_image;
        map_image.loadFromFile("D:\\Oop Project\\images\\Wallnut_body.png");//load the file for the map
        Texture map;
        map.loadFromImage(map_image);
        Sprite s_map;
        s_map.setTexture(map);
        s_map.setPosition(x + 15, y + 15);
        s_map.setScale(0.5f, 0.5f);

        window.draw(s_map);
    }
}
void WallNut::Fire() {
    x += 1;
}
void WallNut::destroyPea(int index) {}
int WallNut::getPeaCount() {
    return peaCount;
}
int WallNut::getXOfPea(int index) {
    return -1;
}
int WallNut::getYOfPea(int index) {
    return -1;
}
int WallNut::getX() {
    return this->x;
}
int WallNut::getY() {
    return this->y;
}
