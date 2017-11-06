#include "Enemy.hpp"

Enemy::Enemy() : SpaceObject(1, 1, 2, 2, 2, 'x', 0) {}

Enemy::Enemy(int x, int y) : SpaceObject(x, y, 2, 2, 2, 'x', 0) {}

Enemy::Enemy(int x, int y, int hp) : SpaceObject(x, y, hp, hp, hp, 'o', 3) {}

Enemy::Enemy(int x, int y, int hp, char c, int color) : SpaceObject(x, y, hp, hp, hp, c, color) {}

Enemy::Enemy(Enemy &enemy) {
    *this = enemy;
}

Enemy::~Enemy() {}

void Enemy::moveDown(int distance) {
    if (this->_y == distance + 1)
        this->_hp = 0;
    else
        this->_y += 1;
}

std::ostream &operator<<(std::ostream &os, const Enemy &s) {
    os << "Enemy    => x: " << s.getX() << " y: " << s.getY() << " hp: " << s.getHP();
    return os;
}




