/*
 * 问题描述：大学举行周年会，有些人要参加，每个人都有个活跃度，但是不能让一个人和他的直接上司同时参加，已知这些人的直接上司，求最大的活跃度。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 692K Time: 94MS
 *
 * 解题方法1：用dp[i][0]表示以当前结点为根的子树且不选择当前点的最大值，dp[i][1]表示以当前结点为根且选择当前结点的最大值。那么转移方程为：dp[i][0] = sum(max(dp[j][1],dp[j][0]))（j是i的孩子结点），dp[i][1] = sum(dp[j][0])+a[i]。

 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */


#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 7000;
struct node
{
    int nex, to;
}edge[maxn * 2];
int n;
int a[maxn];
int bos[maxn];
int dp[maxn][3];
int head[maxn * 2];
int cnt;
void add(int x, int y)
{
    edge[cnt].to = y;
    edge[cnt].nex = head[x];
    head[x] = cnt++;
    edge[cnt].to = x;
    edge[cnt].nex = head[y];
    head[y] = cnt++;
}
void dfs(int key, int parent)
{
    for (int i = head[key]; i != -1; i = edge[i].nex)
    {
        int v = edge[i].to;
        if (v == parent)continue;
        dfs(v, key);
        dp[key][0] += max(dp[v][0], dp[v][1]);
        dp[key][1] += dp[v][0];
    }
    dp[key][1] += a[key];
}
int main()
{
    while (cin>>n)
    {
        for (int i = 1; i <= n; i++)cin>>a[i];
        int x, y;
        cnt = 0;
        memset(dp, 0, sizeof dp);
        memset(head, -1, sizeof head);
        while (cin>>x>>y && x && y)
        {
            add(x, y);
        }
        dfs(1, 0);
        cout<< max(dp[1][1], dp[1][0])<<endl;
    }
    return 0;
}
