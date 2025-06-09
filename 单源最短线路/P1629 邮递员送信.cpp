#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
typedef pair<int,int> PII;
const int N = 1010; 

int n,m;
int dist[N];
bool st[N];

vector<PII> edges1[N];
vector<PII> edges2[N];

void dijkstra(vector<PII> edges[])
{
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	dist[1] = 0;
	
	for(int i=1;i<n;i++)
	{
		int u = 0;
		for(int i=1;i<=n;i++)
		{
			if(!st[i] && dist[i] < dist[u]) u = i;
		}
		st[u] = true;
		for(auto t:edges[u])
		{
			int v = t.first, w = t.second;
			if(dist[u] + w < dist[v]) dist[v] = dist[u] + w; 
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=m;i++) 
 	{
 		int u,v,w; cin >> u >> v >> w;
		edges1[u].push_back({v,w}); 	
		edges2[v].push_back({u,w});
	}
	 
	int ret = 0; 
	
 	dijkstra(edges1);
 	
 	for(int i=1;i<=n;i++) ret = ret + dist[i];
 	
 	dijkstra(edges2);
 	
 	for(int i=1;i<=n;i++) ret = ret + dist[i];
	
 	cout << ret;
 	
	return 0;
} 
