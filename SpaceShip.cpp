#include "SpaceShip.hpp"

/*CONSTRUCTORS AND DESTRUCTOR*/


SpaceShip::SpaceShip() : SpaceObject(0, 0, 1, 20, 20, 'W', 4) {

    _score = 0;
    _level = 1;
    _maxScore = 10;
}


SpaceShip::SpaceShip(int x, int y) : SpaceObject(x, y, 1, 20, 20, 'W', 4) {
    _score = 0;
    _level = 1;
    _maxScore = 10;
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

int SpaceShip::getMaxScore() const {
    return _maxScore;
}

/*OPERATORS*/

SpaceShip &SpaceShip::operator=(const SpaceShip &player) {
    SpaceObject::operator = (player);
    _score = player._score;
    _level = player._level;
    _maxScore = player._maxScore;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const SpaceShip &s) {
    os << "SpaceShip => x: " << s.getX() << " y: " << s.getY() << " damage: " << s.getDamage() << " hp: " << s.getHP()
       << " maxHP: " << s.getMaxHP() << " score: " << s.getScore() << " level: " << s.getLevel();
    return os;
}

/*LOGIC*/

Bullet *SpaceShip::attack() const {
    return new Bullet(this->_x, this->_y - 1, _damage);
}

Bullet *SpaceShip::superAttack() const {
    return new Bullet(this->_x, this->_y - 1, _damage * 80, '*');
}

void SpaceShip::levelUp() {
    _maxHP += 10;
    _hp = _maxHP;
    _damage += _level;
    _level++;
    _maxScore *= 5;
}

void SpaceShip::move(int x, int y, int x_m, int y_m) {
    if (x_m)
    {
        if (this->_x + x_m > 0 && this->_x + x_m < x+2)
            this->_x += x_m;
    }
    if (y_m)
    {
        if (this->_y + y_m > 15 && this->_y + y_m < y+2)
            this->_y += y_m;
    }
}

void SpaceShip::increaseScore(int amount) {
    _score += amount;
    if (_score >= _maxScore) {
        levelUp();
    }
}