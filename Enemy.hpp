#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SpaceObject.hpp"

class Enemy : public SpaceObject {
public:
    Enemy();
    Enemy(int x, int y);
    Enemy(Enemy &enemy);
    Enemy(int x, int y, int hp);
    Enemy(int x, int y, int hp, char c, int color);
    virtual ~Enemy();
    void moveDown(int distance);
};

std::ostream &operator<<(std::ostream &os, const Enemy &o);


#endif//ENEMY_HPP
