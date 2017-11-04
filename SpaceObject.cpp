#include "SpaceObject.hpp"

/*CONSTRUCTORS AND DESTRUCTOR*/

SpaceObject::SpaceObject() {
    _x = 0;
    _y = 0;
    _damage = 0;
    _maxHP = 0;
    _hp = _maxHP;
}

SpaceObject::SpaceObject(int _x, int _y, int _damage, int _hp, int _maxHP) : _x(_x), _y(_y), _damage(_damage), _hp(_hp),
                                                                             _maxHP(_maxHP) {}

SpaceObject::SpaceObject(SpaceObject &spaceObject) {
    *this = spaceObject;
}

SpaceObject::~SpaceObject() {}

/*GETTERS*/

int SpaceObject::getX() const {
    return _x;
}

int SpaceObject::getY() const {
    return _y;
}

int SpaceObject::getDamage() const {
    return _damage;
}

int SpaceObject::getHP() const {
    return _hp;
}

int SpaceObject::getMaxHP() const {
    return _maxHP;
}

SpaceObject &SpaceObject::operator=(const SpaceObject &spaceObject) {
    _x = spaceObject._x;
    _y = spaceObject._y;
    _damage = spaceObject._damage;
    _hp = spaceObject._hp;
    _maxHP = spaceObject._maxHP;
    return *this;
}

SpaceObject &SpaceObject::operator+=(int amount) {
    _hp += amount;
    _normHP();
    return *this;
}

SpaceObject &SpaceObject::operator-=(int amount) {
    _hp -= amount;
    _normHP();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const SpaceObject &o) {
    os << "SpaceObject => x: " << o.getX() << " y: " << o.getY() << " damage: " << o.getDamage() << " hp: " << o.getHP()
       << " maxHP: " << o.getMaxHP();
    return os;
}

/*LOGIC*/


void SpaceObject::moveDown(int distance) {
    if (distance < 0) {
        distance = 0;
    }
    _y -= distance;
}

void SpaceObject::moveUp(int distance) {
    if (distance < 0) {
        distance = 0;
    }
    _y += distance;
}

void SpaceObject::moveLeft(int distance) {
    if (distance < 0) {
        distance = 0;
    }
    _x -= distance;
}

void SpaceObject::moveRight(int distance) {
    if (distance < 0) {
        distance = 0;
    }
    _x += distance;
}

void SpaceObject::_normHP() {
    if (_hp < 0) {
        _hp = 0;
    }
    if (_hp > _maxHP) {
        _hp = _maxHP;
    }
}

void SpaceObject::kill() {
    _hp = 0;
}


