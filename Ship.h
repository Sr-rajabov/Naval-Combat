//
// Created by sorbo on 03.07.2023.
//

#ifndef NAVAL_COMBAT_SHIP_H
#define NAVAL_COMBAT_SHIP_H
#include "Battlefield.h"
#include "vector"
class Ship {
public:
    //Constructor & Destructor
    explicit Ship(size_t x, size_t y, size_t size);
    Ship();
    ~Ship();
    //Getters & Setters
    size_t getsize() const;
    size_t getx() const;
    size_t gety() const;
    void setx(size_t value);
    void sety(size_t value);
    size_t get_arr_size() const;
    size_t get_coordinates(size_t i) const;
    //Copy constructor
    Ship(Ship const &ship);
    //Other
    friend istream &operator>>(istream &is, Ship &ship);
    size_t *push_coordinates(size_t a, size_t b);
private:
    size_t x;
    size_t y;
    size_t size;
    size_t arr_size;
    size_t *arr;
};

istream &operator>>(istream &is, Ship &ship);

#endif //NAVAL_COMBAT_SHIP_H
