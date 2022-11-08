/*
 * ������������ѧ��������ᣬ��Щ��Ҫ�μӣ�ÿ���˶��и���Ծ�ȣ����ǲ�����һ���˺�����ֱ����˾ͬʱ�μӣ���֪��Щ�˵�ֱ����˾�������Ļ�Ծ�ȡ�
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 692K Time: 94MS
 *
 * ���ⷽ��1����dp[i][0]��ʾ�Ե�ǰ���Ϊ���������Ҳ�ѡ��ǰ������ֵ��dp[i][1]��ʾ�Ե�ǰ���Ϊ����ѡ��ǰ�������ֵ����ôת�Ʒ���Ϊ��dp[i][0] = sum(max(dp[j][1],dp[j][0]))��j��i�ĺ��ӽ�㣩��dp[i][1] = sum(dp[j][0])+a[i]��

 * ���ⷽ��2 ����ѡ����
 *
 * ���������7
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
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
