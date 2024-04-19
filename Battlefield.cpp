//
// Created by sorbo on 03.07.2023.
//

#include "Battlefield.h"
#include <utility>

//Constructor & Destructor
Battlefield::Battlefield(){
    try {
        field = new string *[rows];
        *(field) = new string[rows * cols];
        for (int i = 1; i != rows; ++i) {
            *(field + i) = *(field + i - 1) + cols;
        }
        char count = '1';
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i > 0 && i < rows - 1 && j != 0 && j != cols / 2 - 1 && j != cols - 1 && j != cols / 2)
                    *(*(field + i) + j) = '~';
                else if (j == cols / 2 - 1) *(*(field + i) + j) = '|';
                if (j == cols - 1) *(*(field + i) + j) = ' ';
                if (i == rows - 1) *(*(field + i) + j) = ' ';
            }
        }
        for (int i = 1; i < rows - 1; ++i, count++) {
            *(*(field + i)) = count;
            *(*(field) + i) = count;
            *(*(field + i) + rows) = count;
            *(*(field) + rows + i) = count;
        }
        *(*(field + rows - 2)) = "10";
        *(*(field) + rows - 2) = "10";
        *(*(field) + cols - 2) = "10";
        *(*(field + rows - 2) + rows) = "10";
    }
    catch (bad_alloc const &ex) {
        cerr << ex.what() << newline;
    }
}


Battlefield::~Battlefield() {
    delete []*(field);
    delete [] field;
}

//Getters & Setters
size_t Battlefield::getCols() const {return cols;}

size_t Battlefield::getRows() const {return rows;}

string Battlefield::getField(size_t i, size_t j) const {return field[i][j];}

void Battlefield::setField(size_t i, size_t j, string value) {
    field[i][j] = std::move(value);
}

//Other
void Battlefield::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(3) <<  *(*(field + i) + j);
        }
        cout << newline;
    }
}
