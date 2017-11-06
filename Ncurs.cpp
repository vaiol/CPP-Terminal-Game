//
// Created by ysavenko on 04.11.17.
//

#include "Ncurs.hpp"

Ncurs::Ncurs(int x, int y) {
    this->_xSize = x;
    this->_ySize = y;
    initscr();
    cbreak();
    start_color();
    curs_set(0);
    _initColors();
    wbkgd(stdscr, COLOR_PAIR(1));
    noecho();
    nodelay(stdscr, TRUE);
}
Ncurs::Ncurs() {
    this->_xSize = 120;
    this->_ySize = 70;
    initscr();
    cbreak();
    start_color();
    _initColors();
    wbkgd(stdscr, COLOR_PAIR(1));
    noecho();
    nodelay(stdscr, TRUE);
}
Ncurs::~Ncurs() {

}
Ncurs& Ncurs::operator=(Ncurs const &src) {
    this->_ySize = src._ySize;
    this->_xSize = src._xSize;
    return *this;
}
Ncurs::Ncurs(Ncurs const &src) {
    *this = src;
}

void Ncurs::draw_border() const {
   attron(COLOR_PAIR(2));
    mvwhline(stdscr, 0, 0, ' ', this->_xSize + 2);
    mvwhline(stdscr, this->_ySize + 2, 0, ' ', this->_xSize + 2);
    mvwvline(stdscr, 0, 0, ' ', this->_ySize + 2);
    mvwvline(stdscr, 0, this->_xSize + 2, ' ', this->_ySize + 2);
    mvwhline(stdscr, 0, this->_xSize + 3, ' ', 30);
    mvwhline(stdscr, 25, this->_xSize + 3, ' ', 30);
    mvwvline(stdscr, 0, this->_xSize + 33, ' ', 26);
    mvwaddch(stdscr, this->_ySize + 2, this->_xSize + 2, ' ');
    attroff(COLOR_PAIR(2));
}

void Ncurs::draw_obj(SpaceObject obj) const {
    attron(COLOR_PAIR(obj.getColor()));
    mvwaddch(stdscr, obj.getY(), obj.getX(), obj.getC());
    attroff(COLOR_PAIR(obj.getColor()));
}
void Ncurs::_initColors() {
    init_pair(1, COLOR_WHITE, COLOR_BLUE);  // Background
    init_pair(2, 0, 1);                     // Border
    init_pair(3, COLOR_RED, COLOR_BLUE);            // Obstacle
    init_pair(4, COLOR_MAGENTA, 12);            // SpaceShip
    init_pair(5, COLOR_BLACK, COLOR_YELLOW);                //Level
    init_pair(6, COLOR_GREEN, 12);                //Obstacle lvl 3
    init_pair(7, COLOR_BLACK, COLOR_BLUE);                //Bomb
}
void Ncurs::clearWin() const {
    int a = 1;
    while (a < _xSize + 2)
    {
        int b = 1;
        while (b < _ySize + 2)
        {
            mvwaddch(stdscr, b, a, ' ');
            b++;
        }
        a++;
    }
}

void Ncurs::printStats(const SpaceShip &hero, int time) const {
    mvwprintw(stdscr, 5,  this->_xSize + 5, "Player hp       %d   ", hero.getHP());
    mvwprintw(stdscr, 7,  this->_xSize + 5, "Score           %d   ", hero.getScore());
    mvwprintw(stdscr, 15,  this->_xSize + 5, "Time in game    %d sec", time);
    mvwprintw(stdscr, 9, this->_xSize + 5, "Level           %d ",  hero.getLevel());
    mvwprintw(stdscr, 13, this->_xSize + 5, "Current damage  %d ", hero.getDamage());
    mvwprintw(stdscr, 11, this->_xSize + 5, "Points to next  %d ", hero.getMaxScore() - hero.getScore());
}

void Ncurs::finish(int score) const {
    attron(COLOR_PAIR(7));
    mvwprintw(stdscr, 25, this->_xSize/2 - 5, "Game over");
    mvwprintw(stdscr, 26, this->_xSize/2 - 5, "your score %d", score);
    mvwprintw(stdscr, 27, this->_xSize/2 - 5, "press 'q' to exit");
    mvwprintw(stdscr, 28, this->_xSize/2 - 5, "or start next 'n' ");
    mvwprintw(stdscr, this->_ySize - 3, this->_xSize/3, "astepano");
    mvwprintw(stdscr, this->_ySize - 3, this->_xSize * 2/3, "ysavenko");
    attroff(COLOR_PAIR(7));
}