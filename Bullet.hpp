#ifndef BULLET_HPP
#define BULLET_HPP

#include "SpaceObject.hpp"

class Bullet : public SpaceObject {
public:
    Bullet();
    Bullet(int x, int y, int damage);
    Bullet(int x, int y, int damage, char c);
    Bullet(const Bullet &bullet);
    virtual ~Bullet();
    void moveUp();
    static bool collision(const Bullet &a, const SpaceObject &b);
    Bullet &operator=(const Bullet &bullet);
private:
    int _speed;
};

std::ostream &operator<<(std::ostream &os, const Bullet &b);

#endif//BULLET_HPP


