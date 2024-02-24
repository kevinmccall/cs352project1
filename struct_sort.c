#include "./struct_sort.h"
#include <stdio.h>
#include <stdlib.h>

#define NUM_PEOPLE 100

person_t data[NUM_PEOPLE];
char str[100];

void remove_space(char *person_field){
        while (person_field[0] == ' '){
            ++person_field;
        }
}

int main(int argc, char **argv) {
    char *filename = "contacts.txt";
    FILE *file = fopen(filename, "r");
    // reads a single line in from the file
    // parse the string to create a struct
    // 7
    int count = 0;
    while (fgets(str, 100, file) != NULL) {
        person_t person;
        
        sscanf(str, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %s",
           person.first_name, person.last_name, person.addy.address,
           person.addy.city, person.addy.state, person.addy.zip_code,
           person.phone_number);

        remove_space(&person.first_name);
        data[count] = person;
        count++;
    }

    // printf("%s~ %s~ %s~ %s~ %s~ %s~ %s~\n", first_name, last_name, address,
    //        city, state, zip, phone_num);

    // add the struct to the array

    // sort the array

    // write to output file

    // done :D
}