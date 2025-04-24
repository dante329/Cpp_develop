//草稿
//#include <iostream>
//#include <deque>
//#include <cstring>
//using namespace std;
//typedef pair<int,int> PII;
//int n,m;
//const int N = 510;
//char p[N][N];
//int dist[N][N];
//int x1,y1,x2,y2;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//
//void bfs()
//{
//	deque<PII> dq;
//	dq.push_back({x1,y1});
//	dist[x1][y1] = 0;
//	while(dq.size())
//	{
//		auto t = dq.front(); dq.pop_front();
//		int x = t.first, y = t.second;
//		for(int i=0;i<4;i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if(a >= 0 && a <= n && b >= 0 && b <= m)
//			{
//				int tmp;
//				if(p[a][b] == p[x][y]) tmp = 0;
//				else tmp = 1;
//				
//				if(dist[a][b] == -1)
//				{
//					dist[a][b] = dist[x][y] + tmp;
//				} 
//				else
//				{		
//					if(tmp < dist[a][b]) dist[a][b] = tmp;
//					else continue;
//					if(dist[a][b] == 1) dq.push_back({a,b});
//					else dq.push_front({a,b});
//				}
//			}
//		}
//	}
//}
//
//int main() 
//{
//	while(cin >> n >> m && n && m)
//	{
//		memset(dist,-1,sizeof dist);
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//			{
//				cin >> p[i][j];
//			}
//		}
//		cin >> x1 >> y1 >> x2 >> y2;
//		
//		bfs();
//		
//		cout << dist[x2][y2] << endl; 
//	}
//	return 0;
//}

//草稿改进 
//#include <iostream>
//#include <deque>
//#include <cstring>
//using namespace std;
//typedef pair<int,int> PII;
//int n,m;
//const int N = 510;
//char p[N][N];
//int dist[N][N];
//int x1,y1,x2,y2;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//
//void bfs()
//{
//	deque<PII> dq;
//	dq.push_back({x1,y1});
//	dist[x1][y1] = 0;
//	while(dq.size())
//	{
//		auto t = dq.front(); dq.pop_front();
//		int x = t.first, y = t.second;
//		for(int i=0;i<4;i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if(a >= 0 && a < n && b >= 0 && b < m)
//			{
//				int tmp;
//				if(p[a][b] == p[x][y]) tmp = 0;
//				else tmp = 1;
//				
//				if(dist[a][b] == -1)
//				{
//					dist[a][b] = dist[x][y] + tmp;
//					if(dist[a][b] == 1) dq.push_back({a,b});
//					else dq.push_front({a,b});
//				} 
//				else
//				{		
//					if(dist[a][b] + tmp < dist[x][y]) dist[x][y] = dist[a][b] + tmp;
//					
//				}
//			}
//		}
//	}
//}
//
//int main() 
//{
//	while(cin >> n >> m && n && m)
//	{
//		memset(dist,-1,sizeof dist);
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<m;j++)
//			{
//				cin >> p[i][j];
//			}
//		}
//		cin >> x1 >> y1 >> x2 >> y2;
//		
//		bfs();
//		
//		cout << dist[x2][y2] << endl; 
//	}
//	return 0;
//}

//正解 
#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 510;

char p[N][N];
int dist[N][N];
int n,m;
int x1,y1,x2,y2;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs()
{
	if(x1 == x2 && y1 == y2)
	{
		dist[x2][y2] = 0;
		return;
	}
	
	memset(dist,-1,sizeof dist);
	deque<PII> dq;
	dq.push_back({x1,y1});
	dist[x1][y1] = 0;
	
	while(dq.size())
	{
		auto t = dq.front(); dq.pop_front();
		int x = t.first, y = t.second;
		//只有队列中弹出的(x,y)这个元素等于(x2,y2)的时候才能剪枝，pop掉之后说明这个点真正到了 
		if(x == x2 && y == y2) return;
		
		for(int i=0;i<4;i++)
		{
			int a = x + dx[i], b = y + dy[i];
			//判断a、b合法 
			if(a >= 0 && a < n && b >= 0 && b < m)
			{
				//判断(a,b)与(x,y)的字符是否相同 
				char ch = p[x][y], next = p[a][b];
				//计算距离增量w 
				int w = (ch == next ? 0 : 1);
				
				//第一次BFS到某个点 
				if(dist[a][b] == -1) 
				{
					dist[a][b] = dist[x][y] + w;
					//第一次BFS到某个点是需要将这个点加入队列的，如果增量为0加入队首，增量为1加入队尾 
					if(w == 0) dq.push_front({a,b});
					else dq.push_back({a,b}); 
				}
				//BFS到之前访问过的点，判断当前路径是否更优。注意再次遍历到某个点时不需要再将这个点加入队列的 
				else if(dist[a][b] + w < dist[x][y])
				{
					//松弛操作 
					dist[a][b] = dist[x][y] + w;
				}
				//注意在这里是不能剪枝的，这里可能是(x2,y2)相邻的某个点在上下左右移动时访问到的(x2,y2)，而不是真正到(x2,y2)了。有可能还没找出(x2,y2)的最优路径 
//				if(x == x2 && y == y2) return;
			}
		}
	}
}

int main() 
{
	while(cin >> n >> m && n && m)
	{		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> p[i][j];
			}
		}
		cin >> x1 >> y1 >> x2 >> y2;
		
		bfs();
		
		cout << dist[x2][y2] << endl; 
	}
	return 0;
}
