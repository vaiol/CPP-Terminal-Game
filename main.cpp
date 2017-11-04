#include "SpaceShip.hpp"

#include <iostream>

int main() {
    SpaceShip p(100,100);
    p.moveUp(1);
    SpaceShip pCopy(p);
    p -= 10;
    std::cout << p << std::endl;
    std::cout << pCopy << std::endl;
    std::cout << *pCopy.attack()->moveUp() << std::endl;
}

