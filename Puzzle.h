//
// Created by Наталья Белова on 09.10.2021.
//

#ifndef UNTITLED11_PUZZLE_H
#define UNTITLED11_PUZZLE_H
#include "WellOfWisdom.h"

// Класс описывает объект Puzzle.
class Puzzle: public WellOfWisdom {
    // Уникальная переменная для класса Puzzle.
    char* answer = new char[10000];
public:
    // Конструктор класса.
    Puzzle(char* content, char* answer);
void ToString(FILE* output_file);
};


#endif //UNTITLED11_PUZZLE_H
