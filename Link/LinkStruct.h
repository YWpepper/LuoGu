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
}

void displayAddress(struct Node *ptr)
{
    static int idx = 0;
    if (ptr != nullptr)
    {
        // idx += 1;
        // cout << " node: " << idx << " address: " << ptr << " data : " << ptr->data << endl;
        displayAddress(ptr->next);
        cout << ptr->data << endl;
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
    struct Node *temp;
    struct Node *p;
    p = head;
    temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = data;
    int i = 0;
    while (i != idx)
    {
        p = p->next;
        i++;
    }
    temp->next = p->next;
    p->next = temp;
    free(temp);
    return head;
}

struct Node *deleteOfNode(struct Node *head, int idx)
{
    struct Node *ptr;
    ptr = head; // 指向同一个空间；
    int i = 0;
    while (i != idx)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *Tptr;
    Tptr = (struct Node *)malloc(sizeof(struct Node *));
    Tptr = ptr->next;
    ptr = Tptr->next;
    free(Tptr);
    return head;
}
