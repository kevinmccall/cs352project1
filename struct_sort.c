/**
 * @author Luke Howell and Kevin McCall
 * @version 2/24/2024
 *
 * This program takes two command line arguments, the first being a file
 * containing contacts, the second a file to write to. The program then sorts
 * the contacts and writes to the second file name provided. The program sorts
 * the people by last name first, ascending alphabetically, and if they
 * have the same last name, they are sorted by first name.
 */

#include "./struct_sort.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** The maximum number of person_t entries that can be read in */
#define NUM_PEOPLE 100
/** The maximum string length we are using for this project */
#define MAX_STRING_LEN 255
/** expected number of CLI args */
#define EXPECTED_COMMAND_LINE_ARGS 3

/** The array to store person structs to be sorted in*/
person_t data[NUM_PEOPLE];
/** The current line being read in main */
char str[100];
/** the number of valid entries in the data array */
int num_people_data = 0;

/**
 * Loads a person struct into person from a line of data from the expected
 * input file
 *
 * @param person a person struct to be passed in to be populated
 * @param line_of_data data structured in the form contacts.txt we were given
 * for the project
 */
void load_person_struct(person_t *person, char *line_of_data) {
    sscanf(line_of_data, " %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %s",
           person->first_name, person->last_name, person->addy.address,
           person->addy.city, person->addy.state, person->addy.zip_code,
           person->phone_number);
}

/**
 * Sorts the array of persons by last name in ascending order alphabetically,
 * and if the last names are the same, the people are sorted by first name.
 */
void bubble_sort() {
    for (int i = 0; i < num_people_data; i++) {
        for (int j = i + 1; j < num_people_data; j++) {
            if (person_t_cmp(&data[i], &data[j]) > 0) {
                person_t temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

/**
 * Compares two strings, case insensitively
 *
 *@param string1 the first string that is to be compared
 *@param string2 the second string that is to compared
 *@return < 0 string1 is smaller than string2
 *        = 0 string1 is equal to string2
 *        > 0 string2 is smaller than string1
 */
int strincmp(char *string1, char *string2, int length) {
    int s1len = strnlen(string1, length) + 1;
    char s1lower[s1len];
    for (int i = 0; *(string1 + i) != '\0'; i++) {
        s1lower[i] = tolower(string1[i]);
    }

    int s2len = strnlen(string2, length) + 1;
    char s2lower[s2len];
    for (int i = 0; *(string2 + i) != '\0'; i++) {
        s2lower[i] = tolower(string2[i]);
    }

    return strncmp(s1lower, s2lower, length);
}

/**
 * Compares two person_t based on their last name, then first name
 *
 * @return < 0 a is smaller than b
 *         = 0 a is equal to b
 *         > 0 b is less than a
 */
int person_t_cmp(person_t *a, person_t *b) {
    int res = strincmp(a->last_name, b->last_name, MAX_STRING_LEN);
    if (res == 0) {
        res = strincmp(a->first_name, b->first_name, MAX_STRING_LEN);
    }
    return res;
}

/**
 * Entry point of programs
 * Expects 2 command line arguments
 * 1: the input file of structured data to be sorted by this program
 * 2: the output file where the sorted data shall be written to
 */
int main(int argc, char **argv) {
    if (argc != EXPECTED_COMMAND_LINE_ARGS) {
        fprintf(
            stderr,
            "Incorrect number of arguments passed. Expected %d received %d\n",
            EXPECTED_COMMAND_LINE_ARGS, argc);
        fprintf(stderr, "Usage: struct_sort <input file> <output file>\n");
        exit(1);
    }
    // char *filename = "contacts.txt";
    // char *out = "sorted.txt";
    char *filename = argv[1];
    char *out = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1);
    }
    // reads a single line in from the file
    // parse the string to create a struct
    while (fgets(str, 100, file) != NULL) {
        person_t person;
        load_person_struct(&person, str);
        data[num_people_data] = person;
        num_people_data++;
    }

    // sort the array

    bubble_sort();

    // write to output file
    FILE *outfile = fopen(out, "w");
    if (outfile == NULL) {
        fprintf(stderr, "Unable to write to file %s\n", out);
        exit(1);
    }
    for (int i = 0; i < num_people_data; i++) {
        fprintf(outfile, "%s,  %s,  %s,  %s,  %s,  %s,  %s\n",
                data[i].first_name, data[i].last_name, data[i].addy.address,
                data[i].addy.city, data[i].addy.state, data[i].addy.zip_code,
                data[i].phone_number);
    }
    // done :D
}