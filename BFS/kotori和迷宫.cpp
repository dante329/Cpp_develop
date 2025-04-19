//初版 
//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int N = 35;
//char a[N][N];
//int dist[N][N];
//int n,m;
//int x,y;
//int sum,ret = 1e5; //sum出口个数 ，ret最短路径 
//int dx[] = {1,-1,0,0};
//int dy[] = {0,0,1,-1};
// 
//void bfs()
//{
//	memset(dist,-1,sizeof dist);
//	queue<pair<int,int>> q;
//	q.push({x,y});
//	dist[x][y] = 0;  
//	while(q.size())
//	{
//		auto t = q.front(); q.pop();
//		int i = t.first; 
//		int j = t.second;
//		for(int k=0;k<4;k++)
//		{
//			int x = i + dx[k], y = j + dy[k];
//			if(x<1||x>n||y<1||y>m) continue;
//			if(dist[x][y] != -1) continue;
//			if(a[x][y] == '*') continue;
//			if(a[x][y] == '.') 
//			{
//				dist[x][y] = dist[i][j] + 1;
//				q.push({x,y}); 
//			}
//			if(a[x][y] == 'e') 
//			{
//				sum++;
//				dist[x][y] = dist[i][j] + 1;
//				ret = min(ret,dist[x][y]);
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
//			cin >> a[i][j];
//			if(a[i][j] == 'k') 
//			{
//				x=i,y=j;
//			}
//		}
//	}	
//			
//	bfs();
//	
//	if(sum) cout << sum << " " << ret;
//	else cout << -1;
//	return 0;
//}

简化条件判断（正向过滤） 
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 35;
char a[N][N];
int dist[N][N];
int n,m;
int x,y;
int sum,ret = 1e5; //sum出口个数 ，ret最短路径 
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
 
void bfs()
{
	memset(dist,-1,sizeof dist);
	queue<pair<int,int>> q;
	q.push({x,y});
	dist[x][y] = 0;  
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int i = t.first; 
		int j = t.second;
		for(int k=0;k<4;k++)
		{
			int x = i + dx[k], y = j + dy[k];
			if(x>=1 && x<=n && y>=1 && y<=m && a[x][y]!='*' && dist[x][y] == -1)
			{
				dist[x][y] = dist[i][j] + 1;
				if(a[x][y] == 'e')
				{
					sum++;				
					ret = min(ret,dist[x][y]);
					continue;
				}
				q.push({x,y}); 
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
			cin >> a[i][j];
			if(a[i][j] == 'k') 
			{
				x=i,y=j;
			}
		}
	}	
			
	bfs();
	
	if(sum) cout << sum << " " << ret;
	else cout << -1;
	return 0;
}

//标答 
//#include<iostream>
//#include<queue>
//#include<cstring>
//using namespace std;
//const int N = 35;
//char a[N][N];
//int dist[N][N];
//int n,m;
//int x,y;
//int sum,ret = 1e5; //sum出口个数 ，ret最短路径 
//int dx[] = {1,-1,0,0};
//int dy[] = {0,0,1,-1};
// 
//void bfs()
//{
//	memset(dist,-1,sizeof dist);
//	queue<pair<int,int>> q;
//	q.push({x,y});
//	dist[x][y] = 0;  
//	while(q.size())
//	{
//		auto t = q.front(); q.pop();
//		int i = t.first, j = t.second;  
//		for(int k=0;k<4;k++)
//		{
//			int x = i + dx[k], y = j + dy[k];
//			if(x>=1 && x<=n && y>=1 && y<=m && a[x][y]!='*' && dist[x][y] == -1)
//			{
//				dist[x][y] = dist[i][j] + 1;
//				if(a[x][y] == 'e') continue; 
//				q.push({x,y}); 
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
//			cin >> a[i][j];
//			if(a[i][j] == 'k') 
//			{
//				x=i,y=j;
//			}
//		}
//	}	
//			
//	bfs();
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)	
//		{
//			if(a[i][j] == 'e' && dist[i][j] != -1)
//			{
//				sum++;
//				ret = min(ret,dist[i][j]);
//			}
//		}
//	}	
//	
//	if(sum) cout << sum << " " << ret;
//	else cout << -1;
//	return 0;
//}
