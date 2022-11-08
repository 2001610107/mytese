/*
 * ��������������һ�����������ڵ�Ϊn��n<=10000������ɾ����Щ�ڵ����ʹ����ͼ�е�ÿһ����ͨ��֧�Ľڵ�����������С��n/2
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 840K Time: 110MS
 *
 * ���ⷽ��1�����ÿ���ڵ�Ķ��ӽڵ㣬ÿ����Ϊ���������Ľڵ���dp[i]��Ȼ�󿼲�ÿһ���㣬���n-dp[i]<=n/2��
 �Լ���i��ÿһ������Ϊ���������Ľڵ�����dp[u]<=n/2����ô��������������
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������8
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
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
    dp[u] = 0;//�Ӻ���
    for (i = 0; i < cnt; i++)
    {
        v = p[u][i];
        if (v == fa)continue;
        int ans = dfs(v, u);
        mson = max(mson, ans);//���ӽڵ����������
        sum += ans;///��u Ϊ�����к�����
    }
    dp[u] = max(n - sum, mson);///ɾ��u�ڵ㣬
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
