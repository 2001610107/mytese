#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 10005
bool prime[maxn];
void Isprime()
{
    int i, j;
    for (i = 1000; i <= maxn; i++) {
        for (j = 2; j < i; j++)
            if (i % j == 0) {
                prime[i] = false;
                break;
            }
        if (j == i) prime[i] = true;
    }

}
int  BFS(int first, int last)
{
    bool used[maxn];
    queue <int> q;
    int now, i, j, temp, now_temp, count[maxn], t[4];
    memset(used, false, sizeof(used));
    memset(count, 0, sizeof(count));
    q.push(first);
    used[first] = true;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        t[0] = now / 1000;   //第一位
        t[1] = now % 1000 / 100;  //第二位
        t[2] = now % 100 / 10;    //第三位
        t[3] = now % 10;       //第四位
        //cout << t[0] << " " << t[1] << " " << t[2] << " " << t[3] << " " << endl;
        for (j = 0; j < 4; j++)
        {
            temp = t[j];
            for (i = 0; i < 10; i++)
            {
                if (i != temp)
                {
                    t[j] = i;
                    now_temp = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
                    if (!used[now_temp] && prime[now_temp])
                    {
                        count[now_temp] = count[now] + 1;
                        used[now_temp] = true;
                        q.push(now_temp);
                    }
                    if (now_temp == last) return count[now_temp];
                }
            }
            t[j] = temp;
        }
        if (now == last) return count[now];
    }
    return -1;
}
int main()
{
    int n, first, last, count;
    cin >> n;
    Isprime();
    while (n--)
    {
        cin >> first >> last;
        count = BFS(first, last);
        if (count != -1)
        {
            cout << count << endl;
        }
        else cout << "Impossible" << endl;
    }
}