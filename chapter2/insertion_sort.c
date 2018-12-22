#include "stdio.h"
#include "common_func.h"
    

// assending order
void insertion_sort (int* arr, int len) {
    int key = 0;
    for (int i = 1; i < len; ++i) {
        key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        print_arr(arr, len);
    }
}

// desending order
void insertion_sort_de (int* arr, int len) {
    int key = 0;
    for (int i = 1; i < len; ++i) {
        key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] < key)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        print_arr(arr, len);
    }
}

void bubble_sort(int* arr, int len) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (arr[j - 1] > arr[j]) {
                    sorted = false;
                    swap(arr[j - 1], arr[j]);
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    // int a[10] = {3, 4, 2, 6, 7, 5, 1, 9, 8, 0};
    int a[6] = {31, 41, 59, 26, 41, 58};
    insertion_sort(a, 6);


    return 0;
}