//
// Created by Наталья Белова on 09.10.2021.
//

#ifndef UNTITLED11_WELL_OF_WISDOM_H
#define UNTITLED11_WELL_OF_WISDOM_H

#include <string>
// Класс описывает объект WellOfWisdom.
class WellOfWisdom {
public:
    // Содержание кладези муд- рости – строка символов.
    char* content = new char[10000];
    // Метод для получения частного от деления количества знаков препинания на длину строки.
    double GetQuotient();
public:
    // Конструкторы класса.
    WellOfWisdom(char* content);
    WellOfWisdom() {};
    // Виртуальный метод для описания объекта в выходном файле.
    virtual void ToString(FILE* output_file) {};
};



#endif //UNTITLED11_WELL_OF_WISDOM_H
