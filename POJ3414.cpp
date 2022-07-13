#include<iostream>

#include<queue>
#include<cstring>
#include<stack>

using namespace std;
int a, b, c;
int count;
bool used[101][101];
struct node {
    int x, y;
    int step;
    int flag;
    node *pre;
};
queue<node> q;
stack<int> r;

void bfs(int x, int y) {
    node now;
    node pot[300];
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
            switch(i)
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
                now.x=pot[cnt].x;
                now.y=0;
                now.flag=4;
                break;
                case 5://POUR(1,2)
                    if(pot[cnt].x > b-pot[cnt].y)
                    {
                        now.x = pot[cnt].x-(b-pot[cnt].y);
                        now.y = b;
                    }
                    else
                    {
                        now.x = 0;
                        now.y = pot[cnt].y+pot[cnt].x;
                    }

                now.flag=5;
                break;
                case 6://POUR(2,1)
                    if(pot[cnt].y > a-pot[cnt].x)
                    {
                        now.y = pot[cnt].y - (a-pot[cnt].x);
                        now.x = a;
                    }
                    else
                    {
                        now.x = pot[cnt].x+pot[cnt].y;
                        now.y = 0;
                    }
                   now.flag=6;
                    break;
            }
            if(used[now.x][now.y]) continue;
            used[now.x][now.y]=1;
            now.step=pot[cnt].step+1;
            now.pre=&pot[cnt];//记录步骤
            if(now.x==c||now.y==c)
            {
                count=now.step;
                while(now.pre)
                {
                    r.push(now.flag);
                    now=*now.pre;
                }
                return;
            }
            q.push(now);

        }
    }
    count=-1;
    return;
}

void result_print() {
    if (count != -1) {
        cout << count << endl;
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
    } else cout << "impossible" << endl;
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
