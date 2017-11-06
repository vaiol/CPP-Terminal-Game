//
// Created by ysavenko on 04.11.17.
//

#ifndef RETRO_HPP
#define RETRO_HPP

#include "Ncurs.hpp"
#include "Enemy.hpp"
#include "SpaceShip.hpp"

class Retro {
public:
    Retro(int x, int y, SpaceShip &ship, Ncurs &ncurs);
    Retro();
    ~Retro();
    Retro &operator=(Retro const&retro);
    Retro(Retro const&retro);

    void take_key(int key);
    void move_obj();
    void draw_objects();
    const Ncurs &getNcurs() const;
    const SpaceShip &getHero() const;
    int isPlay() const;

private:
    void _addBullet(Bullet *bullet);
    void _clearObj();
    void _Generator();
    void _checkCollision();
    void _generateObstacle();
    void _generateObstacle2();
    void _generateLevelUp();
    int _eof_score;
    int _currentLevel;
    int _xSize;
    int _ySize;
    Ncurs _ncurs;
    int _play;
    int _bCount;
    int _eCount;
    Enemy *_enemies;
    SpaceShip _hero;
    Bullet *_bulets;
    int _wall;
};

long getTime();
#endif //RETRO_HPP
