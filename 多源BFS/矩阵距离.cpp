//Ϊʲô���뵽��1����Դbfs����Ϊ���뵽����ÿ��0����ÿ��0bfs�ҵ����������1����������ʱ�临�Ӷ�̫���ˣ����������� 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;

int n,m;
const int N = 1010;
char a[N][N];
int dist[N][N];
//����������������ҵ���������پ������ָͨ����������ȥ�ҵ���̾��룩 
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0}; 

void bfs()
{
	memset(dist,-1,sizeof dist); 
	//�������1�������� 
	queue<PII> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j] == '1') 
			{
				q.push({i,j});
				dist[i][j] = 0;
			} 
		}
	} 
	
	//BFS
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i=0;i<4;i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && dist[a][b] == -1) 
			{
				dist[a][b] = dist[x][y] + 1;
				q.push({a,b}); 
			}
		}
	} 
}

int main() 
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	
	bfs();
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
