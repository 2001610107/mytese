/*
 * 问题描述：农夫在x点牛在y点，农夫前进或者后退花费一分钟，前进两倍花费2分钟，求花费最少的时间抓住牛
 *
 * 提交状态：
 *
 * AC 结果： Memory: 160K Time: 1110MS
 *
 * 解题方法1：
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：0
 *
 * 错误原因 （可选）：
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
