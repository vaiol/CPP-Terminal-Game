#include "Bullet.hpp"

Bullet::Bullet() : SpaceObject(0, 0, 0, 0, 0, '.', 0) {
    _speed = 2;
}

Bullet::Bullet(const Bullet &bullet) {
    *this = bullet;
    _speed = 2;
}

Bullet::Bullet(int x, int y, int damage) : SpaceObject(x, y, damage, damage, damage, '.', 0) {
    _speed = 2;
}

Bullet::Bullet(int x, int y, int damage, char c) : SpaceObject(x, y, damage, damage, damage, c, 7) {
    _speed = 2;
}

Bullet::~Bullet() {

}

std::ostream &operator<<(std::ostream &os, const Bullet &s) {
    os << "Bullet    => x: " << s.getX() << " y: " << s.getY() << " hp: " << s.getHP();
    return os;
}

void Bullet::moveUp() {
    if (this->_y <= _speed)
        this->_hp = 0;
    else
        this->_y -= _speed;
}

bool Bullet::collision(const Bullet &a, const SpaceObject &b) {
    if (&a == &b) {
        return true;
    }
    if (!a._hp || !b.getHP()) {
        return false;
    }
    for (int i = 0; i <= a._speed; i++) {
        if (a._x == b.getX() && a._y - i == b.getY()) {
            return true;
        }
    }
    return false;
}

Bullet &Bullet::operator=(const Bullet &bullet) {
    SpaceObject::operator = (bullet);
    _speed = bullet._speed;
    return *this;
}
