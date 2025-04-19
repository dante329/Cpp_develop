//#include <iostream>
//using namespace std;
//int n,m,x,y; 
//const int N = 410;
//int a[N][N];
//int dx[] = {1,1,2,2,-1,-1,-2,-2};
//int dy[] = {2,-2,1,-1,2,-2,1,-1};
//int step;
//
//void bfs(int i,int j) //bfs�Ĺ��ܾ�����a������� 
//{
//	a[i][j] = step++;
//	for(int q=0;q<8;q++)
//	{
//		int k = i + dx[q], l = j + dy[q];
//		if(k<1||k>n||l<1||l>m) continue;
//		bfs(k,l);
//	} 
//}
//
//int main() 
//{
//	cin >> n >> m >> x >> y;
//	bfs(x,y);
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout << a[i][j] << " ";
//		cout << endl;
//	return 0;
//}


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> PII;
int n,m,x,y; 
const int N = 410;
int dist[N][N];
int dx[] = {1,1,2,2,-1,-1,-2,-2};
int dy[] = {2,-2,1,-1,2,-2,1,-1};

void bfs() //bfs�Ĺ��ܾ�����a��������������bfsʵ�ַ�ʽ��ͨ������ 
{
	memset(dist,-1,sizeof dist); //��ʼ��ľ���Ϊ0��Ϊ�����ִ����ѡ���ʼ��Ϊ-1 
	
	queue<PII> q;
	q.push({x,y});
	dist[x][y] = 0;
	
	while(!q.empty())
	{
		auto t = q.front(); q.pop();
		int i = t.first, j = t.second;
		//ö�ٳ���ͷԪ��(i,j)���п����ߵ���λ�� 
		for(int k=0;k<8;k++)
		{	 
			int x = i + dx[k], y = j + dy[k]; //���ﶨ��ľֲ���x��y������ȫ�ֱ���������ͻ��������ֲ�������Χ�ڵ��õľ��Ǿֲ����� 
			//�������ж� 
			if(x<1||x>n||y<1||y>m) continue;
			//���ܻص�����λ�ã���Ȼ����ѭ��������Ҳ�������Ѿ���ǹ������·�� 
			if(dist[x][y] != -1) continue; 
			
			dist[x][y] = dist[i][j] + 1; //(x,y)�Ǵ�(i,j)���ģ�����dist[i][j]�Ļ����ϼ�1 
			q.push({x,y});
		}		
	}

}

int main() 
{
	cin >> n >> m >> x >> y;
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
