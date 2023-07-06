//
// Created by sorbo on 03.07.2023.
//

#ifndef NAVAL_COMBAT_PLAYER_H
#define NAVAL_COMBAT_PLAYER_H
#include "Ship.h"
#include "limits"
#include "Game tools.h"
#include "Checks.h"

class Player {
public:
    explicit Player();
    ~Player();
    string getName() const;
    int getPlayerNum() const;
    void deploy(Battlefield &field, size_t num_of_ships, size_t i);
    Ship getShip(size_t i) const;
    Ship *erase_ship(size_t position);
    size_t get_arr_size() const;
    Ship *push_back(const Ship* ship);
private:
    string Name;
    static int num;
    int playerNum;
    size_t arr_size;
    Ship *ship_arr;
};

#endif //NAVAL_COMBAT_PLAYER_H
