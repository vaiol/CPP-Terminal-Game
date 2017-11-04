#include "Enemy.hpp"

Enemy::Enemy() : SpaceObject(0, 0, 0, 2, 2) {}

Enemy::Enemy(int x, int y) : SpaceObject(x, y, 0, 2, 2) {}

Enemy::Enemy(int x, int y, int hp) : SpaceObject(x, y, 0, hp, hp) {}

Enemy::Enemy(Enemy &enemy) {
    *this = enemy;
}

Enemy::~Enemy() {}

void Enemy::moveDown(int distance) {
    SpaceObject::moveDown(distance);
}




