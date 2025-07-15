#include "LinkStruct.h"

int main()
{
    struct Node *myLink1;
    int arr[10] = {1, 2, 3, 4};
    myLink1 = create(myLink1, arr, 6);
    // displayAddress(myLink1);
    display(myLink1);
    cout << "num is " << countNodes(myLink1) << endl;
    cout << "sum of it is " << sumOfNodes(myLink1) << endl;
    cout << "max of it is " << maxOfNodes(myLink1) << endl;
    myLink1 = insertOfNode(myLink1, 4, 5);
    display(myLink1);
    cout << endl;
    myLink1 = deleteOfNode(myLink1, 4);
    display(myLink1);
}
