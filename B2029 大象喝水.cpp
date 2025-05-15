/*
题目描述
一只大象口渴了，要喝 20 升水才能解渴，但现在只有一个深 h 厘米，底面半径为 r 厘米的小圆桶 （h 和 r 都是整数）。问大象至少要喝多少桶水才会解渴。

Update：数据更新，这里我们近似地取圆周率 π=3.14。

输入格式
输入有一行：包行两个整数，以一个空格分开，分别表示小圆桶的深 h 和底面半径 r，单位都是厘米。

输出格式
输出一行，包含一个整数，表示大象至少要喝水的桶数。

输入输出样例
输入 #1复制

23 11
输出 #1复制
*/
#include "stdio.h"
#include <bits/stdc++.h>
#define PI 3.14
#define V 20000     // 1L = 10000 cm^3

using namespace std;

int main()
{
    int h, r;
    scanf("%d %d",&h, &r);
    // printf("%d, %d",h, r);
    int nums = int(V / (PI * r * r * h)) + 1;
    cout << nums << endl;
}

