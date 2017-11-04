#include "Enemy.hpp"

Enemy::Enemy() : SpaceObject(0, 0, 0, 2, 2, 1) {}

Enemy::Enemy(int x, int y) : SpaceObject(x, y, 0, 2, 2, 1) {}

Enemy::Enemy(int x, int y, int hp, int speed) : SpaceObject(x, y, 0, hp, hp, speed) {}

Enemy::Enemy(Enemy &enemy) {
    *this = enemy;
}

Enemy::~Enemy() {}

void Enemy::moveDown(int distance) {
    SpaceObject::moveDown(distance);
}




