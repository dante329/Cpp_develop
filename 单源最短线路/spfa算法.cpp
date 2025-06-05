#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;

const int N = 1e4 + 10, INF = pow(2,31) - 1;

vector<PII> edges[N];

int n,m,s;
int dist[N];
bool st[N]; // spfa的st数组是标记结点是否已经在队列中了 

void spfa()
{
	for(int i=0;i<=n;i++) dist[i] = INF;
	dist[s] = 0;
	
	queue<int> q;
	q.push(s);
	st[s] = true;
	
	while(q.size())
	{
		auto a = q.front(); q.pop();
		st[a] = false;
		
		for(auto& t:edges[a])
		{
			int b = t.first, c = t.second;
			
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;
				if(!st[b])
				{
					q.push(b);
					st[b] = true;
				}				 
			}
		}
	}
}


int main()
{
	cin >> n >> m >> s;
	
	for(int i=1;i<=m;i++) 
	{
		int u,v,w;
		cin >> u >> v >> w;
		edges[u].push_back({v,w});
	}
	
	spfa();
	
	for(int i=1;i<=n;i++) cout << dist[i] << " ";
	
	return 0;
 } 
