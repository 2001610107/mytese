
/*
 * 问题描述：给你一个字符串，请把字符串压缩的尽量短，并且输出最短的方案。例如：AAAAA可压缩为5(A). 
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 1412K Time: 110MS
 *
 * 解题方法1：设dp[i][j]表示折叠后的最短字串，l[i][j]表示dp[i][j]的长度。
  * dp[i][j]两种情况：1：直接折叠。2：合并两段。折叠次数越大，长度越短。枚举折叠次数，直接转移。
 *
*
 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：
 *
 * 心得体会 （可选）：
 */
/*
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 150;
char s[N], r[N], dp[N][N][N];
int l[N][N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

void fun(int a, int b) {
    if (a == b) {
        dp[a][b][0] = s[a];
        l[a][b] = 1;
        return;
    }
    for (int i = 1; i <= b - a; i++) {
        if ((b - a + 1) % i) continue;
        bool p = 1;
        for (int j = a + i; j <= b; j++) {
            if (s[j] == s[j - i]) continue;
            p = 0; break;
        }
        if (!p) continue;
        if (!l[a][a + i - 1]) fun(a, a + i - 1);
        sprintf(r, "%d", (b - a + 1) / i);
        strcpy(dp[a][b], r);
        l[a][b] = strlen(dp[a][b]);
        dp[a][b][l[a][b]++] = '(';
        strcat(dp[a][b], dp[a][a + i - 1]);
        l[a][b] += l[a][a + i - 1];
        dp[a][b][l[a][b]++] = ')';
        break;
    }
    for (int i = a; i < b; i++) {
        if (!l[a][i]) fun(a, i);
        if (!l[i + 1][b]) fun(i + 1, b);
        if (!l[a][b] || l[a][i] + l[i + 1][b] < l[a][b]) {
            strcpy(dp[a][b], dp[a][i]);
            strcat(dp[a][b], dp[i + 1][b]);
            l[a][b] = l[a][i] + l[i + 1][b];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    int l = strlen(s);
    fun(0, l - 1);
    cout << dp[0][l - 1] << endl;
    return 0;
}
*/
