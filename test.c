#include <stdio.h>

int main() {
    // int int_val;
    // double float_val;
    // sscanf("52, 2", "%d, %lf", &int_val,
    //        &float_val); // example input is: 52, 2.
    // printf("%d %lf\n", int_val, float_val);
    // sscanf("52, 2", "%d %lf", &int_val, &float_val); // example input is:
    // 52, 2. printf("%d %lf\n", int_val, float_val);

    char str1[100];
    char str2[100];
    sscanf("kevin, luke\n", "%s %s", str1, str2); // example input is: 52, 2.
    printf("str1 -> %s\nstr2 -> %s\n", str1, str2);

    // integer of size 10 - garbage values
    int *array = malloc(sizeof(int) * 10);
    // or - filled with 0s
    array = calloc(10, sizeof(int))
}