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
    char getC() const;
    int getColor() const;
    virtual SpaceObject &operator=(const SpaceObject &spaceObject);
    SpaceObject &operator+=(int amount);
    SpaceObject &operator-=(int amount);
    static bool collision(const SpaceObject &a, const SpaceObject &b);
    SpaceObject();
    SpaceObject(SpaceObject &spaceObject);
    SpaceObject(int x, int y, int damage, int hp, int maxHP, char c, int color);
    virtual ~SpaceObject();
protected:
    int _x;
    int _y;
    int _damage;
    int _hp;
    int _maxHP;
    char _c;
    int _color;
    void _normHP();
};

std::ostream &operator<<(std::ostream &os, const SpaceObject &o);




#endif//SPACEOBJECT_HPP
