#include "Player.hpp"

#include <iostream>

int main() {
    Player p(100,100);
    p.move(90, 90);
    Player pCopy(p);
    std::cout << p << std::endl;
    std::cout << pCopy << std::endl;
}

