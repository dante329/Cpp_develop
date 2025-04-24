//�ݸ�
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

//�ݸ�Ľ� 
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

//���� 
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
		//ֻ�ж����е�����(x,y)���Ԫ�ص���(x2,y2)��ʱ����ܼ�֦��pop��֮��˵��������������� 
		if(x == x2 && y == y2) return;
		
		for(int i=0;i<4;i++)
		{
			int a = x + dx[i], b = y + dy[i];
			//�ж�a��b�Ϸ� 
			if(a >= 0 && a < n && b >= 0 && b < m)
			{
				//�ж�(a,b)��(x,y)���ַ��Ƿ���ͬ 
				char ch = p[x][y], next = p[a][b];
				//�����������w 
				int w = (ch == next ? 0 : 1);
				
				//��һ��BFS��ĳ���� 
				if(dist[a][b] == -1) 
				{
					dist[a][b] = dist[x][y] + w;
					//��һ��BFS��ĳ��������Ҫ������������еģ��������Ϊ0������ף�����Ϊ1�����β 
					if(w == 0) dq.push_front({a,b});
					else dq.push_back({a,b}); 
				}
				//BFS��֮ǰ���ʹ��ĵ㣬�жϵ�ǰ·���Ƿ���š�ע���ٴα�����ĳ����ʱ����Ҫ�ٽ�����������е� 
				else if(dist[a][b] + w < dist[x][y])
				{
					//�ɳڲ��� 
					dist[a][b] = dist[x][y] + w;
				}
				//ע���������ǲ��ܼ�֦�ģ����������(x2,y2)���ڵ�ĳ���������������ƶ�ʱ���ʵ���(x2,y2)��������������(x2,y2)�ˡ��п��ܻ�û�ҳ�(x2,y2)������·�� 
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
