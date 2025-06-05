#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1e4 + 10, INF = pow(2,31) - 1;

int n,m,s;
int dist[N];

vector<PII> edges[N];

void bf()
{
	for(int i=0;i<=n;i++) dist[i] = INF;
	dist[s] = 0;
	
	bool flag = false;
	for(int i=1;i<n;i++)
	{			
		flag = false;
		for(int u=1;u<=n;u++)
		{
			//dist[u]�����INF�ʹ���û�и���ֵ��ֱ��������û�б�Ҫ�������ĳ��߽����ɳڲ��� 
			if(dist[u] == INF) continue; 
			
			for(auto& t:edges[u])
			{
				int v = t.first, w = t.second;
				if(dist[u] + w < dist[v]) 
				{
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}
		
		if(flag == false) break;
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
	
	bf();
	 
	for(int i=1;i<=n;i++) cout << dist[i] << " "; 
	
	return 0;
}
