#include "LinkStruct.h"

int main()
{
    /*
    func：创建一个链表通过数组。
    */
    // struct Node *myLink1(nullptr);
    // int arr[10] = {0, 0, 0, 0};
    // myLink1 = create(myLink1, arr, 4);
    // display(myLink1);

    /*
    func：链表求和，链表找最大，插入数值，删除数值
     */
    // cout << "num is " << countNodes(myLink1) << endl;
    // cout << "sum of it is " << sumOfNodes(myLink1) << endl;
    // cout << "max of it is " << maxOfNodes(myLink1) << endl;
    // myLink1 = insertOfNode(myLink1, 4, 5);
    // display(myLink1);
    // cout << endl;
    // myLink1 = deleteOfNode(myLink1, 4);
    // display(myLink1);

    /*
    func：优化查找，并且将查找到的目标移到最前面
     */
    // myLink1 = linearSearch(myLink1, 2);
    // display(myLink1);

    /*
    func：创建一个链表通过直接插入。
        - 此处优化了头节点插入
    */
    struct Node *myLink1(nullptr);
    myLink1 = insertOfNode(myLink1, 0, 0); // 测试头插环境
    myLink1 = insertOfNode(myLink1, 1, 1); // 测试一般环境
    myLink1 = insertOfNode(myLink1, 2, 2);
    myLink1 = insertOfNode(myLink1, 3, 3);
    display(myLink1);

    /*
    func： 将目标插入到一个排好序的链表里面。
    */
    // int key = 8;
    // myLink1 = insertInSorted(myLink1, key);
    // cout << endl;
    // display(myLink1);

    /*
    func：此处检验尾巴节点删除和头节点删除；
    */
    // myLink1 = deleteOfNode(myLink1, 0);
    // display(myLink1);

    /*
    func：删除重复的元素？ 之前是查找重复元素，用哈希表，现在这种用两个指针。
    */
    // myLink1 = deleteDuplicated(myLink1);
    // display(myLink1);

    /*
    func：如何旋转一个链表；
    1. 交换 链表的 指针区域。
    2. 交换 链表的 数值区域；
    在上述交换的思想，一种是swap，一种是复制存储。看作二维数组来处理
   */
    myLink1 = reverseLink2(myLink1);
    display(myLink1);
}
