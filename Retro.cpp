//
// Created by ysavenko on 04.11.17.
//
#include <sys/time.h>
#include "Retro.hpp"
#include <iostream>

void Retro::take_key(int key) {
    static long time;
    if (key == 27)
        this->_play = 0;
    else if (key == 97)
        this->_hero.move(this->_xSize, this->_ySize, -1, 0);
    else if (key == 100)
        this->_hero.move(this->_xSize, this->_ySize, 1, 0);
    else if (key == 119)
        this->_hero.move(this->_xSize, this->_ySize, 0, -1);
    else if (key == 115)
        this->_hero.move(this->_xSize, this->_ySize, 0, 1);
    else if (key == 32) {
        _addBullet(this->_hero.attack());
    }
    else if (key == 122) {
        if (getTime() - time >= 1000) {
            _addBullet(this->_hero.superAttack());
            time = getTime();
        }
    }
}

void Retro::_checkCollision() {
    for (int i = 0; i < _eCount; i++) {
        if (SpaceObject::collision(_hero, _enemies[i])) {
            _hero -= _enemies[i].getDamage();
            _enemies[i] -= _hero.getDamage() * 1000;
            if (!_hero.getHP()) {
                _play = 0;
            }
            if (!_enemies[i].getHP()) {
                _hero.increaseScore(_enemies[i].getMaxHP());
            }
        }
    }
    for (int i = 0; i < _eCount; i++) {
        for (int j = 0; j < _bCount; j++) {
            if (Bullet::collision(_bulets[j], _enemies[i])) {
                _bulets[j] -= _enemies[i].getDamage();
                _enemies[i] -= _bulets[j].getDamage();
                if (!_enemies[i].getHP()) {
                    _hero.increaseScore(_enemies[i].getMaxHP());
                }
            }
        }
    }

}

Retro::Retro(int x, int y, SpaceShip &ship, Ncurs &ncurs) {
    this->_ncurs = ncurs;
    this->_hero = ship;
    std::srand((unsigned)time(NULL));
    this->_xSize = x;
    this->_ySize = y;
    this->_play = 1;
    this->_bCount = 0;
    this->_eCount = 0;
    this->_enemies = new Enemy[this->_ySize * this->_xSize];
    this->_bulets = new Bullet[this->_ySize];
    this->_wall = 0;
    _eof_score = 20000;
    _currentLevel = 1;
}
Retro::Retro() {
    std::srand((unsigned)time(NULL));
    this->_xSize = 60;
    this->_ySize = 50;
    this->_play = 1;
    this->_bCount = 0;
    this->_eCount = 0;
    this->_enemies = new Enemy[this->_ySize * this->_xSize];
    this->_bulets = new Bullet[this->_ySize];
    this->_wall = 0;
    _eof_score = 20000;
    _currentLevel = 1;
}
Retro::~Retro() {
    std::srand((unsigned)time(NULL));

}
Retro& Retro::operator=(Retro const &retro) {
    this->_ySize = retro._ySize;
    this->_xSize = retro._xSize;
    this->_play = retro._play;
    this->_ncurs = retro._ncurs;
    this->_bCount = retro._bCount;
    this->_enemies = retro._enemies;
    this->_bulets = retro._bulets;
    this->_eCount = retro._eCount;
    return *this;
}

Retro::Retro(Retro const &retro) {
    *this = retro;
}

void Retro::move_obj() {
    int a = 0;
    while (a < _bCount)
    {
        _bulets[a].moveUp();
        a++;
    }
    a = 0;
    while (a < _eCount)
    {
        _enemies[a].moveDown(this->_ySize);
        a++;
    }
    _Generator();
}

void Retro::draw_objects() {
    _ncurs.draw_obj(this->_hero);
    int a = 0;
    while (a < _bCount)
    {
        _ncurs.draw_obj(_bulets[a]);
        a++;
    }
    a = 0;
    while (a < _eCount)
    {
        if(_enemies[a].getHP())
            _ncurs.draw_obj(_enemies[a]);
        a++;
    }
    _checkCollision();
    _clearObj();
}

long getTime()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    return ms;
}

void Retro::_addBullet(Bullet *bullet) {
    if (_bCount && this->_bulets[_bCount - 1].getX() == bullet->getX() && this->_bulets[_bCount - 1].getY() == bullet->getY()) {
        return;
    }
    this->_bulets[_bCount++] = *bullet;
    delete bullet;
}


void Retro::_clearObj() {
    int a = _bCount - 1;
    while (a >= 0)
    {
        if (_bulets[a].getHP() == 0)
        {
            if (a == _bCount - 1)
                _bCount--;
            else
            {
                _bulets[a] = _bulets[_bCount - 1];
                _bCount--;
            }
        }
        a--;
    }
    a = _eCount - 1;
    while (a >= 0)
    {
        if (_enemies[a].getHP() == 0)
        {
            if (a == _eCount - 1)
                _eCount--;
            else
            {
                _enemies[a] = _enemies[_eCount - 1];
                _eCount--;
            }
        }
        a--;
    }
}

void Retro::_Generator() {
    if (!_wall && this->_hero.getScore() >= _eof_score)
    {
        _wall = 1;
        int a = 1;
        while (a < this->_xSize)
        {
            _enemies[_eCount++] = Enemy(a, 1,10000);
            a++;
        }
    }
    else {
        int part1Max = (this->_xSize / 2 - 1);
        int a = (rand() % part1Max) + 1;
        int b = (rand() % part1Max) + _xSize / 2;
        _enemies[_eCount++] = Enemy(a, 1);
        _enemies[_eCount++] = Enemy(b, 1);
    }
    _generateLevelUp();
    if (_hero.getLevel() > 4)
        _generateObstacle();
    if (_hero.getLevel() > 5) {
        _generateObstacle();
        _generateObstacle();
    }
    _generateObstacle();
    _generateObstacle2();
}

void Retro::_generateLevelUp() {
    if (_hero.getLevel() != _currentLevel) {
        _currentLevel = _hero.getLevel();
        int a = (rand() % (this->_xSize - 8)) + 8;
        _enemies[_eCount++] = Enemy(a-7, 1, _hero.getHP(), 'L', 5);
        _enemies[_eCount++] = Enemy(a-6, 1, _hero.getHP(), 'E', 5);
        _enemies[_eCount++] = Enemy(a-5, 1, _hero.getHP(), 'V', 5);
        _enemies[_eCount++] = Enemy(a-4, 1, _hero.getHP(), 'E', 5);
        _enemies[_eCount++] = Enemy(a-3, 1, _hero.getHP(), 'L', 5);
        _enemies[_eCount++] = Enemy(a-1, 1, _hero.getHP(), (char)_hero.getLevel() + '0', 5);
    }
}



void Retro::_generateObstacle() {
    if (_hero.getLevel() < 2)  {
        return;
    }
    int a = (rand() % (this->_xSize - 2)) + 2;
    int hp = (int)(30 * (_hero.getLevel()) * 2.1);
    _enemies[_eCount++] = Enemy(a-1, 1, hp);
    _enemies[_eCount++] = Enemy(a-1, 2, hp);
    _enemies[_eCount++] = Enemy(a, 1, hp);
    _enemies[_eCount++] = Enemy(a, 2, hp);
};

void Retro::_generateObstacle2() {
    if (_hero.getLevel() < 3)  {
        return;
    }
    static long time;
    if (getTime() - time >= (3000 / _hero.getLevel()) || _hero.getLevel() > 5) {
        int a = (rand() % (this->_xSize - 3)) + 3;
        int hp = (int)((100 * (_hero.getLevel()) * 2.1));
        _enemies[_eCount++] = Enemy(a, 1, hp, 'o', 6);
        _enemies[_eCount++] = Enemy(a, 2, hp, 'o', 6);
        _enemies[_eCount++] = Enemy(a, 3, hp, 'o', 6);
        _enemies[_eCount++] = Enemy(a-1, 2, hp, 'o', 6);
        _enemies[_eCount++] = Enemy(a+1, 2, hp, 'o', 6);
        time = getTime();
    }
}

const Ncurs &Retro::getNcurs() const {
    return _ncurs;
}

int Retro::isPlay() const {
    return _play;
}

const SpaceShip &Retro::getHero() const {
    return _hero;
};

