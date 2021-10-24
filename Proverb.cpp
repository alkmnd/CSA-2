//
// Created by Наталья Белова on 09.10.2021.
//

#include "Proverb.h"
Proverb::Proverb(char* content, char* country) : WellOfWisdom(content) {
    strcpy(this->content, content);
    strcpy(this->country, country);

}

void Proverb::ToString(FILE* output_file) {
    fprintf(output_file, "This is a proverb:\t%s\tCountry: %s\tValue of the function: %f\n",
            this->content, this->country, this->GetQuotient());
}
