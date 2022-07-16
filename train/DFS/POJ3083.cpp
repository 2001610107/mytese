/*
 * 问题描述：给一个图，输入列为w,行为h的迷宫,'#'代表墙不能走, '.'代表路可以走,S为起点,E为终点，
 * 需求3个解，按照一定原则从S走到E的步数，第一个解求依次按左前右后遍历所需步数，
 * 第二个解求依次按右前左后遍历所需步数，其中前后左右都是以当前面向为参考系。第三个解为最短路。
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 332K Time: 16MS
 *
 * 解题方法1：第一按照按左前右后遍历的方式深搜，并计算步伐数，第二按照右前左后遍历的方式深搜，并计算步伐数，最短路用宽度搜索。
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：10
 *
 * 错误原因 （可选）：对宽度搜索使用到的队列数据结构掌握不足
 *
 * 心得体会 （可选）：对宽度搜索使用到的队列数据结构有进一步认识
 */

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
