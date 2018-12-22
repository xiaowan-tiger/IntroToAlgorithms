#include "stdio.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void print_arr(int* arr, int len) {
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
