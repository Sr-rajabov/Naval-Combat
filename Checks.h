//
// Created by sorbo on 03.07.2023.
//

#ifndef NAVAL_COMBAT_CHECKS_H
#define NAVAL_COMBAT_CHECKS_H
#include "Player.h"
bool boundary_check(Battlefield &field, size_t x, size_t y, char direction, size_t size);

bool field_check(Battlefield &field, size_t x, size_t y, char direction, size_t size);

bool hit_check_up(Battlefield &field, size_t x, size_t y);

#endif //NAVAL_COMBAT_CHECKS_H
