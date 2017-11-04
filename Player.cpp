#include "Player.hpp"

/*CONSTRUCTORS AND DESTRUCTOR*/

Player::Player() : SpaceObject(0, 0, 1, 100, 100) {
    _score = 0;
    _level = 1;
}

Player::Player(int x, int y) : SpaceObject(x, y, 1, 100, 100) {
    _score = 0;
    _level = 1;
}

Player::Player(Player &player) {
    *this = player;
}

Player::~Player() {}

/*GETTERS*/

int Player::getLevel() const {
    return _level;
}

int Player::getScore() const {
    return _score;
}

/*OPERATORS*/

Player &Player::operator=(const Player &player) {
    SpaceObject::operator = (player);
    _score = player._score;
    _level = player._level;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Player => x: " << player.getX() << " y: " << player.getY() << " damage: " << player.getDamage() << " hp: " << player.getHP()
       << " maxHP: " << player.getMaxHP() << " score: " << player.getScore() << " level: " << player.getLevel();
    return os;
}

/*LOGIC*/

void Player::attack() const {
    //Generate Bullet
}

void Player::levelUp() {
    _damage += _level;
    _level++;
}

