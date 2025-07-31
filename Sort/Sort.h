#include <iostream>
#include <string>
#include <stack>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void display(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int len)
{
    int cnt = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            cnt++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Total caculate is: " << cnt << endl;
}

void bubbleSort_re(int arr[], int len)
{
    int cnt = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++)
        {
            cnt++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1; // 只要执行了一次交换，就说明这个列表还没有排好序列；
            }
        }
        // 如果执行完一轮之后，flag依然等于0，则可以证明已经排序成功，可以返回结果；
        if (flag == 0)
            break;
    }
    cout << "Total caculate is: " << cnt << endl;
}

void insertSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}