#include "common_func.h"
#include "limits.h"

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

void merge(int* arr, int p, int q, int r) {
    
    int len_left = q - p + 1;
    int len_right = r - q;
    int len_total = r - p + 1;

    int l_arr[len_left + 1];
    int r_arr[len_right + 1];

    int i = 0, j = 0;
    // copy two arrays of left/right of arr
    for (; i < len_left; i++)
        l_arr[i] = arr[p + i];
    for (; j < len_right; j++)
        r_arr[j] = arr[q + j + 1];
    
    l_arr[i] = r_arr[j] = INT_MAX;

    i = j = 0;

    for (int k = p; k < r + 1; k++) {
        if (l_arr[i] <= r_arr[j])
            arr[k] = l_arr[i++];
        else
            arr[k] = r_arr[j++];
    }
}

void merge_sort(int* arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
        print_arr(arr, r + 1);
    }
}
