/*
题目描述
学校和 yyy 的家之间的距离为 s 米，而 yyy 以 v 米每分钟的速度匀速走向学校。

在上学的路上，yyy 还要额外花费 10 分钟的时间进行垃圾分类。

学校要求必须在上午 8:00 到达，请计算在不迟到的前提下，yyy 最晚能什么时候出门。

由于路途遥远，yyy 可能不得不提前一点出发，但是提前的时间不会超过一天。

输入格式
一行两个正整数 s,v，分别代表路程和速度。

输出格式
输出一个 24 小时制下的时间，代表 yyy 最晚的出发时间。

输出格式为 HH:MM，分别代表该时间的时和分。必须输出两位，不足前面补 0。

输入输出样例

输入 #1复制
100 99
输出 #1复制
07:48
*/

#include <stdio.h>
#define ADDITION_MIN 10
#define Min_In_Hour 60
#define Min_In_Day (24 * Min_In_Hour)

int main()
{
    int s,v;
    int t_start = 0, t_walk = 0;
    scanf("%d %d", &s, &v);

    // 速度能被路程整除
    if(s % v == 0)
        t_walk = s / v;
    else 
        t_walk = (s / v) + 1;       // 不能被整除的情况就向上取多一位

    // t_start < 0

    t_start = 8 * Min_In_Hour - ADDITION_MIN - t_walk;
    if(t_start < 0)
        t_start += Min_In_Day;

    printf("%02d:%02d", t_start / Min_In_Hour, t_start % Min_In_Hour);
}