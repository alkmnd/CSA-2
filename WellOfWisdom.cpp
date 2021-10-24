//
// Created by Наталья Белова on 09.10.2021.
//
#include "WellOfWisdom.h"
#include <cctype>

WellOfWisdom::WellOfWisdom(char* content) {
    strcpy(this->content, content);
}
double WellOfWisdom::GetQuotient() {
    int counter = 0;
    for (int i = 0; i < strlen(this->content); ++i) {
        if(ispunct(content[i]))
        {
            counter++;
        }
    }
    return (double)counter / (double)strlen(this->content);
}



