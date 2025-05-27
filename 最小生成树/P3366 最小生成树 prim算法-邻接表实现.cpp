//邻接表实现
//vector数组实现孩子表示法的邻接表 
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 5010, INF = 0x3f3f3f3f;

vector<PII> edge[N];
int dist[N];
bool st[N];

int n,m;

int prim()
{
	memset(dist,0x3f,sizeof dist);
	
	dist[1] = 0;
	
	int ret = 0;
	
	for(int i=1;i<=n;i++) //确定了要添加n个点，就直接用循环 
	{
		//1.找距离最短的顶点 
		int t = 0;
		for(int i=1;i<=n;i++)
		{
			if(!st[i] && dist[i] < dist[t]) t = i;
		}
			
		//判断是否连通 
		if(dist[t] == INF) return INF;
		
		st[t] = true;
		ret += dist[t];
		
		//2.更新最短距离 
		for(auto& p:edge[t]) //循环与t相连的点 
		{
			int a = p.first, b = p.second; //当前新加入的点到某个相连的a点的距离b 
			dist[a] = min(dist[a],b); //更新某个相连的a点的最短距离 
		}
	} 
	
	return ret;
}

int main()
{
	cin >> n >> m;
	//建图 
	for(int i=1;i<=m;i++) 
	{
		int x,y,z; cin >> x >> y >> z;
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	
	int ret = prim();
	
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	 
	return 0;
 } 
