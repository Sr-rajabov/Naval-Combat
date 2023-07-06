//
// Created by sorbo on 03.07.2023.
//

#ifndef NAVAL_COMBAT_BATTLE_H
#define NAVAL_COMBAT_BATTLE_H
#include "Player.h"

void Battle(Battlefield &field, Battlefield &cover_field, Player *player1, Player *player2);

void shootout(Battlefield &field, Battlefield & cover_field, Player *player, bool &check);

bool winner_check(Battlefield &field, Player *player);

void destroy_check(Battlefield &field, Battlefield &cover_field, Player *player);

#endif //NAVAL_COMBAT_BATTLE_H

