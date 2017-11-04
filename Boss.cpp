#include "Boss.hpp"
/*CONSTRUCTORS AND DESTRUCTOR*/
/*GETTERS*/
/*LOGIC*/
int Boss::getSize() const {
    return _size;
}

Boss::Boss() : SpaceObject(0, 0, 40, 40, 40, 2) {
    _size = 2;
}

Boss::Boss(int x, int y) : SpaceObject(x, y, 40, 40, 40, 2) {
    _size = 2;
}

Boss::Boss(Boss &boss) {
    *this = boss;
}

Boss::Boss(int x, int y, int hp, int size) : SpaceObject(x, y, hp, hp, hp, size) {
    _size = _size < 0 ? 0 : _size;
}

Boss::~Boss() {}

void Boss::moveLeft(int distance) {
    SpaceObject::moveLeft(distance);
}

void Boss::moveRight(int distance) {
    SpaceObject::moveRight(distance);
}
