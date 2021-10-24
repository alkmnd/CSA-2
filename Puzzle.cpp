//
// Created by Наталья Белова on 09.10.2021.
//

#include "Puzzle.h"
Puzzle::Puzzle(char* content, char* answer) : WellOfWisdom(content) {
    strcpy(this->content, content);
    strcpy(this->answer, answer);
}

void Puzzle::ToString(FILE* output_file) {
    fprintf(output_file, "This is a puzzle:\t%s\tAnswer: %s\t Value of the function: %f\n",
            this->content, this->answer, this->GetQuotient());
}
