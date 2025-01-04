#include "Pea.h"


//implementation of Class Pea
Pea::Pea() : type(""), x(-1), y(-1) {}
Pea::Pea(string ttype, int xx, int yy) : type(ttype) {
    x = xx + 90;
    y = yy + 10;
}
void Pea::drawPea(RenderWindow& window) {
    //cout << "yes gone" << endl;
    Image map_image;
    // if (type == "pea")
    map_image.loadFromFile("D:\\Oop Project\\images\\peabullet.png");//load the file for the map
    //else if (type == "snowpea")
      //  map_image.loadFromFile("D:\\Oop Project\\images\\Peabullet.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    //cout << "now x = " << x << " and y= " << y << endl;
    s_map.setPosition(x + 15, y + 15);
    s_map.setScale(1.46429f, 1.46429f);

    window.draw(s_map);

    movePea();
}
void Pea::movePea() {
    //cout << "gome" << endl;
    //if (peaClock.getElapsedTime().asSeconds() >= timeLim) {
        // Reset the clock
      //   peaClock.restart();
       // cout << "plussed" << endl;
    x += 20;
    //}
}
int Pea::getx() {
    return x;
}
int Pea::gety() {
    return y;
}
