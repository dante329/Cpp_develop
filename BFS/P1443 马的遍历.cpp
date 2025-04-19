//#include <iostream>
//using namespace std;
//int n,m,x,y; 
//const int N = 410;
//int a[N][N];
//int dx[] = {1,1,2,2,-1,-1,-2,-2};
//int dy[] = {2,-2,1,-1,2,-2,1,-1};
//int step;
//
//void bfs(int i,int j) //bfs的功能就是在a当中填步数 
//{
//	a[i][j] = step++;
//	for(int q=0;q<8;q++)
//	{
//		int k = i + dx[q], l = j + dy[q];
//		if(k<1||k>n||l<1||l>m) continue;
//		bfs(k,l);
//	} 
//}
//
//int main() 
//{
//	cin >> n >> m >> x >> y;
//	bfs(x,y);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout << a[i][j] << " ";
//		cout << endl;
//	return 0;
//}


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;
int n,m,x,y; 
const int N = 410;
int dist[N][N];
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};

void bfs() //bfs的功能就是在a当中填步数，具体的bfs实现方式是通过队列 
{
	memset(dist,-1,sizeof dist); //初始点的距离为0，为了区分此情况选择初始化为-1 
	
	queue<PII> q;
	q.push({x,y});
	dist[x][y] = 0;
	
	while(!q.empty())
	{
		auto t = q.front(); q.pop();
		int i = t.first, j = t.second;
		//枚举出队头元素(i,j)所有可能走到的位置 
		for(int k=0;k<8;k++)
		{	 
			int x = i + dx[k], y = j + dy[k]; //这里定义的局部的x、y不会与全局变量发生冲突，在这个局部变量范围内调用的就是局部变量 
			//可行性判断 
			if(x<1||x>n||y<1||y>m) continue;
			//不能回到来的位置，不然会死循环。并且也不干涉已经标记过的最短路径 
			if(dist[x][y] != -1) continue; 
			
			dist[x][y] = dist[i][j] + 1; //(x,y)是从(i,j)来的，就在dist[i][j]的基础上加1 
			q.push({x,y});
		}		
	}

}

int main() 
{
	cin >> n >> m >> x >> y;
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;	
	}
	return 0;
}
