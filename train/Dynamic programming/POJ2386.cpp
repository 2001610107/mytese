/*
 * ��������������һ��n*m�ĵ�ͼ����W����ʾ��ˮ����.����ʾ�յأ���ˮ�ǰ���ͨ�ģ����ж��ٸ���ˮ�顣
 *
 * �ύ״̬�� AC
 *
 * AC ����� Memory: 664K Time: 47MS
 *
 * ���ⷽ��1��ɨ��һ��ͼ��ÿ����һ����W����������һ�������ѻ��߹��Ѱ����ڵġ�W�����Ϊ��.����ֱ��ͼ��û�л�ˮ��
 *
 * ���ⷽ��2 ����ѡ����
 *
 * ���������8
 *
 * ����ԭ�� ����ѡ����û�д���û��з�
 *
 * �ĵ���� ����ѡ����
 */

 


#include <iostream>
#include <cstdio>
using namespace std;

char field[1001][1001];
int n, m;
void DFS_floodfill(int x, int y)   
{
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
        {
            int xx = x + dx;
            int yy = y + dy;
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && field[xx][yy] == 'W')
                DFS_floodfill(xx, yy);
        }
}
int main()
{
    int i, j, ans;
    while (cin>>n>>m)
    {
        getchar();
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
                cin>>field[i][j];
            getchar();
        }
        ans = 0;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                if (field[i][j] == 'W')
                {
                    DFS_floodfill(i, j);
                    ans++;
                }
        cout << ans << endl;
    }
    return 0;
}
