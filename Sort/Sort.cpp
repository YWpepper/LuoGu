#include "Sort.h"

int main()
{
    // int arr[] = {5, 8, 7, 3, 2};
    // int arr[] = {2, 3, 5, 7, 8};
    int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    display(arr, len);
    // bubbleSort(arr, len);
    // bubbleSort_re(arr, len);
    insertSort(arr, len);
    // selectSort(arr, len);
    // shellSort(arr, len);
    display(arr, len);
    return 0;
}