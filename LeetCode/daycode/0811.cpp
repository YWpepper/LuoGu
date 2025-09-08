#include <vector>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <iostream> // 用于输出结果
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

// 先遍历一个链表存储所有节点的地址，再遍历第二个链表查找是否有已经存储的节点
// ListNode *getInterNode(ListNode *headA, ListNode *headB)
// {
//     unordered_set<ListNode *> nodes;
//     while (headA != nullptr)
//     {
//         nodes.insert(headA);
//         headA = headA->next;
//     } // o(n)
//     // 遍历第二个节点
//     while (headB != nullptr)
//     {
//         if (nodes.count(headB))
//         {
//             return headB; // 只要找到就返回节点，因为节点的传递性不改变，所以不用担心；
//         }
//         headB = headB->next;
//     } // o(n)
//     return nullptr; //  检查完全文无相交节点；
// }

// 辅助函数：根据数组创建链表
ListNode *create_list(const vector<int> &val)
{
    if (val.empty())
        return nullptr;
    ListNode *head = new ListNode(val[0]);
    ListNode *curr = head;
    for (int i = 1; i < val.size(); i++)
    {
        curr->next = new ListNode(val[i]);
        curr = curr->next;
    }
    return head;
}

ListNode *getInterNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
    {
        return nullptr;
    }
    ListNode *pa = headA;
    ListNode *pb = headB;

    while (pa != pb)
    {
        pa = (pa == nullptr) ? headB : pa->next; // 有点类似追逐
        pb = (pb == nullptr) ? headA : pb->next;
    }
    return pa;
}

// 辅助函数：设置两个链表的相交节点
// 参数：listA-第一个链表，listB-第二个链表，skipA-A中到交点的步数，skipB-B中到交点的步数
void setIntersection(ListNode *listA, ListNode *listB, int skipA, int skipB)
{
    // 移动到A的交点前驱
    ListNode *currA = listA;
    for (int i = 0; i < skipA && currA; ++i)
    {
        currA = currA->next;
    }
    // 移动到B的交点前驱
    ListNode *currB = listB;
    for (int i = 0; i < skipB && currB; ++i)
    {
        currB = currB->next;
    }
    // 设置相交（B的交点前驱指向A的交点）
    if (currA && currB)
    {
        currB->next = currA;
    }
}

void printList(ListNode *head, const string &name)
{
    ListNode *curr = head;
    unordered_set<ListNode *> visted;
    while (curr && !visted.count(curr)) // 用一个哈希表防止有环打印
    {
        visted.insert(curr);
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{

    // 测试用例1：存在相交节点（示例1）
    cout << "=== 测试用例1：存在相交节点 ===" << endl;
    vector<int> a_vals = {4, 1, 8, 4, 5};
    vector<int> b_vals = {5, 6, 1};
    ListNode *headA = create_list(a_vals);
    ListNode *headB = create_list(b_vals);
    // 设置相交：A的第2步（0-based索引2）与B的第3步（0-based索引3）相交
    setIntersection(headA, headB, 2, 2); // B的"1"之后连接A的"8"
    printList(headA, "A");
    printList(headB, "B");
    ListNode *interNode = getInterNode(headA, headB);
    if (interNode)
    {
        cout << "相交节点值: " << interNode->val << endl;
    }
    else
    {
        cout << "无相交节点" << endl;
    }
}