//
// Created by Наталья Белова on 09.10.2021.
//
#include "Container.h"
#include "Aphorism.h"
#include "Proverb.h"
#include "Puzzle.h"

Container::Container() {
    sizeOfContainer = 0;
}

char symbols_for_string[41] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g',
                             'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', '1', '2', '3', '4',
                             '5', '6', '7', '8', '9', '0', ',', '.', '!', '?', ':'};
char symbols_for_types[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g',
                             'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
char* GetRandomString(char array []) {
    char* result;
    int length_of_string = rand() % 20 + 1;
    result = new char [length_of_string];
    for (int i = 0; i < length_of_string; ++i) {
        result[i] = array[rand() % (strlen(array))];
    }
    return result;

}
void Container::InRnd(int count) {
    for (int i = 0; i < count; ++i) {
        int type = rand() % 3;
        WellOfWisdom* wellOfWisdom;
        switch(type) {
            case 0:
                wellOfWisdom = new Aphorism
                        (GetRandomString(symbols_for_string),
                         GetRandomString(symbols_for_types));
                break;
            case 1:
                wellOfWisdom = new Proverb
                        (GetRandomString(symbols_for_string),
                         GetRandomString(symbols_for_types));
                break;
            case 2:
                wellOfWisdom = new Puzzle
                        (GetRandomString(symbols_for_string),
                         GetRandomString(symbols_for_types));
                break;
        }
        container[sizeOfContainer] = wellOfWisdom;
        sizeOfContainer++;

    }
}
int Container::Read(FILE* input_file) {
    if (input_file != nullptr) {
        int count = 0;
        int status_code = fscanf(input_file, "%d\n", &count);
        if (status_code != 1) {
            printf("Could not read the number of objects!");
            return 1;
        }
        if (count > 10000) count = MAX_SIZE;
        for (int i = 0; i < count; ++i) {
            int type;
            int status_code = fscanf(input_file, "%d\n", &type);
            if (status_code != 1) {
                printf("Could not read the object type!\n");
                return 1;
            }
            char *content = new char[100001];
            char *type_content = new char[100001];
            status_code = fscanf(input_file, "%s\n", content);
            if (status_code != 1 || strlen(content) == 0) {
                printf("Incorrect input!\n");
                return 1;
            }
            status_code = fscanf(input_file, "%s\n", type_content);
            if (status_code != 1) {
                printf("Incorrect input!\n");
                return 1;
            }
            WellOfWisdom *wellOfWisdom;
            switch (type) {
                case 0: {
                    wellOfWisdom = new Aphorism
                            (content, type_content);
                    break;
                }
                case 1: {
                    wellOfWisdom = new Proverb
                            (content, type_content);
                    break;
                }
                case 2: {
                    wellOfWisdom = new Puzzle
                            (content, type_content);
                    break;
                }
                default: {
                    break;
                }

            }
            container[sizeOfContainer] = wellOfWisdom;
            sizeOfContainer++;

        }
    } else {
        return 1;
    }
    return 0;
}

void Container::Write(FILE* output_file) {
    for (int i = 0; i < sizeOfContainer; ++i) {
        fprintf(output_file, "%d: ", i + 1);
        container[i]->ToString(output_file);
    }
}

void Container::SortElements() {
    int step = 1;
    WellOfWisdom *temp = new WellOfWisdom[sizeOfContainer];
    while (step < sizeOfContainer)
    {
        int index = 0;
        int l = 0;
        int m = l + step;
        int r = l + step * 2;
        do
        {
            m = m < sizeOfContainer ? m : sizeOfContainer;
            r = r < sizeOfContainer ? r : sizeOfContainer;
            int i1 = l, i2 = m;
            for (; i1 < m && i2 < r; )
            {
                if (container[i1]->GetQuotient() < container[i2]->GetQuotient()) { temp[index++] = *container[i1++]; }
                else { temp[index++] = *container[i2++]; }
            }
            while (i1 < m) temp[index++] = *container[i1++];
            while (i2 < r) temp[index++] = *container[i2++];
            l += step * 2;
            m += step * 2;
            r += step * 2;
        } while (l < sizeOfContainer);
        for (int i = 0; i < sizeOfContainer; i++)
            *container[i] = temp[i];
        step *= 2;
    }
}