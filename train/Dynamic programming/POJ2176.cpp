
/*
 * ��������������һ���ַ���������ַ���ѹ���ľ����̣����������̵ķ��������磺AAAAA��ѹ��Ϊ5(A). 
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 1412K Time: 110MS
 *
 * ���ⷽ��1����dp[i][j]��ʾ�۵��������ִ���l[i][j]��ʾdp[i][j]�ĳ��ȡ�
  * dp[i][j]���������1��ֱ���۵���2���ϲ����Ρ��۵�����Խ�󣬳���Խ�̡�ö���۵�������ֱ��ת�ơ�
 *
*
 * ���ⷽ��2 ����ѡ����
 *
 * ���������7
 *
 * ����ԭ�� ����ѡ����
 *
 * �ĵ���� ����ѡ����
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
