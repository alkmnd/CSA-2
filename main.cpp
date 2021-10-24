#include <iostream>
#include "Container.h"
#include <cstdlib>
#include <cstdio>
#include  <ctime>
#include <unistd.h>

// Метод для получения входного файла.
FILE* GetInputFile(char* argv[]) {
    if(access(argv[1], F_OK)!=-1){
        return fopen(argv[1],   "r");
    }
    else{
        printf("Could not open input file!\n");
        return nullptr;
    }
    exit(1);
}
// Получение выходного файла.
FILE* GetOutputFile(char* argv[], int number){
    if(access(argv[number], F_OK)!=-1){
        return fopen(argv[number], "w");
    } else {
        printf("Could not open output file!\n");
        return nullptr;
    }
}
int main(int argc, char* argv[]) {
    time_t start, end;
    start = clock();
    srand(time(0));
    Container *container = new Container();
    if(argc < 3) {
            std::cout << "Incorrect input data" << "\n";
            printf("Elapsed: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
            return 1;

    } else if (argc == 3) {
        int status_code = container->Read(GetInputFile(argv));
        if (status_code != 1) {
            FILE *output_file = GetOutputFile(argv, 2);
            if (output_file != nullptr) {
                container->Write(output_file);
                container->SortElements();
                fprintf(output_file, "Sorted container:\n");
                container->Write(output_file);
            }
        }
    } else if ((argc == 4) && !strcmp(argv[1], "-r")) {
        int numberOfObjects = atoi(argv[2]);
        if ((numberOfObjects < 1) || (numberOfObjects > 10000)) {
            printf("The number of objects must be in the range 1 to 10000");
            printf("Elapsed: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
            return 1;
        }
        container->InRnd(numberOfObjects);
        FILE *output_file = GetOutputFile(argv, 3);
        if (output_file != nullptr) {
            container->Write(output_file);
            container->SortElements();
            fprintf(output_file, "Sorted container:\n");
            container->Write(output_file);
        }
    }
    end = clock();
    // Вывод времени выполнения программы.
    printf("Elapsed time: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
    return 0;
}
