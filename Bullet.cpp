#include "Bullet.hpp"

Bullet::Bullet() : SpaceObject(0, 0, 0, 0, 0) {}

Bullet::Bullet(const Bullet &bullet) {
    *this = bullet;
}

Bullet::Bullet(int x, int y, int damage) : SpaceObject(x, y, damage, damage, damage) {}

Bullet::~Bullet() {

}
std::ostream &operator<<(std::ostream &os, const Bullet &s) {
    os << "Bullet    => x: " << s.getX() << " y: " << s.getY() << " hp: " << s.getHP();
    return os;
}

void Bullet::moveUp(int amount) {
    SpaceObject::move(_x, _y += amount);
}