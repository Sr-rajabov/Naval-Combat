//
// Created by sorbo on 03.07.2023.
//

#ifndef NAVAL_COMBAT_BATTLEFIELD_H
#define NAVAL_COMBAT_BATTLEFIELD_H
#include "iostream"
#include "iomanip"
#include "string"
using namespace std;
#define newline '\n'
class Battlefield {
public:
    //Constructor & Destructor
    explicit Battlefield(size_t rows, size_t cols);
    ~Battlefield();
    //Getters & Setters
    size_t getRows() const;
    size_t getCols() const;
    string getField(size_t i, size_t j) const;
    void setField(size_t i, size_t j, string value);
    //Other
    void print() const;
private:
    size_t rows;
    size_t cols;
    string **field;
};

#endif //NAVAL_COMBAT_BATTLEFIELD_H
