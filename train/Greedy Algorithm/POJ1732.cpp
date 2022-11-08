
/*
 * ������������ N (N <= 50000)�����ʣ�ÿ�����ʳ��Ȳ�����50��������ɳ��Ȳ�����100��Ŀ�괮����Ҫ�ö��ٸ����ʡ�
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 3204K Time: 110MS
 *
 * ���ⷽ��1��״̬��dp[i] ��ʾ���ǰ i ���ַ���Ҫ�õ����ٵ�����

״̬ת�Ʒ��̣�dp[i + wLen - 1] = min(dp[i + wLen - 1], dp[i - 1] + 1)
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������10
 *
 * ����ԭ�� ����ѡ�������ʿ����ظ�ʹ�á�
 *
 * �ĵ���� ����ѡ����
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