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
    stackLinkClass<int> stLink(6);
    cout << "stLink.isEmpty()  " << stLink.isEmpty() << endl;
    stLink.push(11);
    stLink.push(22);
    stLink.push(33);
    stLink.display();

    return 0;
}