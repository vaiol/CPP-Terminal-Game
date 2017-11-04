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
    SpaceShip &operator=(const SpaceShip &player);
    Bullet *attack() const;
    void levelUp();
private:
    int _score;
    int _level;
};

std::ostream &operator<<(std::ostream &os, const SpaceShip &s);

#endif//PLAYER_HPP
