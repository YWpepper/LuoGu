#include "cycleLinkClass.h"
const int MAXLEN = 100;

int findMid(Node<int> *ptr, Node<int> **hash)
{

    int mid = 0;
    for (int i = 1; i < MAXLEN; i++)
    {
        hash[i] = ptr;
        ptr = ptr->next;
        if (ptr == nullptr)
        {
            hash[i + 1] = nullptr;
            if (i % 2 == 0)
                mid = i / 2 + 1;
            else
                mid = i / 2;
            return mid;
        }
    }
}

// rptr 走2步，lptr走1步，这样走到最后，rpt比lptr夺走一半，刚刚好就是中心节点
int findMid_doubleLink(Node<int> *ptr)
{
    int mid = 0;
    Node<int> *lptr = ptr;
    Node<int> *rptr = ptr;
    // 如果是空链表
    if (lptr == nullptr)
        return 0;
    // 如果链表只有一个节点
    if (lptr->next == nullptr)
        return 1;
    // 链表大于等于两个
    while (rptr->next != nullptr)
    {
        rptr = rptr->next; // 多走2步
        if (lptr != nullptr)
        {
            lptr = lptr->next;
            mid++;
            if (rptr->next)
            {
                rptr = rptr->next;
            }
            else
                return mid;
        }
    }
    return mid;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    LinkClass<int> mylink(arr, 16);
    mylink.diaplay();
    Node<int> *ptr = mylink.getFirst();
    // 方法1； 哈希指针数组
    // Node<int> **hash_table = new Node<int> *[MAXLEN]; // 初始化一个哈希表，如果由于是存储链表所以使用二维指针，指向一个指针空间的指针
    // cout << "mid_index is " << findMid(ptr, hash_table) << endl;
    // cout << "mid_point_address is  " << hash_table[findMid(ptr, hash_table)] << endl;

    // 方法2: 双链表
    cout << findMid_doubleLink(ptr) << endl;
    // mylink.display();
    // int deleteNode_idx = 0;
    // mylink.deleteNode(deleteNode_idx);
    // mylink.display();
    // mylink.insert(2, 2);
    // mylink.display();
    // int data_idx = 4;
    // int data_get = 0;
    // cout << endl;
    // cout << mylink.get(data_idx, data_get) << endl;
    // cout << "data_get is " << data_get << endl;
    // return 0;

    /**
     * 单链表的算法题目练习
     *
     */

    /**
     * 1. 寻找链表的中间节点：
     * 考虑链表为空或只有一个节点的情况。
     * 尝试用一次遍历完成查找。
     */

    /**
     * double link 初始化双链表
     */
    // doubleLinkClass<int> *first = new doubleLinkClass<int>;
    // first->insert(0, 0);
    // first->insert(1, 1);
    // first->insert(2, 2);
    // first->insert(3, 3);
    // first->display();
    // first->display();
    // first->remove(3);
    // first->display();

    // first->reverse();
    // first->display();
}
