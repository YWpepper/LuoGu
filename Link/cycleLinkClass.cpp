#include "cycleLinkClass.h"

int main()
{
    int arr[] = {1, 2, 3, 4};
    CycleLinkClass<int> mylink(arr, 4);
    mylink.display();
    return 0;
}