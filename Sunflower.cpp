#include "Sunflower.h"

//implementation of Class Sunflower
Sunflower::Sunflower() : Plants("", 0, 0), peaCount(0) {}
Sunflower::Sunflower(string type, int x, int y) : Plants(type, x, y) {}
void Sunflower::drawPlant(RenderWindow& window, int& sunCurrency) {
    Image map_image;
    map_image.loadFromFile("D:\\Oop Project\\images\\sunflower (1).png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(x + 15, y + 15);
    s_map.setScale(0.5f, 0.6f);

    window.draw(s_map);
    if (sun != NULL) {
        sun->draw(window);
        collectSun(window, sunCurrency);
    }


}
void Sunflower::Fire() {
    if (sunflowerClock.getElapsedTime().asSeconds() >= timeLimit) {
        // Reset the clock
        sunflowerClock.restart();

        sun = new Sun(x, y, 0);
    }
}
int Sunflower::collectSun(RenderWindow& window, int& sunCurrency) {

    // Event loop to handle mouse clicks
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int userInputX = event.mouseButton.x; // Get x-coordinate of mouse click
                int userInputY = event.mouseButton.y; // Get y-coordinate of mouse click

                // Iterate through each sun and check if the user click falls within its bounds
                if (sun != NULL) {
                    int sunX = sun->getx(); // Get x-coordinate of the current sun
                    int sunY = sun->gety(); // Get y-coordinate of the current sun
                    int sunWidth = 80; // Width of the sun
                    int sunHeight = 80; // Height of the sun

                    // Check if user click falls within the bounds of the current sun
                    if (userInputX >= sunX && userInputX <= sunX + sunWidth &&
                        userInputY >= sunY && userInputY <= sunY + sunHeight) {

                        delete sun;
                        sun = NULL;
                        sunCurrency += 25;
                    }
                }

            }
            break;
        }
        break;
    }
    return 0;
}

void Sunflower::destroyPea(int index) {}
int Sunflower::getPeaCount() {
    return peaCount;
}
int Sunflower::getXOfPea(int index) {
    return -1;
}
int Sunflower::getYOfPea(int index) {
    return -1;
}
int Sunflower::getX() {
    return this->x;
}
int Sunflower::getY() {
    return this->y;
}
