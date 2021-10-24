//
// Created by Наталья Белова on 09.10.2021.
//

#ifndef UNTITLED11_PROVERB_H
#define UNTITLED11_PROVERB_H
#include "WellOfWisdom.h"

// Класс описывает пословицу.
class Proverb: public WellOfWisdom {
    // Уникальное значение для класса - страна пословицы.
    char* country = new char[10000];
public:
    // Конструктор класса.
    Proverb(char* content, char* country);
void ToString(FILE* output_file);
};


#endif //UNTITLED11_PROVERB_H
