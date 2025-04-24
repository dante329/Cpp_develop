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
	
	//��ԴBFS 
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
			if(a >= 1 && a <= n && b >= 1 && b <= m && p[a][b] != '#') //�����Ƿ�
			{
				//�����Ȩ 
				int w = (p[a][b] == '.' ? 1 : 0);
			 
				//��һ�η��ʣ�һ��Ҫ��ӣ� 
				if(dist[pos][a][b] == -1)
				{
					dist[pos][a][b] = dist[pos][x][y] + w;
					if(w) q.push_back({a,b});
					else q.push_front({a,b});
				}
				//�ٴη��ʱȴ�С 
				else if(dist[pos][x][y] + w < dist[pos][a][b])
				{
					//�ɳ� 
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
			//�ѺϷ���λ�þ���1��2��3�Ź��ҵľ���ȫ����ȡ���� 
			int x = dist[1][i][j], y = dist[2][i][j], z = dist[3][i][j];
			//��ʹ�Ϸ��ˣ����λ��Ҳ���ܵ����ˣ������ĵ��ǲ��ܲ�����½���� 
			if(x == -1 || y == -1 || z == -1) continue; 
			//�ж����λ�����ڻĵ��ϻ����ڹ�����
			if(p[i][j] == '.') ret = min(ret,x + y + z - 2);
			else ret = min(ret,x + y + z); 
		} 
	}
	
	//�ж�ret
	if(ret == 0x3f3f3f3f) cout << -1 << endl;
	else cout << ret << endl; 
	return 0;
}
