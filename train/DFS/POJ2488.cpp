/*
 * 问题描述：一个棋盘，问能不能以马的跳法不重复、无遗漏地将棋盘遍历一遍。如果可以的话，按照字典序输出排列在先的一条路径。
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory: 244K Time: 16MS
 *
 * 解题方法1：.棋盘是p行q列的，行用数字标识，列用大写字母标识，但是输出时，先输出了大写字母，然后是数字，所以把图翻转一下，看作q行p列的，这样就可以先行后列输出。
 * 按照0-7的顺序进行移动，判断是否达到搜索条件（请注意，此处除了需要满足不跳出棋盘外，还需要满足下一个点未被访问和还没有成功遍历整个棋盘两个条件）。
 * 如果是，进入if语句，标记(nx,ny)已被访问，继续dfs，将(nx,ny)的访问标记删除。
 * 不断dfs过程中，发现某一位置的下一步的八个位置要么在来的路上被访问过了，要么出界了，且此时整个棋盘还未遍历完，这说明，这条路径是不通的，那么在结束本次递归的时候，
 * 需要将原来标记的访问删除掉，以免在尝试另外一种走法时产生错误，因为这个位置的访问与否直接影响了下一条路径搜索的结果。
 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：学会对dfs进行四小步：“当前操作、结束条件、搜索条件、是否有回溯操作”来进一步掌握dfs
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
