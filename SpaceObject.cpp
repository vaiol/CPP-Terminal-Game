#include "SpaceObject.hpp"

/*CONSTRUCTORS AND DESTRUCTOR*/

SpaceObject::SpaceObject() {
    _x = 0;
    _y = 0;
    _damage = 0;
    _maxHP = 0;
    _hp = _maxHP;
    _color = 0;
}

SpaceObject::SpaceObject(int x, int y, int damage, int hp, int maxHP, char c, int color) : _x(x), _y(y), _damage(damage), _hp(hp),
                                                                             _maxHP(maxHP), _c(c), _color(color) {}

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

char SpaceObject::getC() const {
    return  this->_c;
}

int SpaceObject::getColor() const {
    return _color;
}

SpaceObject &SpaceObject::operator=(const SpaceObject &spaceObject) {
    _x = spaceObject._x;
    _y = spaceObject._y;
    _damage = spaceObject._damage;
    _hp = spaceObject._hp;
    _maxHP = spaceObject._maxHP;
    _c = spaceObject._c;
    _color = spaceObject._color;
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
       << " maxHP: " << o.getMaxHP() << " c: " << o.getC() << " color: " << o.getColor();
    return os;
}

/*LOGIC*/

void SpaceObject::_normHP() {
    if (_hp < 0) {
        _hp = 0;
    }
    if (_hp > _maxHP) {
        _hp = _maxHP;
    }
}


bool SpaceObject::collision(const SpaceObject &a, const SpaceObject &b) {
    if (&a == &b) {
        return true;
    }
    if (a._x == b._x && a._y == b._y) {
        return true;
    }
    return false;
}


