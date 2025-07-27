#include <iostream>
#include "../Queue/QueueClass.h"
using namespace std;

template<class T>
class treeNode
{
public:
    int data;
    treeNode *lchild;
    treeNode *rchild;
    treeNode() : data(0), lchild(nullptr), rchild(nullptr) {}
    // 正确的 Node 构造函数（必须确保指针初始化）
    treeNode(int data) : data(data), lchild(nullptr), rchild(nullptr) {}
};

class Tree
{
public:
    treeNode<int> *root;
    Tree() {
        root = nullptr;
    }
    void createTree();
    void Preorder( treeNode<int> *p);
    void Postorder( treeNode<int> *p);
    void Inorder( treeNode<int> *p);
    void Levelorder( treeNode<int> *p);
    int countNode(treeNode<int> *p);
    bool binarySearch(treeNode<int> *p,int key);
    void insertBinary( treeNode<int> *p,int key );
    treeNode<int>*  RInsert( treeNode<int>* p, int key);
    static int Height( treeNode<int> *p);// 在 Height 函数被声明为 static 静态成员函数的情况下:
    // 静态成员函数属于类本身，而非类的实例，因此通过 类名::函数名 的方式调用是最规范的做法。
    treeNode<int>* InPre(treeNode<int>* cur);
    treeNode<int>* InSuc(treeNode<int>* cur);
    treeNode<int>* deleteBinary(treeNode<int>* p, int key);

};

void Tree::createTree()
{
    // ---- 初始化树的结构 ---
    treeNode<int>* ptr;
    treeNode<int>* temp; // 存储输入左右树结构
    int x;
    QueueLinkClass<treeNode<int> *> myQue;
    // ----- endl ------

    cout << "请输入根节点的值: ";
    cin >> x;
    root = new treeNode<int>(x); // 只要把根节点处理好了就可以了
    myQue.enQueue(root);

    // 输入规则：
    cout << "提示：输入-1表示该方向无节点" << endl;
    while (!myQue.isEmpty())
    {
        ptr = myQue.getFrontVal(); //  先获取队首元素
        myQue.deQueue();         // 再弹出队首元素

        // 处理左子节点
        cout << "请输入" << ptr->data << "的左子节点值: "; // 队列
        cin >> x;
        if (x != -1)
        {
            temp = new treeNode<int>(x);
            ptr->lchild = temp;
            myQue.enQueue(temp);
        }

        // 处理右子节点
        cout << "请输入" << ptr->data << "的右子节点值: "; // 队列
        cin >> x;
        if (x != -1)
        {
            temp = new treeNode<int>(x);
            ptr->rchild = temp;
            myQue.enQueue(temp);
        }
    }
}

void Tree::Preorder(treeNode<int> *p)
{
    if (p != nullptr)
    {
        cout << p->data << " "; // 访问根节点
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(treeNode<int> *p)
{
    if (p != nullptr)
    {
        Preorder(p->lchild);
        cout << p->data << " "; // 访问根节点
        Preorder(p->rchild);
    }
}

void Tree::Postorder(treeNode<int> *p)
{
    if (p != nullptr)
    {
        Preorder(p->lchild);
        Preorder(p->rchild);
        cout << p->data << " "; // 访问根节点
    }
}

void Tree::Levelorder( treeNode<int> *p)
{
    // 若树为空，直接返回
    if (p == nullptr) {
        return;
    }

    // 创建队列存储节点指针（使用前面实现的QueueLinkClass或STL的queue）
    QueueLinkClass<treeNode<int>*> q;

    // 根节点入队
    q.enQueue(p);

    // 队列不为空时循环
    while (!q.isEmpty()) {
        // 出队一个节点并访问其值
        treeNode<int>* current = q.getFrontVal();
        q.deQueue();
        cout << current->data << " ";

        // 若左子节点存在，入队
        if (current->lchild != nullptr) {
            q.enQueue(current->lchild);
        }

        // 若右子节点存在，入队
        if (current->rchild != nullptr) {
            q.enQueue(current->rchild);
        }
    }
    cout << endl;
}

int Tree::countNode(treeNode<int> *p)
{
    int x,y;
    if( p!=nullptr )
    {
        x = countNode(p->lchild);
        y = countNode(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;

}


bool Tree::binarySearch(treeNode<int> *p,int key) {

    if(p->data == key)
        return true;
    if(p->data > key)
        return binarySearch( p->lchild,key );
    else
        return binarySearch( p->rchild,key );

    return false;
}


void Tree::insertBinary(treeNode<int> *p,int key) {

    treeNode<int> * insertNode = new treeNode<int>(key);
    treeNode<int>* cur;
    if(p==nullptr)
    {
        root = insertNode;
        return ;
    }
    while( p!=nullptr)
    {
        cur = p; // 用来防止后面p指向了nullptr，cur用来指向最后一个节点
        if(p->data == key) return ;
        if(p->data < key)
        {
            p =p->rchild;
        } else
        {
            p =p->lchild;
        }
    }
    if(insertNode->data < cur->data)
    {
        cur->lchild = insertNode;
    } else
    {
        cur->rchild = insertNode;
    }

    return;
}



// 递归插入节点到二叉搜索树
treeNode<int>* Tree::RInsert(treeNode<int>* p, int key)
{
    // 基准条件：如果当前节点为空，创建新节点并返回
    if (p == nullptr)
    {
        return new treeNode<int>(key);
    }

    // 递归插入左子树（当key小于当前节点值时）
    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    // 递归插入右子树（当key大于当前节点值时）
    else if (key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }
    // 当key等于当前节点值时，不执行任何操作（避免重复插入）
    // 如需允许重复值，可修改为插入到右子树：p->rchild = RInsert(p->rchild, key);

    // 关键：返回当前节点指针，维持树的结构完整性
    return p;
}


int Tree::Height( treeNode<int> *p) {

    if(p==nullptr)
        return 0;
    int x = Height(p->lchild);
    int y = Height(p->rchild);
    return (x>y) ? x+1: y+1;
}

// 中序列 前驱 ： 左子树里面的最右子树
treeNode<int>* Tree::InPre(treeNode<int>* cur)
{
    while(cur && cur->rchild !=NULL)
        cur = cur->rchild;
    return  cur;
}

// 中序列 继承 ： 右子树里面的最左子树
treeNode<int>* Tree::InSuc(treeNode<int>* cur)
{
    while(cur && cur->lchild !=NULL)
        cur = cur->lchild;
    return  cur;
}

treeNode<int>* Tree::deleteBinary(treeNode<int>* p, int key)
{
    if(p==NULL) // 极端条件，如果是空
        return NULL;

    // 1. 通过递归查找目标节点
    if( key < p->data )
        p->lchild = deleteBinary(p->lchild,key);
    else if( key > p->data)
        p->rchild = deleteBinary(p->rchild, key );
    //2. 找到目标节点，执行删除操作
    else
    {   // 子情况1： 目标节点是叶子节点,返回一个空指针
        if(p->lchild==nullptr && p->rchild==nullptr)
        {
            treeNode<int>* toDelete = p;
            delete toDelete ;
            return nullptr;
        }

        // 子情况2： 目标节点只有一个左子树
        if(p->lchild !=nullptr && p->rchild ==nullptr )
        {
            p->data = p->lchild->data;
            p->lchild = nullptr;
            treeNode<int>* toDelete = p->lchild;
            delete toDelete;
            return p;
        }

        // 子情况3： 目标节点只有一个右子树
        if(p->lchild == nullptr && p->rchild != nullptr )
        {
            p->data = p->rchild->data;
            p->rchild = nullptr;
            treeNode<int>* toDelete = p->rchild;
            delete toDelete;
            return p;
        }

        // 子情况4：目标节点有两个子树（核心逻辑）
        // 根据子树高度选择前驱或后继节点替换
        if(Tree::Height(p->lchild) > Tree::Height(p->rchild))
        {
            //  左子树更高：使用中序前驱（左子树最右节点）
            treeNode<int>* temp = InPre(p->lchild);
            p->data = temp->data; // 复制前驱节点值
            // 递归删除前驱节点
            p->lchild = deleteBinary(p->lchild,temp->data);
        }
        else {
            // 右子树更高或等高：使用中序后继（右子树最左节点）
            treeNode<int>* temp  = InSuc(p->rchild);
            p->data = temp->data;
            // 递归删除后继节点
            p->rchild =deleteBinary(p->rchild, temp->data);
        }

    }

// 返回更新后的当前节点指针，维护树结构
    return p;
}

