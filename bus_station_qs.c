#include <stdio.h>
#include <stdlib.h>
#define MaxN 100
#define Max_que 10000
int Findsta(const char *map, unsigned int ArrN, unsigned int Pathlen){
	int visit[MaxN][MaxN] = { 0 };
	int que[Max_que][2];
	int front = 0, rear = 0;
	//方向数组
	int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	//距离数组
	int dis[MaxN][MaxN] = { 0 };
	//路径计数
	int count = 0;
	//寻找起点X
	int start_x = -1, start_y = -1;
	for (int i = 0; i < ArrN*ArrN; i++){
		if (map[i] == 'X')
		{
			start_x = i / ArrN;
			start_y = i%ArrN;
			break;
		}
	}
	if (start_x == -1) return 0;
	//起点入队+标记距离
	visit[start_x][start_y] = 1;
	que[rear][0] = start_x;
	que[rear][1] = start_y;
	dis[start_x][start_y] = 0;
	rear++;
	while (rear != front){
		int row = que[front][0];
		int col = que[front][1];
		int steps = dis[row][col];
		//visit[row][col] = 1;
		front++;
		if (map[row*ArrN+col] == 'S') count++;
		if (steps >= Pathlen) continue;
		//寻找相邻点——上、下、左、右
		for (int d = 0; d < 4; d++){
			int dr = dir[d][0];
			int dc = dir[d][1];
			int	nr = row + dr;
			int nc = col + dc;
			//判断是否过界，是否是障碍“B”，是否已访问
			if (nr>=0&&nr<ArrN&&nc>=0&&nc<ArrN&&map[nr*ArrN+nc]!='B'&&visit[nr][nc]==0)
			{
				//无问题，入队
				que[rear][0] = nr;
				que[rear][1] = nc;
				visit[nr][nc] = 1;
				dis[nr][nc] = steps + 1;//从刚刚来的地方距离再加1
				rear++;
			}
		}
	}
	return count;
	
}
//主函数验证
int main(void){
	/*   错误，map是一维数组
	char map1[] = { "...S........X.S.....S...." };
	char map2[] = { "S...S.........BS........X" };
	*/
	//正确写法
	char map1[] = "...S........X.S.....S...." ;
	char map2[] = "S...S.........BS........X" ;
	
	/*
	char map1[25] = {
		'.', '.', '.', 'S', '.',
		'.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.',
		'.', '.', '.', '.', '.',
		'X', '.', 'S', '.', '.'
	};
	// 测试用例2：5*5地图，X在(4,4)，步长5内有1个S（避开B）
	char map2[25] = {
		'S', '.', '.', '.', 'S',
		'.', '.', '.', '.', '.',
		'.', '.', '.', 'B', '.',
		'.', '.', '.', '.', '.',
		'.', '.', '.', '.', 'X'
	};
	*/
	printf("example1：%d\n", Findsta(map1, 5, 3));
	printf("example2：%d\n", Findsta(map2, 5, 5));
	char c;
	while ((c = getchar()) != '\n');
	return 0;
}
