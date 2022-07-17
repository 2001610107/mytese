/*
 * 问题描述：给出两个杯子的容量和一个目标容量，问能否通过题目中所给出两个杯子操作达到目标容量。如果可以输出最小的操作步数和操作流程。否则，输出impossible.
 *
 * 提交状态： AC
 *
 * AC 结果： Memory: 240K Time: 0MS
 *
 * 解题方法1：倒水的方式共有六种：FILL(1),FILL(2),DROP(1),DROP(2),POUR(1,2),POUR(2,1)，枚举这六种倒法进行BFS
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：7
 *
 * 错误原因 （可选）：在进行POUR(i,j)这个操作中，要判断i杯子中的水能不能装满j杯子，如果能装满那么i杯子中水不一定会全部倒入j杯子中，没注意到i可能还会有剩。
 *
 * 心得体会 （可选）：审题的重要性
 */
#include<iostream>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;
int a, b, c;
int ans;
bool used[101][101];
struct node {
    int x, y;
    int step;
    int flag;
    node* pre;
};
queue<node> q;
stack<int> r;

void bfs(int x, int y) {
    node now;
    node pot[320];
    now.x = now.y = now.flag = now.step = 0;
    now.pre = NULL;
    q.push(now);
    used[x][y] = 1;
    int cnt = -1;
    while (!q.empty()) {
        cnt++;
        pot[cnt] = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            switch (i)
            {
            case 1:   //FILL(1)
                now.x = a;
                now.y = pot[cnt].y;
                now.flag = 1;
                break;
            case 2://FILL(2)
                now.y = b;
                now.x = pot[cnt].x;
                now.flag = 2;
                break;
            case 3://DROP(1)
                now.x = 0;
                now.y = pot[cnt].y;
                now.flag = 3;
                break;

            case 4://DROP(2)
                now.x = pot[cnt].x;
                now.y = 0;
                now.flag = 4;
                break;
            case 5://POUR(1,2)
                if (pot[cnt].x > b - pot[cnt].y)
                {
                    now.x = pot[cnt].x - (b - pot[cnt].y);
                    now.y = b;
                }
                else
                {
                    now.x = 0;
                    now.y = pot[cnt].y + pot[cnt].x;
                }
                now.flag = 5;
                break;
            case 6://POUR(2,1)
                if (pot[cnt].y > a - pot[cnt].x)
                {
                    now.y = pot[cnt].y - (a - pot[cnt].x);
                    now.x = a;
                }
                else
                {
                    now.x = pot[cnt].x + pot[cnt].y;
                    now.y = 0;
                }
                now.flag = 6;
                break;
            }
            if (used[now.x][now.y]) continue;
            used[now.x][now.y] = 1;
            now.step = pot[cnt].step + 1;
            now.pre = &pot[cnt];//记录步骤
            if (now.x == c || now.y == c)
            {
                ans = now.step;
                while (now.pre)
                {
                    r.push(now.flag);
                    now = *now.pre;
                }
                return;
            }
            q.push(now);
        }
    }
    ans = -1;
    return;
}

void result_print() {
    if (ans != -1) {
        cout << ans << endl;
        while (!r.empty()) {
            int i = r.top();
            r.pop();
            switch (i) {
            case 1:
                cout << "FILL(1)" << endl;
                break;
            case 2:
                cout << "FILL(2)" << endl;
                break;
            case 3:
                cout << "DROP(1)" << endl;
                break;
            case 4:
                cout << "DROP(2)" << endl;
                break;
            case 5:
                cout << "POUR(1,2)" << endl;
                break;
            case 6:
                cout << "POUR(2,1)" << endl;
                break;
            }
        }
    }
    else cout << "impossible" << endl;
}

int main() {
    while (cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0)
            break;
        while (!q.empty()) {
            q.pop();
        }
        while (!r.empty()) {
            r.pop();
        }
        memset(used, 0, sizeof(used));
        bfs(0, 0);
        result_print();
    }
}
