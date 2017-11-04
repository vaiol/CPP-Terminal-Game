#include "Bullet.hpp"

Bullet::Bullet() : SpaceObject(0, 0, 0, 1, 1, 4) {}

Bullet::Bullet(const Bullet &bullet) {
    *this = bullet;
}

Bullet::Bullet(int x, int y, int damage) : SpaceObject(x, y, damage, damage, damage, 4) {}

Bullet::~Bullet() {

}
std::ostream &operator<<(std::ostream &os, const Bullet &s) {
    os << "Bullet    => x: " << s.getX() << " y: " << s.getY() << " hp: " << s.getHP();
    return os;
}

void Bullet::moveUp(int distance) {
    SpaceObject::moveUp(distance);
}
