//
// Created by sorbo on 03.07.2023.
//

#include "Battle.h"

void Battle(Battlefield &field, Battlefield &cover_field, Player *player1, Player *player2) {
    bool check = true;
    shootout(field, cover_field, player1, check);
    if (!check) return;
    shootout(field, cover_field, player2, check);
    if (!check) return;
    Battle(field, cover_field, player1, player2);
}

bool winner_check(Battlefield &field, Player *player) {
    if (player->getPlayerNum() == 2) {
        for (size_t i = 1; i < field.getRows() - 2; ++i) {
            for (size_t j = 1; j < field.getRows() - 2; ++j) {
                if (field.getField(i, j) == "O") return false;
            }
        }
    }
    else {
        for (size_t i = 1; i < field.getRows() - 2; ++i) {
            for (size_t j = field.getCols() - 11; j < field.getCols() - 1; ++j) {
                if (field.getField(i, j) == "O") return false;
            }
        }
    }
    return true;
}

void destroy_check(Battlefield &field, Battlefield &cover_field, Player *player) {
    for (size_t i = 0; i < player->get_arr_size(); ++i) {
        bool check = true;
        for (size_t j = 0; j < player->getShip(i).get_arr_size(); j += 2) {
            size_t x = player->getShip(i).get_coordinates(j);
            size_t y = player->getShip(i).get_coordinates(j + 1);
            if (player->getPlayerNum() == 1) {
                if (field.getField(x, y + field.getRows()) == "O") {
                    check = false;
                    break;
                }
            }
            else {
                if (field.getField(x, y) == "O") {
                    check = false;
                    break;
                }
            }
        }
        if (check) {
            cout << "Target destroyed!\n";
            size_t x = player->getShip(i).get_coordinates(0);
            size_t y = player->getShip(i).get_coordinates(1);
            size_t x1 = player->getShip(i).get_coordinates(player->getShip(i).get_arr_size() - 2);
            size_t y1 = player->getShip(i).get_coordinates(player->getShip(i).get_arr_size() - 1);
            if (player->getPlayerNum() == 1) {
                y += field.getRows();
                y1 += field.getRows();
            }
            if (field.getField(x + 1, y) == "~") {
                cover_field.setField(x + 1, y, ".");
                field.setField(x + 1, y, ".");
            }
            if (field.getField(x - 1, y) == "~"){
                cover_field.setField(x - 1, y, ".");
                field.setField(x - 1, y, ".");
            }
            if (field.getField(x, y + 1) == "~") {
                cover_field.setField(x, y + 1, ".");
                field.setField(x, y + 1, ".");
            }
            if (field.getField(x, y - 1) == "~") {
                cover_field.setField(x, y - 1, ".");
                field.setField(x, y - 1, ".");
            }
            if (field.getField(x + 1, y + 1) == "~") {
                cover_field.setField(x + 1, y + 1, ".");
                field.setField(x + 1, y + 1, ".");
            }
            if (field.getField(x + 1, y - 1) == "~") {
                cover_field.setField(x + 1, y - 1, ".");
                field.setField(x + 1, y - 1, ".");
            }
            if (field.getField(x - 1, y + 1) == "~") {
                cover_field.setField(x - 1, y + 1, ".");
                field.setField(x - 1, y + 1, ".");
            }
            if (field.getField(x - 1, y - 1) == "~") {
                cover_field.setField(x - 1, y - 1, ".");
                field.setField(x - 1, y - 1, ".");
            }
            if (player->getShip(i).getsize() > 1) {
                if (field.getField(x1 + 1, y1) == "~") {
                    cover_field.setField(x1 + 1, y1, ".");
                    field.setField(x1 + 1, y1, ".");
                }
                if (field.getField(x1 - 1, y1) == "~") {
                    cover_field.setField(x1 - 1, y1, ".");
                    field.setField(x1 - 1, y1, ".");
                }
                if (field.getField(x1, y1 + 1) == "~") {
                    cover_field.setField(x1, y1 + 1, ".");
                    field.setField(x1, y1 + 1, ".");
                }
                if (field.getField(x1, y1 - 1) == "~") {
                    cover_field.setField(x1, y1 - 1, ".");
                    field.setField(x1, y1 - 1, ".");
                }
                if (field.getField(x1 + 1, y1 + 1) == "~") {
                    cover_field.setField(x1 + 1, y1 + 1, ".");
                    field.setField(x1 + 1, y1 + 1, ".");
                }
                if (field.getField(x1 + 1, y1 - 1) == "~") {
                    cover_field.setField(x1 + 1, y1 - 1, ".");
                    field.setField(x1 + 1, y1 - 1, ".");
                }
                if (field.getField(x1 - 1, y1 + 1) == "~") {
                    cover_field.setField(x1 - 1, y1 + 1, ".");
                    field.setField(x1 - 1, y1 + 1, ".");
                }
                if (field.getField(x1 - 1, y1 - 1) == "~") {
                    cover_field.setField(x1 - 1, y1 - 1, ".");
                    field.setField(x1 - 1, y1 - 1, ".");
                }
            }
            player->erase_ship(i);
            cover_field.print();
            return;
        }
    }
}

void shootout(Battlefield &field, Battlefield & cover_field, Player *player, bool &check) {
    size_t x, y;
    cout << player->getName() << " your turn to shoot!\n"
                                 "Enter the coordinates!\n";
    while (true) {
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Wrong coordinates, try again!\n";
            cover_field.print();
            continue;
        }
        break;
    }
    if (player->getPlayerNum() == 2) {
        if (field.getField(x, y) == "X" || field.getField(x, y) == ".") {
            cout << "Wrong coordinates, try again!\n";
            cover_field.print();
            shootout(field, cover_field, player, check);
        }
        else if (hit_check_up(field, x, y)) {
            cout << "Hit\n";
            cover_field.setField(x, y, "X");
            field.setField(x, y, "X");
            destroy_check(field, cover_field, player);
            cover_field.print();
            if (winner_check(field, player)) {
                cout << player->getName() << " win!\n";
                check = false;
                return;
            }
            shootout(field, cover_field, player, check);
        } else {
            cout << "Miss!\n";
            cover_field.setField(x, y, "X");
            field.setField(x, y, "X");
            cover_field.print();
            return;
        }
    }
    else {
        if (field.getField(x, y + field.getRows()) == "X" || field.getField(x, y + field.getRows()) == ".") {
            cout << "Wrong coordinates, try again!\n";
            shootout(field, cover_field, player, check);
        }
        else if (hit_check_up(field, x, y + field.getRows())) {
            cout << "Hit\n";
            cover_field.setField(x, y + field.getRows(), "X");
            field.setField(x, y + field.getRows(), "X");
            cover_field.print();
            destroy_check(field, cover_field, player);
            if (winner_check(field, player)) {
                cout << player->getName() << " win!\n";
                check = false;
                return;
            }
            shootout(field, cover_field, player, check);
        } else {
            cout << "Miss!\n";
            field.setField(x, y, "X");
            cover_field.setField(x, y + field.getRows(), "X");
            cover_field.print();
            return;
        }
    }
}
