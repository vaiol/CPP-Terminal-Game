#include "SpaceShip.hpp"

#include <iostream>

int main() {
    SpaceShip p(100,100);
    p.move(90, 90);
    SpaceShip pCopy(p);
    p -= 1;
    std::cout << p << std::endl;
    std::cout << pCopy << std::endl;
    std::cout << *pCopy.attack() << std::endl;
}

