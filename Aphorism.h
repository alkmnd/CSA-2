//
// Created by Наталья Белова on 09.10.2021.
//

#ifndef UNTITLED11_APHORISM_H
#define UNTITLED11_APHORISM_H
#include "WellOfWisdom.h"

// Класс описывает афоризм.
class Aphorism: public WellOfWisdom {
    // Уникальный параметр афоризма - автор.
    char* author = new char[10000];
public:
    // Конструктор класса.
    Aphorism(char* content, char* author);
void ToString(FILE* output_file);
};


#endif //UNTITLED11_APHORISM_H
