
/*
 * 问题描述：有 N (N <= 50000)个单词（每个单词长度不超过50），问组成长度不超过100的目标串最少要用多少个单词。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 3204K Time: 110MS
 *
 * 解题方法1：状态：dp[i] 表示组成前 i 个字符所要用的最少单词数

状态转移方程：dp[i + wLen - 1] = min(dp[i + wLen - 1], dp[i - 1] + 1)
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：10
 *
 * 错误原因 （可选）：单词可以重复使用。
 *
 * 心得体会 （可选）：
 */
#include<iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAXN = 50000 + 10;
const int MAXW = 50 + 10;
const int MAXT = 100 + 10;
const int INF = 0x3f3f3f3f;
const char* h = "22233344115566070778889990";

int N;
char s[MAXT];
char word[MAXN][MAXW], buf[MAXN][MAXW];
int dp[MAXT];
int path[MAXT];
bool first;

void Read()
{
 
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> word[i];
    }
}

void Init()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; word[i][j] != '\0'; ++j)
        {
            buf[i][j] = h[word[i][j] - 'a'];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    first = true;
}

void Dp()
{
    int len = strlen(s);

    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int wLen = strlen(buf[j]);

            if (i + wLen - 1 < len && strncmp(&s[i], buf[j], wLen) == 0)
            {
                if (i == 0)
                {
                    dp[i + wLen - 1] = 1;
                    path[i + wLen - 1] = j;
                }
                else if (dp[i - 1] + 1 < dp[i + wLen - 1])
                {
                    dp[i + wLen - 1] = dp[i - 1] + 1;
                    path[i + wLen - 1] = j;
                }
            }
        }
    }
}

void DfsPrint(int pos)
{
    if (pos == -1) return;
    DfsPrint(pos - strlen(word[path[pos]]));
    if (first)
    {
        first = false;
    }
    else
    {
        cout << " ";
    }
    cout<< word[path[pos]];
}

void Output()
{
    int len = strlen(s);

    if (dp[len - 1] == INF)
    {
        puts("No solution.");
    }
    else
    {
        DfsPrint(len - 1);
        puts("");
    }
}

int main()
{
    while (cin>>s)
    {
        Read();
        Init();
        Dp();
        Output();
    }

    return 0;
}