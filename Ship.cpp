//
// Created by sorbo on 03.07.2023.
//

#include "Ship.h"

//Constructor & Destructor
Ship::Ship(size_t x, size_t y, size_t size) : x(x), y(y), size(size), arr_size(0){
    arr = new size_t[arr_size];
}

Ship::~Ship() {
    delete[] arr;
}

Ship::Ship() = default;

//Getters & Setters
size_t Ship::getsize() const {return size;}

size_t Ship::getx() const {return x;}

void Ship::setx(size_t value) {x = value;}

void Ship::sety(size_t value) {y = value;}

size_t Ship::gety() const {return y;}

size_t Ship::get_coordinates(size_t i) const {
    return *(this->arr + i);
}

size_t Ship::get_arr_size() const {return this->arr_size;}

//Copy constructor
Ship::Ship(Ship const &ship) {
    size = ship.size;
    arr_size = ship.arr_size;
    arr = new size_t[arr_size];
    for (int i = 0; i < arr_size; ++i) {
        *(arr + i) = *(ship.arr + i);
    }
}

//Other
size_t *Ship::push_coordinates(size_t a, size_t b) {
    auto *temp = new size_t[arr_size + 2];
    for (int i = 0; i < arr_size; ++i) {
        *(temp + i) = *(arr + i);
    }
    *(temp + arr_size) = a;
    *(temp + arr_size + 1) = b;
    delete[] arr;
    arr = temp;
    arr_size += 2;
    return arr;
}

istream &operator>>(istream &is, Ship &ship) {
    is >> ship.x >> ship.y;
    return is;
}