#include<iostream>

using namespace std;

const int N = 1010;

int a[N],b[N],c[N];
int f[N][N];
int n,m,x;

int main()
{
	cin >> n >> m >> x;
	
	for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=x;k++)
			{
				f[i][j][k] = f[i-1][j][k];
				if(j >= b[i] && k >= c[i]) f[i][j][k] = max(f[i-1][j-b[i]][k-c[i]] + a[i], f[i][j][k]);
			}
		} 
	}
	
	cout << f[n][m][x];
	
	return 0;
} 

//¿Õ¼äÓÅ»¯ 
#include<iostream>

using namespace std;

const int N = 1010;

int a[N],b[N],c[N];
int f[N][N];
int n,m,x;

int main()
{
	cin >> n >> m >> x;
	
	for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=b[i];j--)
		{
			for(int k=x;k>=c[i];k--)
			{
				f[j][k] = f[j][k];
				f[j][k] = max(f[j-b[i]][k-c[i]] + a[i], f[j][k]);
			}
		} 
	}
	
	cout << f[m][x];
	
	return 0;
} 
