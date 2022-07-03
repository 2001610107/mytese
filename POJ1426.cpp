/*
 * 问题描述：给出一个整数n ( 1 < = n < = 200 ) n (1 <= n <= 200)n(1<=n<=200)。求出任意一个它的倍数m，要求m必须只由十进制的 0 或 1 组成。
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 2264Time: 47MS
 *
 * 解题方法1：由于需要找一个全是由 0 和 1 组成的数字，让1分两个方向进行递归，一个是乘 10，一个是乘 10 加  1，让1或0进队列
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：8
 *
 * 错误原因 （可选）：使用队列<queue>中的常用函数导致超出时间限制
 *
 * 心得体会 （可选）：对宽度优先搜索有进一步认识
 */
方法1：#include<iostream>
using namespace std;
int n;
long long now, q[1000000]; 
void bfs()
{
	int head, tail;
	head = 0;
	tail = 1;
	q[tail] = 1;
	while (head < tail)
	{
		head++;
		now = q[head];
		now = now * 10;
		if (now % n == 0)
		{
			break;
		}
		q[tail++] = now;
		q[tail++] = now + 1;
	}
	printf("%I64d\n", now);
}
int main()
{
	while (cin>>n && n != 0)
	{
		bfs();
	}
	return 0;
}
方法2：
#include "iostream"
#define ll long long
using namespace std;
int n, flag;
ll m;

void DFS(int x, ll m) {
    if (x > 19 || flag == 1)
        return;
    if (m % n == 0) {
        flag = 1;
        cout << m << endl;
        return;
    }
    DFS(x + 1, m * 10);
    DFS(x + 1, m * 10 + 1);

}

int main() {
    while (cin >> n) {
        if (n == 0)
            break;
        flag = 0;
        DFS(1, 1);
    }
}
