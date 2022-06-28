#include<iostream>
using namespace std;
int n,k;
char chess[8][8];
int ans;
bool used[8];
void DFS(int start, int count)
{
	for (int i = 0; i < n; i++)
	{
		if (chess[start][i] == '#' && !used[i])
		{
			if (count == 1)
			{
				ans++;
			}
			else
			{
				used[i] = 1;
				for (int j = start + 1; j < n - count +2; j++)
				{
					DFS(j, count - 1);
				}
				used[i] = 0;
			}
		}
	}
}
void solution()
{
	while (cin>>n>>k) {
		if (n == -1 && k == -1) break;
			ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> chess[i];
		}
		memset(used, 0, sizeof(used));
		for (int i = 0; i <= n - k; i++)
		{
			DFS(i, k);
		}
		cout << ans << endl;
		}
}
int main()
{
	solution();
	return 0;
}