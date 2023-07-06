//
// Created by sorbo on 03.07.2023.
//

#include "Player.h"

// Constructor and Destructor
Player::Player() {
    cout << "Player " << num << " enter your name!\n";
    cin >> Name;
    playerNum = num;
    num++;
    arr_size = 0;
    ship_arr = new Ship[arr_size];
}

Player::~Player() {
    delete[] ship_arr;
}

//Getters & Setters
Ship Player::getShip(size_t i) const {
    return ship_arr[i];
}

size_t Player::get_arr_size() const {return this->arr_size;}

string Player::getName() const {return Name;}

int Player::getPlayerNum() const {return playerNum;}

//Other
int Player::num = 1;

void enter_direction(char &direction) {
    cout << "Enter direction!\n"
            "\tr - right\n"
            "\tl - left\n"
            "\tu - up\n"
            "\td - down\n";
    cin >> direction;
    if (direction != 'r' && direction != 'l' && direction != 'u' && direction != 'd') {
        cout << "wrong direction, try again!\n";
        enter_direction(direction);
    }
    }

void enter_coordinates(Battlefield &field, size_t &x, size_t &y, size_t size, char &direction) {
    cout << "Enter start coordinates!\n";
    while (true) {
        cin >> x >> y;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Wrong coordinates, try again!\n";
            continue;
        }
        break;
    }
    if (size > 1) {
        enter_direction(direction);
        if (boundary_check(field, x, y, direction, size)) {
            return;
        } else {
            cout << "Wrong coordinates, try again!\n";
            enter_coordinates(field, x, y, size, direction);
        }
    } else {
        if (boundary_check(field, x, y, direction, size)) {
            return;
        } else {
            cout << "Wrong coordinates, try again!\n";
            enter_coordinates(field, x, y, size, direction);
        }
    }
}

void Player::deploy(Battlefield &field, size_t num_of_ships, size_t size) {
    while (num_of_ships != 0) {
        size_t x = 0, y = 0;
        char direction = 'n';
        size_t size_copy = size;
        enter_coordinates(field, x, y, size, direction);
        Ship *ship = new Ship(x, y, size);
        if (playerNum == 1) {
            if (field_check(field, x, y, direction, size - 1)) {
                if (direction == 'r'){
                    while (size_copy != 0) {
                        field.setField(x, y, "O");
                        ship->push_coordinates(x, y);
                        y++;
                        size_copy--;
                    }
                    field.print();
                }
                else if (direction == 'l') {
                    while (size_copy != 0) {
                        field.setField(x, y, "O");
                        ship->push_coordinates(x, y);
                        y--;
                        size_copy--;
                    }
                    field.print();
                }
                else if (direction == 'u') {
                    while (size_copy != 0) {
                        field.setField(x, y, "O");
                        ship->push_coordinates(x, y);
                        x--;
                        size_copy--;
                    }
                    field.print();
                }
                else if (direction == 'd') {
                    while (size_copy != 0) {
                        field.setField(x, y, "O");
                        ship->push_coordinates(x, y);
                        x++;
                        size_copy--;
                    }
                    field.print();
                }
                else {
                    while (size_copy != 0) {
                        field.setField(x, y, "O");
                        size_copy--;
                        ship->push_coordinates(x, y);
                    }
                    field.print();
                }
            }
            else {
                cout << "Wrong coordinates, try again!\n";
                num_of_ships++;
            }
            this->push_back(ship);
            num_of_ships--;
        }
        else {
            if (field_check(field, x, y + field.getRows(), direction, size - 1)) {
                if (direction == 'r'){
                    while (size_copy != 0) {
                        field.setField(x, y + field.getRows(), "O");
                        ship->push_coordinates(x, y);
                        y++;
                        size_copy--;
                    }
                    field.print();
                }
                else if (direction == 'l') {
                    while (size_copy != 0) {
                        field.setField(x, y + field.getRows(), "O");
                        ship->push_coordinates(x, y);
                        y--;
                        size_copy--;
                    }
                    field.print();
                }
                else if (direction == 'u') {
                    while (size_copy != 0) {
                        field.setField(x, y + field.getRows(), "O");
                        ship->push_coordinates(x, y);
                        x--;
                        size_copy--;
                    }
                    field.print();
                }
                else if (direction == 'd') {
                    while (size_copy != 0) {
                        field.setField(x, y + field.getRows(), "O");
                        ship->push_coordinates(x, y);
                        x++;
                        size_copy--;
                    }
                    field.print();
                }
                else {
                    while (size_copy != 0) {
                        field.setField(x, y + field.getRows(), "O");
                        size_copy--;
                        ship->push_coordinates(x, y);
                    }
                    field.print();
                }
            }
            else {
                cout << "Wrong coordinates, try again!\n";
                num_of_ships++;
            }
            this->push_back(ship);
            num_of_ships--;
        }
    }
}

Ship *Player::erase_ship(size_t position) {
    Ship *temp = new Ship[this->arr_size - 1];
    for (size_t i = 0; i < arr_size; ++i) {
        if (i == position) {
            continue;
        }
        else if (i < position) temp[i] = ship_arr[i];
        else if (i > position) temp[i - 1] = ship_arr[i];
    }
    delete[] ship_arr;
    ship_arr = temp;
    arr_size--;
    return ship_arr;
}

Ship *Player::push_back(const Ship *ship) {
    Ship *temp = new Ship[arr_size + 1];
    for (int i = 0; i < arr_size; ++i) {
        *(temp + i) = *(ship_arr + i);
    }
    *(temp + arr_size) = *ship;
    delete[] ship_arr;
    ship_arr = temp;
    arr_size++;
    return ship_arr;
}