//本题使用dfs和dijkstra分别演示，重点是算法能确定第一次松弛操作就确定是最短路径，因为动态规划“f[p] = f[t];” 我们需要确定f[t]的值，才能对f[p]进行赋值，而确定f[t]的值就必须要在第一次进行松弛操作的时候就确定结点t是最短路径，这样才能递推 
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1e6 + 10, M = 2e6 + 10, MOD = 100003;

int n,m;
int dist[N],f[N];
bool st[N];

vector<int> edges[N]; //边权为1，不用存 

void bfs()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	f[1] = 1; //起点到起点的最短路径有一条
	
	queue<int> q;
	q.push(1);
//	st[1] = true; //不能使用st数组。st数组的目的是防止结点重复加入队列，而我们要求的是“有多少条不同的最短路”，这需要对同一个结点进行多次松弛，看看是否可以使得“dist[t] + 1 == dist[p]” 
	
	while(q.size())  
	{
		int t = q.front(); q.pop();
//		if(st[t]) continue;
//		st[t] = true;
		
		for(int p:edges[t])
		{
			if(dist[t] + 1 < dist[p])
			{
				dist[p] = dist[t] + 1;
				f[p] = f[t]; //需要t的最短路径数是确定的 
				q.push(p); 
			}
			else if(dist[t] + 1 == dist[p])
			{
				f[p] = (f[p] + f[t]) % MOD;
			}
		}
	}
}

void dijkstra()
{
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	f[1] = 1;
	heap.push({0,1}); 
		
	while(heap.size())
	{
		auto t = heap.top() ; heap.pop() ;
		int u = t.second;
		
		if(st[u]) continue;
		st[u] = true;
		
		for(auto v:edges[u])
		{
			if(dist[u] + 1 < dist[v])
			{
				dist[v] = dist[u] + 1;
				f[v] = f[u];
				heap.push({dist[v],v}); 
			}
			else if(dist[u] + 1 == dist[v]) //这里必须是else if，上面已经dist[v] = dist[u] + 1; 要是这里是if那肯定会进去 
			{
				f[v] = (f[v] + f[u]) % MOD;
			}
		}
		
	 } 
} 

int main()
{
	cin >> n >> m;
	for(int i=1;i<=m;i++) 
	{
		int x,y; scanf("%d%d",&x,&y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

//	bfs();
	
	dijkstra();
	
	for(int i=1;i<=n;i++) printf("%d\n",f[i]);
	
	return 0;
} 
