#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SpaceObject.hpp"
#include <ostream>

class Player : public SpaceObject {
public:
    Player();
    Player(int x, int y);
    Player(Player &player);
    virtual ~Player();
    int getScore() const;
    int getLevel() const;
    Player &operator=(const Player &player);
    void attack() const;
    void levelUp();
private:
    int _score;
    int _level;
};

std::ostream &operator<<(std::ostream &os, const Player &player);

#endif//PLAYER_HPP
