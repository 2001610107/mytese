/*
 * 问题描述：给定一棵无向树，节点为n（n<=10000），问删除那些节点可以使得新图中的每一个连通分支的节点数都不超过小于n/2
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 840K Time: 110MS
 *
 * 解题方法1：求出每个节点的儿子节点，每个点为根的子树的节点数dp[i]，然后考察每一个点，如果n-dp[i]<=n/2，
 以及以i的每一个儿子为根的子树的节点数都dp[u]<=n/2，那么这个点就满足条件
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：8
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 10002;
int dp[maxn], sum[maxn], n, flag;
vector<int>p[maxn];
int dfs(int u, int fa)
{
    int  i, j, v, sum = 1, mson = 0;
    int cnt = p[u].size();
    dp[u] = 0;//子孩子
    for (i = 0; i < cnt; i++)
    {
        v = p[u][i];
        if (v == fa)continue;
        int ans = dfs(v, u);
        mson = max(mson, ans);//孩子节点中最大孩子数
        sum += ans;///以u 为根所有孩子数
    }
    dp[u] = max(n - sum, mson);///删除u节点，
    return sum;
}
int main()
{
    while (cin >> n)
    {
        int i, j, a, b;
        flag = 0;
        for (i = 1; i <= n; i++)p[i].clear();
        for (i = 1; i < n; i++)
        {
            cin >> a >> b;
            p[a].push_back(b);
            p[b].push_back(a);
        }
        dfs(1, 0);
        for (i = 1; i <= n; i++)
        {
            if (2 * dp[i] <= n)
            {
                flag = 1;
                cout << i << endl;
            }
        }
        if (!flag)cout<<"NONE\n";
    }
    return 0;
}
