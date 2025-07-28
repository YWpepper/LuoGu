#include "Sort.h"

int main()
{
    int arr[] = {8, 5, 7, 3, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    display(arr, len);
    bubbleSort(arr, len);
    display(arr, len);
    return 0;
}