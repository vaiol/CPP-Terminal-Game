//
// Created by ysavenko on 04.11.17.
//

#ifndef NCURS_HPP
#define NCURS_HPP

#include <ncurses.h>
#include "SpaceShip.hpp"

class Ncurs {
public:
    Ncurs();
    Ncurs(int x, int y);
    Ncurs(Ncurs const &src);
    ~Ncurs();
    Ncurs &operator=(Ncurs const &src);
    void draw_obj(SpaceObject obj) const;
    void clearWin() const;
    void finish(int score) const;
    void printStats(const SpaceShip &hero, int time) const;
    void draw_border() const;
private:
    void _initColors();
    int _xSize;
    int _ySize;
};


#endif //NCURS_HPP
