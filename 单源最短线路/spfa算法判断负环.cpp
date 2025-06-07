#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std; 

typedef pair<int,int> PII;


const int N = 2e3, M = 3010 * 2;

//spfa要存图，不能直接存边 
//int pos;
//struct
//{
//	int x,y,z;
//}e[M];

vector<PII> edges[N];

int dist[N];
bool st[N];
int n,m;
int cnt[N]; //记录从1到达每个点需要经过的边数 

bool spfa()
{
	//清空上一轮的数据 
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	memset(cnt,0,sizeof cnt);

	//初始化 
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	st[1] = true;
	cnt[1] = 0; 
	
	while(q.size())
	{
		int a = q.front(); q.pop();
		st[a] = false; //a出队了就要重新打上false标记 
		
		for(auto& t:edges[a])
		{
			int b = t.first, c = t.second;
			
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;	
				cnt[b] = cnt[a] + 1; 
				
				if(cnt[a] >= n) return true;
				
				if(!st[b]) //b进行了松弛操作，需要加入队列，但是前提是b不在队列中，如果已经在队列中不需要重复添加 
				{
					q.push(b); 
					st[b] = true;
				}
			}
		}
	}
	
	return false;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> n >> m;
		
		for(int i=1;i<=n;i++) edges[i].clear(); 
		
		for(int i=1;i<=m;i++)
		{
			int u,v,w; cin >> u >> v >> w;
			
			edges[u].push_back({v,w});
			if(w >= 0) edges[v].push_back({u,w});  
		}
	
		if(spfa()) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
	
	   
	
	return 0;
 } 
