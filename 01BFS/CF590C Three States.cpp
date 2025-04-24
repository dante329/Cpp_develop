#include<iostream> 
#include<deque>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
int n,m;
const int N = 1e3 + 10;
char p[N][N];
int dist[4][N][N];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int pos)
{
	memset(dist[pos],-1,sizeof dist[pos]);
	
	//多源BFS 
	deque<PII> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(p[i][j] - '0' == pos)
			{
				q.push_front({i,j});
				dist[pos][i][j] = 0;
			}	
		} 
	}	
	
	//01BFS
	while(q.size())
	{
		auto t = q.front(); q.pop_front();
		int x = t.first, y = t.second;
		for(int i=0;i<4;i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && p[a][b] != '#') //跳过非法
			{
				//计算边权 
				int w = (p[a][b] == '.' ? 1 : 0);
			 
				//第一次访问（一定要入队） 
				if(dist[pos][a][b] == -1)
				{
					dist[pos][a][b] = dist[pos][x][y] + w;
					if(w) q.push_back({a,b});
					else q.push_front({a,b});
				}
				//再次访问比大小 
				else if(dist[pos][x][y] + w < dist[pos][a][b])
				{
					//松弛 
					dist[pos][a][b] = dist[pos][x][y] + w;
				} 					
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> p[i][j];	
		} 
	}	
	
	bfs(1);
	bfs(2);
	bfs(3);
	
	int ret = 0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(p[i][j] == '#') continue;
			//把合法的位置距离1、2、3号国家的距离全部提取出来 
			int x = dist[1][i][j], y = dist[2][i][j], z = dist[3][i][j];
			//即使合法了，这个位置也可能到不了，这样的点是不能参与更新结果的 
			if(x == -1 || y == -1 || z == -1) continue; 
			//判断这个位置是在荒地上还是在国家上
			if(p[i][j] == '.') ret = min(ret,x + y + z - 2);
			else ret = min(ret,x + y + z); 
		} 
	}
	
	//判断ret
	if(ret == 0x3f3f3f3f) cout << -1 << endl;
	else cout << ret << endl; 
	return 0;
}
