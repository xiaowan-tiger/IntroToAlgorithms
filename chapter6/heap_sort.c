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

// ====================find index==============================
// be careful about the C-arr index rule
int get_heap_parent(int index) {
    return (index - 1) / 2;
}

int get_heap_left(int index) {
    return index * 2 + 1;
}


int get_heap_right(int index) {
    return index * 2 + 2;
}
// ============================================================



void max_heapify(int* arr, int index, int len) {
    int largest = -1;
 
    // from index get Left_Child / Right_Child indexes, then compare the find the largest
    int l = get_heap_left(index);
    int r = get_heap_right(index);
    if ((l < len) && (arr[l] > arr[index]))
        largest = l;
    else
        largest = index;

    if ((r < len) && (arr[r] > arr[largest])) // here right should compare with "the largest"
        largest = r;

    // if root(index) is not the largest, swap & look downwards until index sink to the leaf
    if (largest != index) {
        // exchange index with (l or r) child
        swap(arr[index], arr[largest]);
        max_heapify(arr, largest, len);
    }
}

void build_max_heap(int* arr, int len) {
    // to build max heap, dir should follow buttom-up way, hence start from mid of the array, downwards executing heapify
    for (int i = (len / 2); i >= 0; i--)
    {
        max_heapify(arr, i, len);
    }
}

void heap_sort(int* arr, int len) {
    // permute array to build max heap
    build_max_heap(arr, len);

    // walk through the array
    for (int i = len - 1; i > 0; i--)
    {
        // backup the largest item to the end
        swap(arr[0], arr[i]);

        // reduce the heap size and re-build the max heap to ensure, root (arr[0]) holds the max, ready for next iteration.
        len = len - 1;
        max_heapify(arr, 0, len);
    }
}


int main(int argc, char const *argv[])
{
    int arr[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    heap_sort(arr, 14);
    print_arr(arr, 14);

    return 0;
}