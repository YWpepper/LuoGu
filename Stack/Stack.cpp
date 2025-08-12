#include"Stack.h"



void addressCom(stackArrayClass<int> st){
    int *buttom = st.getStack();
    int *up = st.getTop();
    cout << "地址比较测试：" << endl;
    cout << "buttom 地址: " << buttom << endl;
    cout << "up 地址: " << up << endl;
    cout << "buttom < up " << ( buttom < up )<< endl;
    cout << "buttom > up " << ( buttom > up )<< endl;
    cout << "buttom - up " << (buttom - up ) << endl;
    cout << "up - buttom " << (up - buttom ) << endl;
}




bool paranthesisMacthing(stackLinkClass<char> stLink , string s)
{
    int len = s.size();
        // 1. 如果一开始就是右括号，一定不匹配
    if(s[0] == ')' || s[0] == ']' || s[0] == '}'){
            return false;
    }
    // 2. 撰写遍历匹配
    for(int i =0;i<len; i++)
    {
        // cout << "i " << i << " s[i] is " << s[i] <<  endl;
        // a 如果是左括号，就push into 
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        { 
            stLink.push(s[i]);
            stLink.display();
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
                cout << "i is " << endl; 
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



bool isOperated(char x)
{
    if(x == '+' ||  x=='-' || x=='*' || x=='/' || x=='(' || x==')')
        return true;
    else 
        return false;

}


int checkRank(char x)
{
    if(x == '+' ||  x=='-' || x == '(')
        return 1;
    else if(  x=='*' || x=='/')
        return 2;
    else if( x == ')')
        return 3;
}


char* convert(char *infix)
{
    stackLinkClass<char> st; // 空栈存储操作符号+括号
    char *postFix = new char[strlen(infix)+1];  // 初始化空列表
    int i=0,j=0;
    for(i=0; infix[i] != '0' ; i++ )
    {
       cout << "i is " << i  << endl;
        // 1. 检查是否是操作符,如何是操作符
        if(isOperated( infix[i] ))
        {
            
            // 1 假设是空栈
            if(st.isEmpty()) // 空栈就不需要比较了
            {
                st.push( infix[i] ); // 正常push
                continue;
            }
            char stTop = ( st.getTop() )->getVal(); 
            // 2 假设是右括号
            if( checkRank(infix[i]) == 3 )
            {
                while( (st.getTop())->getVal() !='(')
                {
                    postFix[j] = st.pop();
                    j++;
                }
                st.pop();
                // 需要把‘(’ pop出来
                continue;
            }

            // 3. 检查当前栈顶元素与自己的关系
            if( checkRank( infix[i] ) >= checkRank(stTop) ){ 
                st.push( infix[i] ); // 正常push
                continue;
            }else
            {
                while(st.getTop()!= nullptr) // 清空整个栈
                {
                    postFix[j] = st.pop();
                    j++;
                }
                st.push( infix[i] );  // 然后再把当前存入
                continue;
            }
        }else
        {
            postFix[j] = infix[i]; // 将操作符号放入栈里
            j++;
            continue;
        }
    }

    if(!st.isEmpty())
    {
        while(st.getTop()!= nullptr) // 清空整个栈
            {
                postFix[j] = st.pop();
                j++;
            }
    }
    
    return postFix;
}





int main()
{
    /**
     * stack 的数组类测试
     */
    // stackArrayClass<int> st(6);
    // cout  << st.getSize() << endl;
    // cout << st.isEmpty() << endl;
    // // cout << "getTop is "<< st.getTop() << endl;
    // // cout << "getStack is " << st.getStack() << endl;
    // int arr[] = {11,22,33,45,54};
    // cout << "sizeof(arr)/sizeof(arr[0]) is " << sizeof(arr)/sizeof(arr[0]) << endl;
    // for(int i=0 ;i <sizeof(arr)/sizeof(arr[0]) ; i++)
    //     st.push(arr[i]);
    // st.display();
    // // st.pop();
    // st.display();
    // st.peak(5);
    // addressCom(st);
    
    /**
     * stack 的链表初始化
    */
    // stackLinkClass<int> stLink(6);
    // cout << "stLink.isEmpty()  " << stLink.isEmpty() << endl;
    // stLink.push(11);
    // // stLink.push(22);
    // // stLink.push(33);
    // stLink.display();
    // stLink.pop();
    // stLink.display();



    /**
     * 链表的算法应用1 ： 检测括号的匹配性质
     */
    // string s;
    // getline(cin, s);  // 从键盘读取一行
    // stackLinkClass<char> stLink(s.size());
    // bool flag = paranthesisMacthing(stLink,s);
    // if(flag) cout << "YES" << endl;
    // else  cout << "NO" << endl;


    /**
     * 链表的算法应用2 ： 编译原理的前后缀
     */
    // string s;
    // a+b*c-(d/e)
    char s[100] = "a+b*c-(d/e)0";
    // cin.getline(s,100);
    char *result[150];
    *result = convert(s);
    cout << result[0] << endl;
    // for(int i=0 ;i<strlen(s); i++)
    // {
    //     cout << "result is " << result[i] << endl;   
    // }

    return 0;
}