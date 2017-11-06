#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SpaceObject.hpp"
#include "Bullet.hpp"
#include <ostream>

class SpaceShip : public SpaceObject {
public:
    SpaceShip();
    SpaceShip(int x, int y);
    SpaceShip(SpaceShip &player);
    virtual ~SpaceShip();
    int getScore() const;
    int getLevel() const;
    int getMaxScore() const;
    SpaceShip &operator=(const SpaceShip &player);
    Bullet *attack() const;
    Bullet *superAttack() const;
    void levelUp();
    void move(int x, int y, int x_m, int y_m);
    void increaseScore(int amount);
private:
    int _score;
    int _level;
    int _maxScore;
};

std::ostream &operator<<(std::ostream &os, const SpaceShip &s);

#endif//PLAYER_HPP
