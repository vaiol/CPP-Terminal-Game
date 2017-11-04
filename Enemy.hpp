#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SpaceObject.hpp"

class Enemy : SpaceObject {
public:
    Enemy();
    Enemy(int x, int y);
    Enemy(Enemy &enemy);
    Enemy(int x, int y, int hp);
    virtual ~Enemy();
    void moveDown(int distance);
};

std::ostream &operator<<(std::ostream &os, const Enemy &o);


#endif//ENEMY_HPP
