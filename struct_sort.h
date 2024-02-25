/**
 * @author Luke Howell and Kevin McCall
 * @version 2/24/2024
 * Contains the struct/function definitions for the struct_sort.c file.
 */

#ifndef STRUCT_SORT_H
#define STRUCT_SORT_H
/** Size of string for state abbreviation in address */
#define STATE 3
/** size of address in person_t */
#define ADDRESS_SIZE 255
/** size of city in address */
#define CITY_SIZE 100
/** size of first name in address */
#define FIRST_NAME 100
/** size of last name in person_t */
#define LAST_NAME 100
/** size of zip code in address */
#define ZIP_SIZE 6
/** size of phone_number in person_t */
#define PHONE_SIZE 13

/**
 * A struct that represents the address of a person.A
 * Contains a street address, a city, a state, and a zip code.
 */
typedef struct {
    char address[ADDRESS_SIZE];
    char city[CITY_SIZE];
    char state[STATE];
    char zip_code[ZIP_SIZE];
} address;

/**
 * Struct representing a person. Contains an address, first name, last name,
 * and a phone number.
 */
typedef struct {
    char first_name[FIRST_NAME];
    char last_name[LAST_NAME];
    address addy;
    char phone_number[PHONE_SIZE];
} person_t;

/**
 * Compares two strings, case insensitively
 *
 *@param string1 the first string that is to be compared
 *@param string2 the second string that is to compared
 *@return < 0 string1 is smaller than string2
 *        = 0 string1 is equal to string2
 *        > 0 string2 is smaller than string1
 */
int strincmp(char *string1, char *string2, int length);

/**
 * Sorts the array of persons by last name in ascending order alphabetically,
 * and if the last names are the same, the people are sorted by first name.
 */
void bubble_sort();

/**
 * Compares two person_t based on their last name, then first name
 *
 * @return < 0 a is smaller than b
 *         = 0 a is equal to b
 *         > 0 b is less than a
 */
int person_t_cmp(person_t *a, person_t *b);

/**
 * Loads a person struct into person from a line of data from the expected
 * input file
 *
 * @param person a person struct to be passed in to be populated
 * @param line_of_data data structured in the form contacts.txt we were given
 * for the project
 */
void load_person_struct(person_t *person, char *line_of_data);

#endif