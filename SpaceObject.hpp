#ifndef SPACEOBJECT_HPP
#define SPACEOBJECT_HPP

#include <ostream>

class SpaceObject {
public:
    int getX() const;
    int getY() const;
    int getDamage() const;
    int getHP() const;
    int getMaxHP() const;
    int getSpeed() const;
    virtual SpaceObject &operator=(const SpaceObject &spaceObject);
    SpaceObject &operator+=(int amount);
    SpaceObject &operator-=(int amount);
    void kill();
    virtual void moveUp(int distance);
    virtual void moveLeft(int distance);
    virtual void moveDown(int distance);
    virtual void moveRight(int distance);
protected:
    SpaceObject();
    SpaceObject(SpaceObject &spaceObject);
    SpaceObject(int x, int y, int damage, int hp, int maxHP, int speed);
    virtual ~SpaceObject();
    int _x;
    int _y;
    int _damage;
    int _hp;
    int _maxHP;
    int _speed;
    void _normHP();
};

std::ostream &operator<<(std::ostream &os, const SpaceObject &o);




#endif//SPACEOBJECT_HPP
