#include "sort.h"

int main(int argc, char const *argv[])
{
    int a[10] = {3, 4, 2, 6, 7, 5, 1, 9, 8, 0};
    merge_sort(a, 0, 9);
    return 0;
}