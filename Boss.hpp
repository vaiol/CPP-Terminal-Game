#ifndef BOSS_HPP
#define BOSS_HPP


#include "SpaceObject.hpp"

class Boss : public SpaceObject {
public:
    Boss();
    Boss(int x, int y);
    Boss(Boss &boss);
    Boss(int x, int y, int hp, int size);
    virtual ~Boss();
    void moveLeft(int distance);
    int getSize() const;
    void moveRight(int distance);
private:
    int _size;
};


#endif//BOSS_HPP
