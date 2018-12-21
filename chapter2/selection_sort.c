#include "stdio.h"
#include "common_func.h"

void selection_sort (int* arr, int len) {
    for (int i = 0; i < len - 1; ++i)
    {
        int min_idx = i;

        for (int j = i + 1; j < len; ++j)
        {
            if (arr[j] < arr[min_idx]) 
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        print_arr(arr, len);
    }
}



int main(int argc, char const *argv[])
{
    int a[10] = {3, 4, 2, 6, 7, 5, 1, 9, 8, 0};
    selection_sort(a, 10);
    return 0;
}