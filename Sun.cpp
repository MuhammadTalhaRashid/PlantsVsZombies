#include "Sun.h"

Sun::Sun(int xx, int yy, bool stat) {
	x = xx;
	y = yy;
	staticSun = stat;
}
void Sun::move() {
    if (sunClock.getElapsedTime().asSeconds() >= timeLimit) {
        // Reset the clock
        sunClock.restart();

        y += 10;
    }
}
void Sun::draw(RenderWindow& window) {
    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\sunnew.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x, y);
    //s_map.setScale(0.375f, 0.375f);

    window.draw(s_map);
}
int Sun::getx() {
	return x;
}
int Sun::gety() {
	return y;
}