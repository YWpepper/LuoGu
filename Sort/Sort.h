#include <iostream>
#include <string>
#include <stack>
#include <vector>

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

void display2(vector<int> arr, int len)
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
    int cnt = 0;
    for (int i = 1; i < len; i++)
    {
        bool flag = true;
        for (int j = i; j >= 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                flag = false;
                cnt++;
            }
            // 只要跟前一个数值比较的时候满足排序要求，则就不需要再跟前面的前面交换了
            if (flag)
                break;
        }
    }
    cout << "Total caculate is: " << cnt << endl;
}

void selectSort(int arr[], int len)
{
    int key_idx = 0;
    for (int i = 0; i < len; i++)
    {
        // 二重循环的目的只是为了找到最小数值的索引，然后插入到第 i 个位置
        for (int j = i; j < len; j++)
        {
            if (arr[key_idx] > arr[j])
            {
                key_idx = j;
            }
        }
        // 遍历完一轮之后只执行一次的交换操作
        swap(arr[key_idx], arr[i]);
    }
}

void shellSort(int arr[], int len)
{
    int slide = 0;
    int shellCNT = 0;
    // slide 用来控制间隔
    for (slide = len / 2; slide > 1; slide = slide / 2)
    {
        cout << "slide is " << slide << endl;
        // 用来按照[slide=2, idx=0], [slide=2, idx=1],[slide=2, idx=2]···
        for (int idx = 0; idx + slide < len; idx++)
        {
            for (int j = idx; j + slide < len; j += slide)
            {
                if (arr[idx] > arr[idx + slide])
                {
                    shellCNT++;
                    swap(arr[idx], arr[idx + slide]);
                    cout << "swap " << arr[idx] << " " << arr[idx + slide] << endl;
                }
            }
        }
    }
    cout << "shellCNT is " << shellCNT << endl;
    cout << "before slide is 1: " << endl;
    display(arr, len);
    cout << "when slide is 1: " << endl;
    insertSort(arr, len);
}

int partition(vector<int> &arr, int l_idx, int r_idx)
{
    int pivot = arr[l_idx];
    int r=l_idx+1, l=l_idx+1;
    while(r < r_idx)
    {
        // 这里是双指针的条件划分设置的地方
        if(arr[r] <= pivot)
        {
            swap(arr[r], arr[l]);
            l++;
        }
        r++;
    }
    cout << "l index is " << l << endl;
    swap(arr[l-1],arr[l_idx]);
    return l; // 即返回当前处理完的index
}



int partition2(vector<int> &arr, int l_idx, int r_idx)
{
    int pivot = arr[l_idx];
    int l=l_idx,r = r_idx;
    do {
        // 从左边开始找，直到找到大于 标准
        do {
            l++;
        }
        while(arr[l] <= pivot);
        // 从右边开始找，直到找到小于 标准
        do {
            r--;
        } while(arr[r] > pivot);
        // 交换位置
        swap(arr[l],arr[r]);
    } while(l<r);
    cout << "l is " << l << " R is " << r << endl;
    // 最后一步是
    // swap(pivot,arr[l--]);

}



void quickSort()
{

}