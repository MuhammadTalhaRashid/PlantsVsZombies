#include "LawnMover.h"

LawnMover::LawnMover(int x, int y) {
	this->x = x;
	this->y = y;
	running = 0;
}
int LawnMover::move(int gameGrid[][11], Plants* newplant, Zombie* newzombie) {
    if (running) {
        // Check if the lawnmower reached the end
        if (x >= 1430) {
            return -1;
        }
            x += 10; // Increment x by 10
            return 0; // normal movement

    }
}
void LawnMover::startMoving() {
		running = 1;
}
void LawnMover::draw(RenderWindow& window) {
    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\LawnMower.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x, y);
    s_map.setScale(0.65f, 0.65f);

    window.draw(s_map);
}

int LawnMover::getx() {
    return x;
}
int LawnMover::gety() {
    return y;
}