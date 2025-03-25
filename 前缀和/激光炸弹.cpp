#include<iostream>

using namespace std;

const int N = 1e4 + 10;
int a[N][N];
int f[N][N];
int n,m;
int x,y,v;
int main()
{
	cin >> n >> m;
	//读数据 
	while(n--)
	{		 
		cin >> x >> y >> v;
		a[++x][++y] += v; //可能存在多个目标在同一位置上的情况。
	}
	//建立二维前缀和 
	int edge = 5001; //题目没有给出坐标轴的范围，所以我们定义一个edge表示m的最大范围 
	for(int i=1;i<=edge;i++)
	{
		for(int j=1;j<=edge;j++)
		{
			f[i][j] = f[i-1][j] + f[i][j-1] -f[i-1][j-1] + a[i][j]; 
		}
	}
	//枚举m区域右下角坐标的所有位置
	int ret = 0;
	m = min(m,edge); 
	for(int x2=m;x2<=edge;x2++)	
	{
		for(int y2=m;y2<=edge;y2++)
		{
			int x1 = x2 - m + 1; 
			int y1 = y2 - m + 1;
			//求(x1,y1)到(x2,y2)区间内的价值和，用到f前缀和数组 
			ret = max(ret,f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1]);
		}
	} 
	cout << ret << endl;
	return 0;
}
