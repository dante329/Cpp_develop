//求最小生成树 
//邻接矩阵存图 
#include <iostream>
#include <cstring>

using namespace std;

const int N = 5010, INF = 0x3f3f3f3f;

int edge[N][N]; //邻接矩阵edge
int dist[N]; //每个顶点距离生成树的距离 
bool st[N]; //标记哪些点已经进入了生成树 
int n,m;  

int prim()
{
	//dist表示顶点距离生成树的距离，最刚开始都初始化为无穷大 
	memset(dist,0x3f,sizeof dist);
	
	dist[1] = 0;
	
	int ret = 0;
	for(int i=1;i<=n;i++) //循环加入n个点 
	{
		//1.找最近点
		int t = 0; 
		for(int i=1;i<=n;i++) 
		{
			if(!st[i] && dist[i] < dist[t]) t = i; //找到没有访问的点，并且这个点距离生成树最近 
		}	
		
		//判断是否连通 
		if(dist[t] == INF) return INF; //不连通直接返回INF
		
		st[t] = true;
		ret += dist[t]; 
		
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
	cin >> n >> m;
	//初始化edge，这样取最小的时候不会影响结果 
	memset(edge,0x3f,sizeof edge);
	//建图
	for(int i=1;i<=m;i++)
	{
		int x,y,z; cin >> x >> y >> z;
		edge[x][y] = edge[y][x] = min(edge[x][y], z); //考虑重边  
	}
	
	int ret = prim(); 
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	
	return 0;
}
