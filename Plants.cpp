#include "Plants.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include  "Repeater.h"
#include "WallNut.h"
#include "Snowpea.h"
#include "Cherrybomb.h"
#include "FloatingPad.h"
#include "Pea.h"


//implementation of Class FloatingPad
floatingPad::floatingPad() : Plants("", 0, 0) {}
floatingPad::floatingPad(string type, int x, int y) : Plants(type, x, y) {}
void floatingPad::drawPlant() {

}
void floatingPad::Fire() {

}
void floatingPad::destroyPea(int index) {}
int floatingPad::getX() {
    return this->x;
}
int floatingPad::getY() {
    return this->y;
}


//implementation of Class Plants
Plants::Plants() : type(""), x(-1), y(-1) {}
Plants::Plants(string ttype, int xx, int yy) : type(ttype), x(xx), y(yy) {}
