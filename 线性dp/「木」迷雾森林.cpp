#include<iostream>

using namespace std;

const int N = 3010;

int a[N][N];
int f[N][N];
int n,m;


int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//³õÊ¼»¯ 
	f[n][0] = 1;
	
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j] == 0) f[i][j] = (f[i+1][j] + f[i][j-1]) % 2333;
		}
	}
	
	cout << f[1][m];
	return 0;
 } 
