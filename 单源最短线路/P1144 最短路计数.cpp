//����ʹ��dfs��dijkstra�ֱ���ʾ���ص����㷨��ȷ����һ���ɳڲ�����ȷ�������·������Ϊ��̬�滮��f[p] = f[t];�� ������Ҫȷ��f[t]��ֵ�����ܶ�f[p]���и�ֵ����ȷ��f[t]��ֵ�ͱ���Ҫ�ڵ�һ�ν����ɳڲ�����ʱ���ȷ�����t�����·�����������ܵ��� 
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

vector<int> edges[N]; //��ȨΪ1�����ô� 

void bfs()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	f[1] = 1; //��㵽�������·����һ��
	
	queue<int> q;
	q.push(1);
//	st[1] = true; //����ʹ��st���顣st�����Ŀ���Ƿ�ֹ����ظ�������У�������Ҫ����ǡ��ж�������ͬ�����·��������Ҫ��ͬһ�������ж���ɳڣ������Ƿ����ʹ�á�dist[t] + 1 == dist[p]�� 
	
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
				f[p] = f[t]; //��Ҫt�����·������ȷ���� 
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
			else if(dist[u] + 1 == dist[v]) //���������else if�������Ѿ�dist[v] = dist[u] + 1; Ҫ��������if�ǿ϶����ȥ 
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
