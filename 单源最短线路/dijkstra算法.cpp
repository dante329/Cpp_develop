#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;

typedef pair<int,int> PII; 

const int N = 1e4 + 10, INF = pow(2,31) - 1;

int n,m,s;
int dist[N];
bool st[N];
vector<PII> edge[N];

void dijkstra()
{
	//初始化
	for(int i=0;i<=n;i++) dist[i] = INF;
	dist[s] = 0;
	
	for(int i=1;i<n;i++) //找n-1次 
	{
		//找当前最小
		int t = 0; 
		for(int i=1;i<=n;i++)
		{
			if(!st[i] && dist[i] < dist[t]) t = i; 
		}
		st[t] = true; //给t打上标记 
		
		//松弛操作 
		for(auto p:edge[t])
		{
			int y = p.first, z = p.second;
			if(dist[t] + z < dist[y]) dist[y] = dist[t] + z;
		}
	}
}

int main() 
{
	cin >> n >> m >> s;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		edge[u].push_back({v,w}); 
	}		
	
	dijkstra();
	
	for(int i=1;i<=n;i++) cout << dist[i] << " ";
	
	return 0;
}
