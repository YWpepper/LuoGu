// https://www.luogu.com.cn/problem/P1241 
// 目前还是 wrong answer

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node():next(nullptr){}
    Node(T val):data(val),next(nullptr){}
    ~Node(){}
    T getVal(){return data;}
    T getNode(){return next;}
};


template<class T>
class stackLinkClass{

private:

    Node<T>* top;
    Node<T>* s;
    int size;

public:

    stackLinkClass():top(nullptr),s(nullptr),size(0){}
    stackLinkClass(int sz):top(nullptr),s(nullptr),size(sz){
        // cout << "initial successfuly" << endl;
    }

    int getSize(){return size;}
    Node<T>* getTop(){return top;}
    Node<T>* getSatck(){return s;}

    bool isEmpty(){
        if(top == nullptr || top == s-1 )
            return true;
        return false;
    }

    bool isFull(){
        if(top -size + 1 == s )
        return true;
        return false;
    }


    void push(T val){
        if(isFull())
            return;
        
        // 一定要动态开辟空间
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty())
        {
            s = top = newNode;
            // cout << "push " << newNode->data << endl;
            return;
        }
        
        // 正常含有数值的情况的话
        // cout << "push " << newNode->data << endl;
        newNode->next = top;
        top =  newNode;
    }


    void display(){

        Node<T>* ptr = top ; 
        if(ptr==nullptr)
        {
             return ;
        }
        
        while(ptr!=nullptr)
        {
            cout << ptr->data;
            ptr = ptr->next;
        }
        // cout << endl;
        return ;
    }

    void Reverse(){

        Node<T>* p = top ; 
        Node<T>* q = top->next ; 
        Node<T>* r = top->next->next ; 
        p->next = nullptr;
        while(r!=nullptr)
        { 
            q->next = p ;
            p = q;
            q = r ;
            r = r->next;
        }
        top = q;
        top->next = p;

    }

    T pop(){

        Node<T>* ptr = top ; 
        if (ptr == nullptr)
            return NULL;
    
        Node<T>* toDelete = ptr;
        T DeleteData = toDelete->data;
        // cout << "POP: " << toDelete->data << endl;
        top = top->next;
        delete toDelete;
        return DeleteData;
        }
};





bool paranthesisMacthing(stackLinkClass<char> stLink , string s)
{
    int len = s.size();
    // 1. 如果一开始就是右括号，一定不匹配
    if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false;
    // 2. 撰写遍历匹配
    for(int i =0;i<len; i++)
    {
        // a 如果是左括号，就push into 
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        { 
            stLink.push(s[i]);
            continue;
        }
        
        // b 如果是右括号 就pop out 出来对比
        if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
           char tstr;
           if(stLink.isEmpty()==0)  // 判断栈首先不能是空的
                tstr = stLink.pop();
            else // 如果已经是空的栈了，那就说明有问题额；
            {
                return false;
            }
            // 条件匹配
            if(s[i] == ')' && tstr == '(')
                continue;
            if(s[i] == ']' && tstr == '[')
                continue;
            if(s[i] == '}' && tstr == '}')
                continue;
            // 如果由于stlink已经是空的了，那就说明多了一个右括号
            return false;
        }
    }

     // 到最后栈里面应该没有元素了；
    if(stLink.isEmpty()) return true;
    else return false; // 否则就是有多的左括号；
}


bool checkCompare(char R, char L )
{
    if(R =='(' && L ==')')  return true;
    if(R =='[' && L ==']') return true;
    if(R =='{' && L =='}')  return true;

    return false;

}

char getMatch(char now)
{
    if(now =='(')
        return ')';
     if(now ==')')
        return '(';

    if(now == '[')
        return ']';
    if(now == ']')
        return '[';

    if(now =='{')
        return '}';
    if(now =='}')
        return '{';

}

bool checkLeft(char str)
{
    if ( str=='[' || str=='{' || str=='(')
        return true;
    else  return false;
}



stackLinkClass<char> BalanceParanthesis(stackLinkClass<char> stLink ,string s)
{
    int len = s.size();

    for(int i = 0 ; i<len; i++)
    {
        char R = s[i];
        char L = s[i+1];
        // 检查是否匹配，如果匹配，将第 i 以及 i+1 存入栈
        if(checkCompare(s[i],s[i+1]))
        {
            stLink.push(s[i]);
            stLink.push(s[i+1]);
            i++;
        }else
        {
            if(checkLeft(s[i]))
            {
                stLink.push(R);
                char temp = getMatch(R);
                stLink.push(temp);
            }else{
                char temp = getMatch(R);
                stLink.push(temp);
                stLink.push(R);
            } 
        }
    }
    return stLink;
}





int main(){

    string s;
    getline(cin, s);  // 从键盘读取一行
    stackLinkClass<char> stLink(s.size()*4);
    stLink = BalanceParanthesis(stLink,s);
    // stLink.display();
    stLink.Reverse();
    stLink.display();

    // if(flag) cout << "YES" << endl;
    // else  cout << "NO" << endl;

    return 0;
}