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
    return *this;
}

SpaceObject &SpaceObject::operator-=(int amount) {
    _hp -= amount;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const SpaceObject &o) {
    os << "SpaceObject => x: " << o.getX() << " y: " << o.getY() << " damage: " << o.getDamage() << " hp: " << o.getHP()
       << " maxHP: " << o.getMaxHP();
    return os;
}

/*LOGIC*/

void SpaceObject::move(int x, int y) {
    _x = x;
    _y = y;
}


