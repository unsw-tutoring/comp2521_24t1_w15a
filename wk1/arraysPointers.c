#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[20];
    double wam;
};

int main(void) {
    int a[5];
    printf("printf a = %p\n", a);
    printf("printf &a = %p\n", &a[0]);
    printf("printf &a = %p\n", &a[1]);

    // TODO: malloc an array of structs

    // TODO: malloc an array of pointers

    // TODO: malloc a 2D array
}