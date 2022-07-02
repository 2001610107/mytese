#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char map[105][105];
bool used[105][105];
int start_x, start_y, end_x, end_y;
int fx;
int w, h;
int go_left[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int go_right[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
struct node {
    int nx;
    int ny;
    int count;
};
int DFS(int x, int y, int count, int go)
{
    if (x == end_x && y == end_y)
    {
        return count + 1;//起点也算一步
    }
    if (x<1 || x>h || y<1 || y>w || map[x][y] == '#')
    {
        return 0;
    }
    int ans = 0;
    fx = (fx + 3) % 4;  //左转
    while (1)
    {
        if (go == 1)
        {
            ans = DFS(x + go_left[fx][0], y + go_left[fx][1], count + 1, go);
        }
        else {
            ans = DFS(x + go_right[fx][0], y + go_right[fx][1], count + 1, go);
        }
        if (ans > 0) break;
        fx = (fx + 1) % 4;//右转
    }
    return ans;
}
int BFS()
{
    node now, next;
    queue<node>q;
    now.nx = start_x;
    now.ny = start_y;
    now.count = 0;
    used[start_x][start_y] = 1;
    q.push(now);
    while (!q.empty())
    {
        now=q.front();
        q.pop();
        if (now.nx ==end_x && now.ny==end_y)
        {
            return now.count + 1;
        }
        int tx, ty;
        for (int i = 0; i < 4; i++)
        {
            tx = now.nx + go_left[i][0];
            ty = now.ny + go_left[i][1];
            if (tx<1 || tx>h || ty<1 || ty>w || used[tx][ty])
            {
                continue;
            }
            else
                used[tx][ty] = 1;
            next.count = now.count + 1;
            next.nx = tx;
            next.ny = ty;
            q.push(next);

        }
    }
}
void solution(int n)
{
    while (n--)
    {
        fx = 0;
        cin >> w >> h;
        memset(used, 0, sizeof(used));
        for (int i = 1; i <=h; i++)
        {
            for (int j = 1; j <=w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
                if (map[i][j] == 'E')
                {
                    end_x = i;
                    end_y = j;
                }
                if (map[i][j] =='#')
                {
                    used[i][j] = 1;
                }
            }
        }
        cout << DFS(start_x, start_y, 0, 1)<<" ";
        fx = 0;
        cout << DFS(start_x, start_y, 0, 2) << " ";
        cout << BFS() << endl;

    }
}
int main()
{
    int n;
    cin >> n;
    solution(n);
}
