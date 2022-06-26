/*
 * 问题描述：
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 244K Time: 16MS
 *
 * 解题方法1：
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include<iostream>
#define maxn 27
using namespace std;
struct path {
	int x;
	int y;
}path[maxn];
bool used[maxn][maxn];
bool success = false;
int q, p;
int dx[8] = { -1,1,-2,2,-2,2,-1,1 };///x为行数，纵坐标
int dy[8] = { -2,-2,-1,-1,1,1,2,2 };///y为列数，横坐标
void dfs(int x, int y, int num)
{
	path[num].x = x;
	path[num].y = y;
	if (num == p * q - 1)
	{
		success = true;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx >= 1 && nx <= p && ny >= 1 && ny <= q && !used[nx][ny] && !success) {
			used[nx][ny] = true;
			dfs(nx, ny, num + 1);
			//搜索失败,当前位置的访问标记要变回false
			used[nx][ny] = false;
		}
	}
	
}
void solution(int n)
{
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		success = false;
		cin >> p >> q;
		memset(used, false, sizeof(used));
		used[1][1] = true;
		dfs(1, 1, 0);
		cout << "Scenario #" << i << ":\n";
		if (!success) 
		{
			cout<<"impossible\n";
		}
		else 
		{
			for (int j = 0; j < p * q; j++)
			{
				cout << char(path[j].y + 'A' - 1 )<< path[j].x;
			}
			cout << endl;
		}
		cout << endl;
	}
}
int main()
{
	int n;
	cin >> n;
	solution(n);
}
