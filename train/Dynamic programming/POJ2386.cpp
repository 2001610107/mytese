/*
 * 问题描述：给定一个n*m的地图，‘W’表示积水，‘.’表示空地，积水是八连通的，求有多少个积水块。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 664K Time: 47MS
 *
 * 解题方法1：扫描一遍图，每遇到一个‘W’计数器加一，并深搜或者广搜把相邻的‘W’填充为‘.’，直到图上没有积水。
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：8
 *
 * 错误原因 （可选）：没有处理好换行符
 *
 * 心得体会 （可选）：
 */

 


#include <iostream>
#include <cstdio>
using namespace std;

char field[1001][1001];
int n, m;
void DFS_floodfill(int x, int y)   
{
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
        {
            int xx = x + dx;
            int yy = y + dy;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && field[xx][yy] == 'W')
                DFS_floodfill(xx, yy);
        }
}
int main()
{
    int i, j, ans;
    while (cin>>n>>m)
    {
        getchar();
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
                cin>>field[i][j];
            getchar();
        }
        ans = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if (field[i][j] == 'W')
                {
                    DFS_floodfill(i, j);
                    ans++;
                }
        cout << ans << endl;
    }
    return 0;
}
