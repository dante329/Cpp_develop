//草稿，没听清讲的什么，然后就给bfs，dfs套一起了，耄耋无语。。。 
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


//这里是想用bfs代替for循环整个矩阵，然后遇到水就bfs，但是似乎不可行 
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

//正确模板 
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
//	if(p[x][y] == '.') return; //这条语句是没有意义的，因为'.'已经被if过滤了，根本就不会进入 

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
	
	//遍历整个数组 
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//当第一次遇到有水的地方时就进行一次dfs或者bfs，将连通的部分全部打上标记 
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
