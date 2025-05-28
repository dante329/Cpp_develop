#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;

int edge[N][N]; //edge[i][j]：i、j两点的边权值 
int dist[N]; //每个顶点距离生成树的距离 
int st[N];
int n,v; //n是物品数，v是统一价格 

//方式一：在函数中特判
int prim1()
{
	memset(dist,0x3f,sizeof dist);
	
	int ret = 0; //最小花费 
	
	//任意选择一个点作为起点
	dist[1] = 0;
	
	for(int i=1;i<=n;i++) //循环加入n个点 
	{
		//1.选择最近的点
		int t = 0;
		for(int i=1;i<=n;i++) 
		{
			if(!st[i] && dist[i] < dist[t]) t = i;
		}
		
		if(dist[t] <= v) ret += dist[t];
		else ret += v;//优惠价反而更高或者没有优惠，那么就直接买 
		st[t] = true;
		
		//不用判断连通，本题一定连通
		
		//2.更新距离
		for(int i=1;i<=n;i++)
		{
			dist[i] = min(dist[i],edge[t][i]);
		} 
	}
	 
	return ret;
}

int prim2()
{
	memset(dist,0x3f,sizeof dist);
	
	int ret = 0; //最小花费 
	
	//任意选择一个点作为起点
	dist[1] = 0;
	
	for(int i=1;i<=n;i++) //循环加入n个点 
	{
		//1.选择最近的点
		int t = 0;
		for(int i=1;i<=n;i++) 
		{
			if(!st[i] && dist[i] < dist[t]) t = i;
		}
		
		ret += dist[t];
		st[t] = true;
		
		//不用判断连通，本题一定连通
		
		//2.更新距离
		for(int i=1;i<=n;i++)
		{	
			dist[i] = min(dist[i],edge[t][i]);
		} 
	}
	 
	return ret;
}

int main()
{
	cin >> v >> n;
	
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			int x; cin >> x; 
			if(x == 0 || x > v) edge[i][j] = v; //方式二：直接在读数据的时候处理
			else edge[i][j] = x;
		}
	}
	
	cout << prim() + v; 
	
	return 0;
} 
