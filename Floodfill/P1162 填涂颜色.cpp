#include<iostream> 
using namespace std;
const int N = 35;
int a[N][N];
int st[N][N];
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x,int y)
{
	st[x][y] = true;
	for(int k=0;k<4;k++)
	{
		int i = x + dx[k], j = y + dy[k];
		if(i >= 0 && i <= n+1 && j >= 0 && j <= n+1 && st[i][j] == false && a[i][j] == 0)
		{
			dfs(i,j);
		}
	}	
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	
	dfs(0,0);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j] == 0 && st[i][j] == true) cout << 0 << " ";
			else if(a[i][j] == 1) cout << 1 << " ";
			else cout << 2 << " ";
		}
		cout << endl;
	}
	return 0;
}
