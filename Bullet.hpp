#ifndef BULLET_HPP
#define BULLET_HPP

#include "SpaceObject.hpp"

class Bullet : public SpaceObject {
public:
    Bullet();
    Bullet(int x, int y, int damage);
    Bullet(const Bullet &bullet);
    virtual ~Bullet();
    void moveUp(int distance);
};

std::ostream &operator<<(std::ostream &os, const Bullet &b);


#endif//BULLET_HPP


