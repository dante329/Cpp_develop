#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> PII;
int n,m;
const int N = 1e3 + 10;
int p[N][N];
//int dist[N][N]; ������ʵ����Ҫdist����Ϊ����Ҫ�����������·��������ֻ��Ҫͨ��BFS�ж��Ƿ���ͨ· 
bool st[N][N]; //��Ǹõ��Ƿ��߹� 
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//��Դbfs 
bool bfs(int mid)
{
	//��ΪҪ����1��ȫ����ӣ�����Ҫ����������� 
	if(n == 1) return true;
	
	memset(st,0,sizeof st);
	
	//��n=1ȫ����������� 
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
	//���ִ𰸣����ֵ����˺�ֵ���˺�ֵ�Ǵ�0����� 
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
		if(bfs(mid)) r = mid; //bfs��check 
		else l = mid + 1;
	}
	
	cout << l; 
	return 0;
}
