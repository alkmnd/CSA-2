//
// Created by Наталья Белова on 09.10.2021.
//

#include "Aphorism.h"
Aphorism::Aphorism(char* content, char* author) : WellOfWisdom(content) {
    strcpy(this->content, content);
    strcpy(this->author, author);
}
void Aphorism::ToString(FILE* output_file) {
    fprintf(output_file, "This is an aphorism:\t%s\tAuthor: %s\tValue of the function: %f\n",
            this->content, this->author, this->GetQuotient());
}