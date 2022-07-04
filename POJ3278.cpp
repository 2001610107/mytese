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