#include<iostream>
using namespace std;
int map[25][25];
int h, w;
int minstep;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };//ÉÏÏÂ×óÓÒ
int start_x , start_y ;
void DFS(int s_x, int s_y, int step)
{
	if (step > 10 || step >= minstep) return;
	for (int i = 0; i < 4; i++)
	{
		int nx = s_x + x[i];
		int  ny = s_y + y[i];
		if (nx >= 0 && ny >= 0 && nx < h && ny < w && map[nx][ny] != 1)
		{
			while (nx >= 0 && ny >= 0 && nx < h && ny < w && map[nx][ny] != 1)
			{
				if (map[nx][ny] == 3)
				{
					minstep = min(minstep, step);
					return;
				}
				nx += x[i];
				ny += y[i];
			}
			if (map[nx][ny] == 1)
			{
				step++;
				map[nx][ny] = 0;
				DFS(nx - x[i], ny - y[i], step);
				step--;
				map[nx][ny] = 1;
			}
		}
	}
}
   

int main()
{
	while (cin >> w >> h && w + h)
	{
		memset(map, 0, sizeof(map));
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 2) {
					start_x = i;
					start_y = j;
				}
			}
		}
		minstep = 0x3f3f3f3f;
		DFS(start_x, start_y, 1);
		if (minstep > 10)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << minstep << endl;
		}
	}
	
}