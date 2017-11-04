#ifndef SPACEOBJECT_HPP
#define SPACEOBJECT_HPP


#include <ostream>

class SpaceObject {
public:
    SpaceObject();
    SpaceObject(SpaceObject &spaceObject);
    SpaceObject(int _x, int _y, int _damage, int _hp, int _maxHP);
    virtual ~SpaceObject();
    int getX() const;
    int getY() const;
    int getDamage() const;
    int getHP() const;
    int getMaxHP() const;
    virtual SpaceObject &operator=(const SpaceObject &spaceObject);
    SpaceObject &operator+=(int amount);
    SpaceObject &operator-=(int amount);
    void move(int x, int y);
protected:
    int _x;
    int _y;
    int _damage;
    int _hp;
    int _maxHP;
};

std::ostream &operator<<(std::ostream &os, const SpaceObject &object);




#endif//SPACEOBJECT_HPP
