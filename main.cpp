#include <iostream>
#include <unistd.h>
#include "Ncurs.hpp"
#include "Retro.hpp"
#include "Enemy.hpp"

int main() {

    int game = 1;

    while (game) {
        SpaceShip s(30, 38);
        Ncurs n(120, 70);
        Retro *retro = new Retro(120, 70, s, n);

        long startTime = getTime();
        long time = getTime();
        retro->getNcurs().draw_border();
        while (retro->isPlay()) {
            retro->take_key(getch());
            retro->getNcurs().clearWin();
            retro->draw_objects();
            retro->getNcurs().printStats(retro->getHero(), (int)(getTime() - startTime) / 1000);
            if (getTime() - time >= 100) {
                retro->move_obj();
                time = getTime();
            }
            refresh();
        }
        retro->getNcurs().clearWin();
        retro->getNcurs().finish(retro->getHero().getScore());
        int ch = getch();
        while (ch != 'q' && ch != 'n') {
            ch= getch();
        }
        if (ch == 'q')
            game = 0;
        else
            game = 1;
        delete retro;
    }
    endwin();
    return 0;
}