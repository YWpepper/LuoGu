#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool checkValid(string const &s, stack<char> &sk)
    {
        for (int i = 0; i < s.size(); i++)
        {
            // 先获取当前元素
            char temp = s[i];
            if (temp == '(' || temp == '[' || temp == '{')
            {
                // 如果是左括号，就进栈
                sk.push(temp);
                continue;
            }
            if (temp == ')' || temp == ']' || temp == '}')
            {
                // 如果temp是右括号则开始是匹配
                // 但是首先要检查是否为空栈，即防止有多余的括号
                if (sk.empty())
                    return false;
                char com_S = sk.top(); // 栈里面存的都是左括号
                sk.pop();
                if (com_S == '(' && temp == '}')
                    return false;
                if (com_S == '(' && temp == ']')
                    return false;
                if (com_S == '{' && temp == ')')
                    return false;
                if (com_S == '{' && temp == ']')
                    return false;
                if (com_S == '[' && temp == ')')
                    return false;
                if (com_S == '[' && temp == '}')
                    return false;
            }
        }
        if(sk.empty())
            return true;
        else    
            return false;
    }

    bool isValid(string s)
    {
        stack<char> sk;
        return checkValid(s, sk);
    }
};

int main()
{
    string str = "()[]{}";
    Solution mySolution;
    if (mySolution.isValid(str))
        cout << "true" << endl;
    else
        cout << "fasle" << endl;
}