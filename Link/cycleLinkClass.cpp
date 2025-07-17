#include "cycleLinkClass.h"

int main()
{
    int arr[] = {1, 2, 3, 4};
    CycleLinkClass<int> mylink(arr, 4);
    mylink.display();
    int deleteNode_idx = 0;
    mylink.deleteNode(deleteNode_idx);
    mylink.display();
    return 0;
}