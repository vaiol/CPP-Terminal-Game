#include "SpaceObject.hpp"

/*CONSTRUCTORS AND DESTRUCTOR*/

SpaceObject::SpaceObject() {
    _x = 0;
    _y = 0;
    _damage = 0;
    _maxHP = 0;
    _hp = _maxHP;
}

SpaceObject::SpaceObject(int x, int y, int damage, int hp, int maxHP, int speed) : _x(x), _y(y), _damage(damage), _hp(hp), _maxHP(maxHP), _speed(speed) {
    _normHP();
    _damage = _damage < 0 ? 0 : _damage;
    _speed = _speed < 0 ? 0 : _speed;
}

SpaceObject::SpaceObject(SpaceObject &spaceObject) {
    *this = spaceObject;
    _normHP();
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

int SpaceObject::getSpeed() const {
    return _speed;
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



