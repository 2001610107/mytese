

/*
 * 问题描述：给出两列数，要求对上下相同的数进行连线,1、一个数最多连一条线。2、一条线必须且仅与一条线相交。
求最多可以连出几条线？
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 320K Time: 0MS
 *
 * 解题方法1：f[i][j]表示用a用前i个数,b用前j个数的值，f[i][j]=max(f[i][j−1],f[i−1][j])
如果能找到 x∈[1,i)x∈[1,i)和 y∈[1,j)y∈[1,j) 满足 a[x]=b[j]b[y]=a[j]a[x]=b[j]b[y]=a[j]（就是上下匹配）
那么f[i][j]=max(f[i][j−1],f[i−1][j],f[i−1][j−1]+2)

 * 解题方法2 （可选）：
 *
 * 出错次数：8
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
 
 /*
f[i][j]=max(f[i-1][j],f[i][j-1],f[i-1][j-1]+2)
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110;
int f[N][N];

int main()
{
	int t, n, m;
    int a[N],b[N];
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(f, 0, sizeof f);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= m; i++) cin >> b[i];
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int x, y;
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
				if (a[i] == b[j]) continue;
				for ( x = i - 1; x >0; x--) if (a[x] == b[j]) break;
				for ( y = j - 1; y >0; y--) if (b[y]==a[i]) break;
				if (!x || !y) continue;
				f[i][j] = max(f[i][j], f[x - 1][y - 1] + 2);
			}
		}
		cout << f[n][m] << endl;
	}

}

