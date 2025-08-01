#include "Sort.h"

int main()
{
    int arr[] = {5, 8, 7, 3, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    display(arr, len);
    // bubbleSort(arr, len);
    // bubbleSort_re(arr, len);
    insertSort(arr, len);
    display(arr, len);
    return 0;
}