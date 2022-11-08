/*
 * 问题描述：在一天 n 个小时中取 b 个小时，使权值和最大，b 个小时可分成若干段，每段的第一个小时的权值不计入总和，第 n个小时与第一个小时相连

 * 提交状态： AC
 *
 * AC 结果： Memory: 316K Time: 94MS
 *
 * 解题方法1：记f[i][j][0] 为前i个小时中睡了j个小时且第i个小时不在睡，f[i][j][1] 为前i个小时中睡了j个小时且第i个小时在睡

转移方程：

f[i][j][0]=max(f[i−1][j][0],f[i−1][j][1])
f[i][j][1]=max(f[i−1][j−1][0],f[i−1][j−1][1]+w[i])​

因为首尾相连，所以第 n nn 个小时会影响第一个小时
当第 n个小时没有睡：f[1][0][0]= f[1][1][1] = 0, f[n][b][0]
当第 n个小时在睡:f[1][0][0]=0,f[1][1][1]=w[1]，结果为f[n][b][1]
取最大值

 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
#include<iostream>
using namespace std;
const int N = 4000;
int w[N];
int f[N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++) cin >> w[i];
    memset(f, 0xc0, sizeof f);
    f[0][0] = f[1][1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = min(i, b); j >= 0; j--) {
            f[j][0] = max(f[j][0], f[j][1]);
            if (j) f[j][1] = max(f[j - 1][0], f[j - 1][1] + w[i]);
        }
    int res = f[b][0];
    memset(f, 0xc0, sizeof f);
    f[0][0] = 0, f[1][1] = w[1];
    for (int i = 2; i <= n; i++)
        for (int j = min(i, b); j >= 0; j--) {
            f[j][0] = max(f[j][0], f[j][1]);
            if (j) f[j][1] = max(f[j - 1][0], f[j - 1][1] + w[i]);
        }
    res = max(res, f[b][1]);
    cout << res << endl;
    return 0;
}
