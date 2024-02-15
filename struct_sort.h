#ifndef STRUCT_SORT_H
#define STRUCT_SORT_H
#define STATE 3
#define ADDRESS_SIZE 100
#define CITY_SIZE 100
#define FIRST_NAME 100
#define LAST_NAME 100
#define ZIP_SIZE 6
#define PHONE_SIZE 13

typedef struct {
    char address[ADDRESS_SIZE];
    char city[CITY_SIZE];
    char state[STATE];
    char zip_code[ZIP_SIZE];
} address;
typedef struct {
    char first_name[FIRST_NAME];
    char last_name[LAST_NAME];
    address addy;
    char phone_number[PHONE_SIZE];
} person_t;

#endif
