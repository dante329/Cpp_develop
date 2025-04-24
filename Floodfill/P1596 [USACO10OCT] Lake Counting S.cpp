//�ݸ壬û���彲��ʲô��Ȼ��͸�bfs��dfs��һ���ˣ����������� 
//#include <iostream>
//#include <queue>
//
//using namespace std;
//typedef pair<int,int> PII;
//const int N = 110;
//char p[N][N];
//bool st[N][N];
//int n,m;
//
//int dx[] = {0,0,1,1,1,-1,-1,-1};
//int dy[] = {1,-1,1,-1,0,1,-1,0};
//
//void dfs(int x,int y)
//{
//	if(p[x][y] == '.') return;
//	
//	for(int i=0;i<8;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if(a >= 1 && a <= n && b >= 1 && b <= m && p[a][b] == 'W') 
//		{
//			st[a][b] = true;
//			dfs(a,b);
//		}
//	} 
//}
//
//void bfs()
//{
//	queue<PII> q;
//	q.push({1,1});
//	if(p[1][1] == 'W') st[1][1] = true;
//	while(q.size())
//	{
//		auto t = q.front(); q.pop();
//		int x = t.first, y = t.second;
//		for(int i=0;i<8;i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if(a >= 1 && a <= n && b >= 1 && b <= m)
//			{
//				if(p[a][b] == 'W') 
//				{
//					st[a][b] = true;
//					dfs(a,b);
//				}
//			}
//		}
//	}
//}

//int main() 
//{
//	cin >> n >> m;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cin >> p[i][j];
//		}
//	}	
//	
//	bfs();
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(st[i][j]) cout << "1" << " "; 
//			else cout << "0" << " ";
//		}
//		cout << endl;
//		
//	}
//	return 0;
//}


//����������bfs����forѭ����������Ȼ������ˮ��bfs�������ƺ������� 
//#include <iostream>
//#include <queue>
//
//using namespace std;
//typedef pair<int,int> PII;
//const int N = 110;
//char p[N][N];
//bool st[N][N];
//int n,m;
//
//int dx[] = {0,0,1,1,1,-1,-1,-1};
//int dy[] = {1,-1,1,-1,0,1,-1,0};
//
//void dfs(int x,int y)
//{
//	for(int i=0;i<8;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if(a >= 1 && a <= n && b >= 1 && b <= m && p[a][b] == 'W' && st[a][b] == false) 
//		{
//			st[a][b] = true;
//			dfs(a,b);
//		}
//	} 
//}
//
//void bfs()
//{
//	queue<PII> q;
//	q.push({1,1});
//	if(p[1][1] == 'W') st[1][1] = true;
//	while(q.size())
//	{
//		auto t = q.front(); q.pop();
//		int x = t.first, y = t.second;
//		for(int i=0;i<8;i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			
//			if(a >= 1 && a <= n && b >= 1 && b <= m)
//			{				
//				if(p[a][b] == 'W' && st[a][b] == false) 
//				{
//					q.push({a,b});
//					st[a][b] = true;
//					dfs(a,b);
//				}					
//			}
//		}
//	}
//}
//
//int main() 
//{
//	cin >> n >> m;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cin >> p[i][j];
//		}
//	}	
//	
//	bfs();
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			if(st[i][j]) cout << "1" << " "; 
//			else cout << "0" << " ";
//		}
//		cout << endl;
//		
//	}
//	return 0;
//}

//��ȷģ�� 
#include <iostream>
#include <queue>

using namespace std;

const int N = 110;

char p[N][N];
bool st[N][N];
int n,m;

int dx[] = {0,0,1,1,1,-1,-1,-1};
int dy[] = {1,-1,1,-1,0,1,-1,0};

void dfs(int x,int y)
{	
//	if(p[x][y] == '.') return; //���������û������ģ���Ϊ'.'�Ѿ���if�����ˣ������Ͳ������ 

	st[x][y] = true;
	
	for(int i=0;i<8;i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if(a >= 1 && a <= n && b >= 1 && b <= m && p[a][b] == 'W' && st[a][b] == false) 
		{
			st[a][b] = true;
			dfs(a,b);
		}
	} 
}

void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	st[x][y] = true;
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i=0;i<8;i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if(a >= 1 && a <= n && b >= 1 && b <= m && p[a][b] == 'W' && st[a][b] == false)
			{
				st[a][b] = true;
				q.push({a,b});
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
	
	//������������ 
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//����һ��������ˮ�ĵط�ʱ�ͽ���һ��dfs����bfs������ͨ�Ĳ���ȫ�����ϱ�� 
			if(p[i][j] == 'W' && st[i][j] == false)
			{
				ret++;
//				dfs(i,j);
				bfs(i,j);
			}
		}
	}
	
	cout << ret;
	
	return 0;
}
