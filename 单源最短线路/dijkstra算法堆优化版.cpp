#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

priority_queue<PII,vector<PII>,greater<PII>> heap; //<���룬���>

int n,m,s;
int dist[N];
bool st[N];
vector<PII> edges[N];

void dijkstra()
{
	//��ʼ��
	memset(dist,0x3f,sizeof dist);
	dist[s] = 0;
	heap.push({0,s}); 
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		
		int a = t.second;
		
		//�ж��Ƿ��Ѿ�ȷ�����· 
		if(st[a]) continue;
		st[a] = true;
		
		//�ɳڲ��� 
		for(auto& x:edges[a])
		{
			int b = x.first, c = x.second;
			
			if(dist[a] + c < dist[b]) 
			{
				dist[b] = dist[a] + c;
				heap.push({dist[b],b}); 
			}
		}
	} 
}

int main()
{
	cin >> n >> m >> s;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w; cin >> u >> v >> w;
		edges[u].push_back({v,w}); 
	}
	
	dijkstra();
	
	for(int i=1;i<=n;i++) cout << dist[i] << " ";
	
	return 0;
}
