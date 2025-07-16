#include <cstdio>
#include <cstdlib> // malloc func
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node *create(struct Node *head, int arr[], int len)
{
    struct Node *temp, *last;                          // 他们的空间是开辟在栈里面的吗？
    head = (struct Node *)malloc(sizeof(struct Node)); // 开辟空间在堆里面
    head->data = arr[0];
    head->next = nullptr;
    last = head; // last和head指向了同一个空间
    // 撰写for函数初始化一个链表
    for (int i = 1; i < len; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = nullptr;
        last->next = temp; // 在这里修改了head的next指针区域
        last = temp;
    }
    return head;
}

void display(struct Node *ptr)
{
    while (ptr != 0)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void displayAddress(struct Node *ptr)
{
    static int idx = 0;
    if (ptr != nullptr)
    {
        // idx += 1;
        // cout << " node: " << idx << " address: " << ptr << " data : " << ptr->data << endl;
        displayAddress(ptr->next);
        cout << ptr->data << " ";
    }
}

int countNodes(struct Node *ptr)
{
    if (ptr == 0)
        return 0;
    else
        return countNodes(ptr->next) + 1;
}

int sumOfNodes(struct Node *ptr)
{
    if (ptr == 0)
        return 0;
    else
        return (sumOfNodes(ptr->next) + ptr->data);
}

int maxOfNodes(struct Node *ptr)
{
    static int max = -32768;
    if (ptr == 0)
        return max;
    else
    {
        if (ptr->data > max)
        {
            max = ptr->data;
        }
    }
    return maxOfNodes(ptr->next);
}

struct Node *insertOfNode(struct Node *head, int idx, int data)
{
    // 先获取链表的长度，idx不能超过链表的长度；
    int len = countNodes(head);

    // 这是我们需要插入的目标对象
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = nullptr;

    // 如果本身该链表就是空链表
    if (head == nullptr)
    {
        head = temp;
        return head;
    }
    // 头插
    if (idx == 0)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    else // 无论插在哪里，尾巴或者中间。
    {
        // 这是一个用来遍历链表的临时指针
        struct Node *p;
        p = head;
        // 先用p指向目标idx的节点
        for (int i = 0; i < idx - 1; i++)
            p = p->next;
        // 准备开始插入 开始给 temp->next 赋予指针空间
        temp->next = p->next;
        p->next = temp;
    }

    return head;
}

// 因为我现在不知道我的插入位置需要通过找到按顺序插入的位置。
struct Node *insertInSorted(struct Node *head, int key)
{
    struct Node *ptr;
    ptr = head;
    struct Node *target = (struct Node *)malloc(sizeof(struct Node));
    target->data = key;
    target->next = nullptr;
    while (ptr != nullptr)
    {
        if (((ptr->next)->data) > key && ((ptr->data)) < key)
        {
            target->next = ptr->next;
            ptr->next = target;
            return head;
        }
        ptr = ptr->next;
    }
}

struct Node *deleteOfNode(struct Node *head, int idx)
{
    struct Node *ptr;
    ptr = head;   // 指向同一个空间；
    if (idx == 0) // 头删除
    {
        ptr = head->next;
        head = ptr;
        return head;
    }

    int i = 0;
    while (i != idx - 1)
    {
        ptr = ptr->next;
        i++;
    } // 先移动到指定位置
    struct Node *Tptr;
    Tptr = (struct Node *)malloc(sizeof(struct Node *));
    Tptr = (ptr->next)->next;
    ptr->next = Tptr;
    return head;
}

struct Node *linearSearch(struct Node *head, int target)
{
    struct Node *ptr;
    ptr = head; // 指向同一个空间；
    struct Node *bptr = nullptr;
    while (ptr != nullptr)
    {
        if (ptr->data == target) // 如果找到该目标，将该目标移到最前面
        {
            // 首先先保留ptr的next；
            // 由于bptr是一个慢指针，所以还是指向target的前一个节点
            cout << "bptr->data is " << bptr->data << endl;
            bptr->next = ptr->next;
            ptr->next = head;
            head = ptr;
            return head;
        }
        bptr = ptr;      // 放一个后指针指向它，得在它更新前赋值，不然他找到目标的时候都更想了
        ptr = ptr->next; // ptr指针一直去遍历链表
    }
}

struct Node *deleteDuplicated(struct Node *head)
{
    // 默认从小到大
    struct Node *lptr;
    struct Node *rptr = (struct Node *)malloc(sizeof(struct Node));
    lptr = head;
    rptr = head->next;
    while (lptr && rptr)
    {
        if (lptr->data == rptr->data)
        {
            // 说明是重复的元素了
            lptr->next = rptr->next;
            rptr = rptr->next;
            // continue; // 不执行后面了 或者用else
        }
        else
        {
            lptr = lptr->next;
            rptr = rptr->next;
        }
    }
    return head;
}

int swapLinkData(struct Node *ptr1, struct Node *ptr2)
{
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
    return 0;
}

// 用了一个临时数组来存储
struct Node *reverseLink(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *last = head;
    int tempArr[10] = {0};
    for (int i = 0; i < (countNodes(ptr) - 1), ptr != nullptr; i++)
    {
        tempArr[i] = ptr->data;
        ptr = ptr->next;
    }
    ptr = head;
    int cnt = countNodes(ptr) - 1;
    while (ptr != nullptr && cnt >= 0)
    {
        ptr->data = tempArr[cnt];
        ptr = ptr->next;
        cnt--;
    }
    return head;
}

// 冒泡排序交换法则
struct Node *reverseLink2(struct Node *head)
{
    struct Node *ptr = head;

    for (int i = 0; i <= (countNodes(ptr)) - 2; i++)
    {
        swapLinkData(ptr, ((ptr->next)->next)); // 这个很有意思
        ptr = ptr->next;
    }
    return head;
}