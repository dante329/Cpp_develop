#include<iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std; 

typedef pair<int,int> PII;


const int N = 2e3, M = 3010 * 2;

//spfaҪ��ͼ������ֱ�Ӵ�� 
//int pos;
//struct
//{
//	int x,y,z;
//}e[M];

vector<PII> edges[N];

int dist[N];
bool st[N];
int n,m;
int cnt[N]; //��¼��1����ÿ������Ҫ�����ı��� 

bool spfa()
{
	//�����һ�ֵ����� 
	memset(dist,0x3f,sizeof dist);
	memset(st,0,sizeof st);
	memset(cnt,0,sizeof cnt);

	//��ʼ�� 
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	st[1] = true;
	cnt[1] = 0; 
	
	while(q.size())
	{
		int a = q.front(); q.pop();
		st[a] = false; //a�����˾�Ҫ���´���false��� 
		
		for(auto& t:edges[a])
		{
			int b = t.first, c = t.second;
			
			if(dist[a] + c < dist[b])
			{
				dist[b] = dist[a] + c;	
				cnt[b] = cnt[a] + 1; 
				
				if(cnt[a] >= n) return true;
				
				if(!st[b]) //b�������ɳڲ�������Ҫ������У�����ǰ����b���ڶ����У�����Ѿ��ڶ����в���Ҫ�ظ���� 
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
