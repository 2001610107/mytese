/*
 * 问题描述：一个w*h的网格，在这些网格上一些地方有障碍物，给定起点与终点的位置，当石头从起点开始走，撞上障碍才会转弯，否则会一直沿着来时的方向继续前进。
 * 撞到障碍后停在障碍前的位置，障碍消失。然后石头可以选择四个方向（相邻处无障碍的方向）前进，问至少需要停多少次才能从起点到达终点。不能到达或者多余10步后游戏失败。
 * 如果能到达输出最少的步数，否则输出-1.
 *
 * 提交状态： AC 
 *
 * AC 结果： Memory:244KTime: 79MS
 *
 * 解题方法1：在初始位置，基于四个方向进行深度优先搜索。每次先判断这个方向是否可以滑动，可以滑动就一直滑到尾，在滑的过程中判断受否经过终点；
 *  记录每一次到达一个障碍移动的最少次数，利用min函数更新每次计算到的移动次数的最小值。
 *
 * 解题方法2 （可选）：
 *
 * 出错次数：6
 *
 * 错误原因 （可选）：忘记对map进行初始化
 *
 * 心得体会 （可选）：
 */


#include<iostream>
using namespace std;
int map[25][25];
int h, w;
int minstep;
int x[4] = { 0,0,1,-1 };
int y[4] = { 1,-1,0,0 };//上下左右
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
