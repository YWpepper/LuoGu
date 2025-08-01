#include"QueueClass.h"





int main(){

    // QueueClass<int> myQue(10);
    // for( int i=0; i<3; i++)
    // {
    //     myQue.enQueue(i);  
    // }
    // myQue.display();
    // int x = myQue.deQueue();
    // cout << "after delete" << endl;
    // myQue.display();



    /*
    测试： 队列链表
    */
    // QueueLinkClass<int> qlink(100);
    // for( int i=0; i<5; i++)
    // {
    //     qlink.enQueue(i);  
    // }
    // qlink.display();




    /*
     测试：队列经典算法题目 机器翻译
    */
   int size=0; 
   int inputLen = 0;
   cin >> size >> inputLen;
   // 初始化队列，初始化数组
   QueueClass<int> myQue(size+1);
   int *req = new int[inputLen];
   memset(req,0,inputLen);
   // 初始化一个哈希表
    int hash[1005] ={0};
    // 初始化基数表
    int cnt=0;
   // 输入数组
   for(int i=0 ;i < inputLen ; i++)
   {
        
        cin >> req[i];
        int cinTemp = req[i];
        if(! hash[cinTemp])
        {
            cout << "查找单词" << cinTemp << endl;
            // 如果没有出现过，才可以往里面push
            hash[cinTemp]=1;
            // 检查队列是否满了
            if(myQue.isFull())
            {
                // 满了需要pop出来再放入
                int temp = myQue.deQueue();
                // pop 的同时需要重新设置哈希表的编号
                hash[cinTemp]=0;
                myQue.enQueue(cinTemp);
                // cout << "调入内存" << cinTemp << endl;
            }else{
                // 没有满则直接放入
                myQue.enQueue(cinTemp);
                // cout << "调入内存" << cinTemp << endl;
            }
            cnt++;
            // cout << "queque display: " << endl;
            myQue.display();
        }
   }
   cout << "cnt is " << cnt <<  endl;

//    cpuProgress(myQue, req);



}