//
// Created by Наталья Белова on 09.10.2021.
//

#ifndef UNTITLED11_CONTAINER_H
#define UNTITLED11_CONTAINER_H
#include "WellOfWisdom.h"

// Класс описывает контейнер.
class Container {
    // Массив объектор типа WellOfWisdom.
    WellOfWisdom** container = new WellOfWisdom*[10000];
    // Размер контейнера.
    int sizeOfContainer;
    // Максимальный размер контейнера.
    static const int MAX_SIZE = 10000;
public:
    // Конструктор класса.
    Container();
    // Метод для считывания данных.
    int Read(FILE* input_file);
    //Метод для вывода данных.
    void Write(FILE* output_file);
    // Метод для сортировки.
    void SortElements();
    // Метод для раномной генерации объектов.
    void InRnd(int count);
};

#endif //UNTITLED11_CONTAINER_H
