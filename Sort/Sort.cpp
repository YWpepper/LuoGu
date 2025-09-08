#include "Sort.h"

int main()
{
    // int arr[] = {5, 8, 7, 3, 2};
    // int arr[] = {2, 3, 5, 7, 8};
    // int arr[] = {8, 9, 1, 7, 2, 3, 5, 4, 6};
    // int len = sizeof(arr) / sizeof(arr[0]);

    // vector<int> arr = {8, 9, 1, 7, 2, 3, 5, 4, 6};
    // vector<int> arr = {1, 9, 1, 7, 2, 3, 5, 4, 6};
    vector<int> arr = {5,4,3,2,1};
    int len = arr.size();

    display2(arr, len);
    // bubbleSort(arr, len);
    // bubbleSort_re(arr, len);
    // insertSort(arr, len);

    // selectSort(arr, len);
    // shellSort(arr, len);

    int j1 = partition2(arr,0,len);
    display2(arr, len);

    // int j2= partition(arr,0,j1-1);
    // int j3=  partition(arr,j1,len);
    // display2(arr, len);


    // int j4= partition(arr,0,j2-1);
    // partition(arr,j3,len);
    // display2(arr, len);

    return 0;
}