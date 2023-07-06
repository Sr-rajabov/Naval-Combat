//
// Created by sorbo on 03.07.2023.
//

#include "Checks.h"

bool boundary_check(Battlefield &field, size_t x, size_t y, char direction, size_t size) {
    if (direction == 'r') {
        return x > 0 && x < field.getRows() - 1 && y > 0 && y < field.getRows() - 1 && (y + size - 1) < field.getRows() - 1;
    }
    else if (direction == 'l') {
        return x > 0 && x < field.getRows() - 1 && y > 0 && y < field.getRows() - 1 && (y - size - 1) < field.getRows() - 1;
    }
    else if (direction == 'u') {
        return x > 0 && x < field.getRows() - 1 && y > 0 && y < field.getRows() - 1 && (x - size - 1) < field.getRows() - 1;
    }
    else if (direction == 'd') {
        return x > 0 && x < field.getRows() - 1 && y > 0 && y < field.getRows() - 1 && (x + size - 1) < field.getRows() - 1;
    }
    else {
        return x > 0 && x < field.getRows() - 1 && y > 0 && y < field.getRows() - 1;
    }
}

bool field_check(Battlefield &field, size_t x, size_t y, char direction, size_t size) {
    if (direction == 'r') {
        return field.getField(x, y) != "O" && field.getField(x + 1, y) != "O" && field.getField(x - 1, y) != "O" &&
               field.getField(x, y + 1) != "O" && field.getField(x, y - 1) != "O" && field.getField(x + 1, y + 1) != "O" &&
               field.getField(x - 1, y - 1) != "O" && field.getField(x + 1, y - 1) != "O" && field.getField(x - 1, y + 1) != "O"
               && field.getField(x, y + size) != "O" && field.getField(x + 1, y + size) != "O" && field.getField(x - 1, y + size) != "O" &&
               field.getField(x, y + 1 + size) != "O" && field.getField(x, y - 1 + size) != "O" && field.getField(x + 1, y + 1 + size) != "O" &&
               field.getField(x - 1, y - 1 + size) != "O" && field.getField(x + 1, y - 1 + size) != "O" && field.getField(x - 1, y + 1 + size) != "O";
    }
    else if (direction == 'l') {
        return field.getField(x, y) != "O" && field.getField(x + 1, y) != "O" && field.getField(x - 1, y) != "O" &&
               field.getField(x, y + 1) != "O" && field.getField(x, y - 1) != "O" && field.getField(x + 1, y + 1) != "O" &&
               field.getField(x - 1, y - 1) != "O" && field.getField(x + 1, y - 1) != "O" && field.getField(x - 1, y + 1) != "O"
               && field.getField(x, y - size) != "O" && field.getField(x + 1, y - size) != "O" && field.getField(x - 1, y - size) != "O" &&
               field.getField(x, y + 1 - size) != "O" && field.getField(x, y - 1 - size) != "O" && field.getField(x + 1, y + 1 - size) != "O" &&
               field.getField(x - 1, y - 1 - size) != "O" && field.getField(x + 1, y - 1 - size) != "O" && field.getField(x - 1, y + 1 - size) != "O";
    }
    else if (direction == 'u') {
        return field.getField(x, y) != "O" && field.getField(x + 1, y) != "O" && field.getField(x - 1, y) != "O" &&
               field.getField(x, y + 1) != "O" && field.getField(x, y - 1) != "O" && field.getField(x + 1, y + 1) != "O" &&
               field.getField(x - 1, y - 1) != "O" && field.getField(x + 1, y - 1) != "O" && field.getField(x - 1, y + 1) != "O"
               && field.getField(x - size, y) != "O" && field.getField(x + 1 - size, y) != "O" && field.getField(x - 1 - size, y) != "O" &&
               field.getField(x - size, y + 1) != "O" && field.getField(x - size, y - 1) != "O" && field.getField(x + 1 - size, y + 1) != "O" &&
               field.getField(x - 1 - size, y - 1) != "O" && field.getField(x + 1 - size, y - 1) != "O" && field.getField(x - 1 - size, y + 1) != "O";
    }
    else if (direction == 'd') {
        return field.getField(x, y) != "O" && field.getField(x + 1, y) != "O" && field.getField(x - 1, y) != "O" &&
               field.getField(x, y + 1) != "O" && field.getField(x, y - 1) != "O" && field.getField(x + 1, y + 1) != "O" &&
               field.getField(x - 1, y - 1) != "O" && field.getField(x + 1, y - 1) != "O" && field.getField(x - 1, y + 1) != "O"
               && field.getField(x + size, y) != "O" && field.getField(x + 1 + size, y) != "O" && field.getField(x - 1 + size, y) != "O" &&
               field.getField(x + size, y + 1) != "O" && field.getField(x + size, y - 1) != "O" && field.getField(x + 1 + size, y + 1) != "O" &&
               field.getField(x - 1 + size, y - 1) != "O" && field.getField(x + 1 + size, y - 1) != "O" && field.getField(x - 1 + size, y + 1) != "O";
    }
    else {
        return field.getField(x, y) != "O" && field.getField(x + 1, y) != "O" && field.getField(x - 1, y) != "O" &&
               field.getField(x, y + 1) != "O" && field.getField(x, y - 1) != "O" &&
               field.getField(x + 1, y + 1) != "O" &&
               field.getField(x - 1, y - 1) != "O" && field.getField(x + 1, y - 1) != "O" &&
               field.getField(x - 1, y + 1) != "O";
    }
}

bool hit_check_up(Battlefield &field, size_t x, size_t y) {
    return field.getField(x, y) == "O";
}

