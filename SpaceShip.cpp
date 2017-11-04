#include "SpaceShip.hpp"

/*CONSTRUCTORS AND DESTRUCTOR*/

SpaceShip::SpaceShip() : SpaceObject(0, 0, 1, 100, 100) {
    _score = 0;
    _level = 1;
}

SpaceShip::SpaceShip(int x, int y) : SpaceObject(x, y, 1, 100, 100) {
    _score = 0;
    _level = 1;
}

SpaceShip::SpaceShip(SpaceShip &player) {
    *this = player;
}

SpaceShip::~SpaceShip() {}

/*GETTERS*/

int SpaceShip::getLevel() const {
    return _level;
}

int SpaceShip::getScore() const {
    return _score;
}

/*OPERATORS*/

SpaceShip &SpaceShip::operator=(const SpaceShip &player) {
    SpaceObject::operator = (player);
    _score = player._score;
    _level = player._level;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const SpaceShip &s) {
    os << "SpaceShip => x: " << s.getX() << " y: " << s.getY() << " damage: " << s.getDamage() << " hp: " << s.getHP()
       << " maxHP: " << s.getMaxHP() << " score: " << s.getScore() << " level: " << s.getLevel();
    return os;
}

/*LOGIC*/

Bullet *SpaceShip::attack() const {
    return new Bullet(_x, _y + 1, _damage);
}

void SpaceShip::levelUp() {
    _damage += _level;
    _level++;
}

