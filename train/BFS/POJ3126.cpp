/*
 * 问题描述：给你两个四位素数a，b；每次可以花1dollar让a一个数位上的数字变换，但要保证每次变换后的数字还是一个素数，求问最少需要多少次变换让a变成b
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 280K Time: 157MS
 *
 * 解题方法1：因为是四位的素数，所以先对素数打表，然后进行BFS，每次进入队列的是八个只有一个数字不同的四位数，并且还要是素数就入队
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：审题不够仔细，忘记特殊测试打印“Impossible”
 *
 * 心得体会 （可选）：
 */

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 10005
bool prime[maxn];
void Isprime()
{
    int i, j;
    for (i = 1000; i <= maxn; i++) {
        for (j = 2; j < i; j++)
            if (i % j == 0) {
                prime[i] = false;
                break;
            }
        if (j == i) prime[i] = true;
    }

}
int  BFS(int first, int last)
{
    bool used[maxn];
    queue <int> q;
    int now, i, j, temp, now_temp, count[maxn], t[4];
    memset(used, false, sizeof(used));
    memset(count, 0, sizeof(count));
    q.push(first);
    used[first] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        t[0] = now / 1000;   //第一位
        t[1] = now % 1000 / 100;  //第二位
        t[2] = now % 100 / 10;    //第三位
        t[3] = now % 10;       //第四位
        //cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << " " << endl;
        for (j = 0; j < 4; j++)
        {
            temp = t[j];
            for (i = 0; i < 10; i++)
            {
                if (i != temp)
                {
                    t[j] = i;
                    now_temp = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
                    if (!used[now_temp] && prime[now_temp])
                    {
                        count[now_temp] = count[now] + 1;
                        used[now_temp] = true;
                        q.push(now_temp);
                    }
                    if (now_temp == last) return count[now_temp];
                }
            }
            t[j] = temp;
        }
        if (now == last) return count[now];
    }
    return -1;
}
int main()
{
    int n, first, last, count;
    cin >> n;
    Isprime();
    while (n--)
    {
        cin >> first >> last;
        count = BFS(first, last);
        if (count != -1)
        {
            cout << count << endl;
        }
        else cout << "Impossible" << endl;
    }
}
