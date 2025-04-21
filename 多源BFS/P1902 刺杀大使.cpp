#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
int n,m;
const int N = 1e3 + 10;
int p[N][N];
//int dist[N][N]; 这题其实不需要dist，因为不需要计算具体的最短路径，我们只需要通过BFS判断是否有通路 
bool st[N][N]; //标记该点是否走过 
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//多源bfs 
bool bfs(int mid)
{
	//因为要将第1行全部入队，所以要考虑特殊情况 
	if(n == 1) return true;
	
	memset(st,0,sizeof st);
	
	//将n=1全部加入队列中 
	queue<PII> q;
	for(int i=1;i<=m;i++)
	{
		q.push({1,i});
		st[1][i] = true;  
	}
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		
		for(int i=0;i<4;i++)
		{
			int a = x + dx[i], b = y + dy[i];
			
			if(a >= 1 && a <= n && b >= 1 && b <= m && st[a][b] == false && p[a][b] <= mid) 
			{
				st[a][b] = true;
				q.push({a,b});
				
				if(a == n) return true;
			}
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;	
	//二分答案，二分的是伤害值，伤害值是从0到最大 
	int l = 0, r = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> p[i][j];
			r = max(r,p[i][j]);
		} 
	}
	
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(bfs(mid)) r = mid; //bfs做check 
		else l = mid + 1;
	}
	
	cout << l; 
	return 0;
}
