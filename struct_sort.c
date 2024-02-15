#include <stdio.h>
#include "./struct_sort.h"

#define NUM_PEOPLE 100
person_t data[NUM_PEOPLE];
char str[100];

int main (int argc, char **argv){
    FILE *file = fopen(argv[1], "r");
    fgets(str, 100, file);
}