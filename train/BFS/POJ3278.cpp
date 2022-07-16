/*
 * 问题描述：农夫在x点牛在y点，农夫前进或者后退花费一分钟，前进两倍花费2分钟，求花费最少的时间抓住牛
 *
 * 提交状态：AC
 *
 * AC 结果： Memory: 1000K Time: 72MS
 *
 * 解题方法1：由于奶牛的位置是不变的，农场主有三种行走方式：向前走一格，向后走一格，从x的位置传送到2x的位置。通过BFS的方式，采用队列的数据结构形式，首先将初始位置入队，设步数为0；
 * 其次分别按三个方式行走，当所达到的位置没有达到过时，入队，并且步数+1。注意：当农场主的位置在奶牛的前面时只能向后走
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：3
 *
 * 错误原因 （可选）：对到达过的位置忘记进行标记已访问过
 *
 * 心得体会 （可选）：
 */


#include<iostream>
#include<queue>
using namespace std;
#define N 100010
int stamp[N];
bool used[N];
int dir[3];
void BFS(int n, int k)
{
	queue<int>q;
	int head;
	q.push(n);
	used[n] = true;
	stamp[n] = 0;
	while (!q.empty())
	{
		head = q.front();
		q.pop();
		if (head == k)
		{
			cout << stamp[k] << endl;
			break;
		}
		dir[0] = head - 1;
		dir[1] = head + 1;
		dir[2] = head * 2;
		for (int i = 0; i < 3; i++)
		{
			if (dir[i] >= 0 && dir[i] < N && used[dir[i]] == false)
			{
				used[dir[i]] = true;
				stamp[dir[i]] = stamp[head] + 1;
				q.push(dir[i]);
				if (dir[i] > k)
					break;
			}
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	BFS(n,k);
}
