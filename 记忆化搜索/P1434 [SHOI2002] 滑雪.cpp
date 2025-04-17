#include<iostream>
using namespace std;
const int N = 110;
int a[N][N];
int f[N][N];
int n,m;
//方向向量
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int dfs(int i,int j)
{
	if(f[i][j]) return f[i][j];
	int len = 1;
	//向四个方向探索，在循环外面定义一个len，不断地dfs找到当前点最长的距离 
	for(int k=0;k<4;k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(x<1||y<1||x>n||y>n) continue;
		if(a[x][y] < a[i][j]) continue;
		len = max(1+dfs(x,y),len);
	}
	return f[i][j] = len;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	
	int ret = 1;		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ret = max(ret,dfs(i,j));
			
	cout << ret;
	return 0;
 } 
