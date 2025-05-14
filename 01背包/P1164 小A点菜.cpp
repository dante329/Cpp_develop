#include<iostream>

using namespace std;

const int N = 1010;

int a[N],f[N][M];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= a[i]) f[i][j] += f[i-1][j-a[i]];
		}
	 } 

	cout << f[n][m];
	return 0;
}

//¿Õ¼äÓÅ»¯
#include<iostream>

using namespace std;

const int N = 1010, M = 10010;

int a[N],f[M];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
		{
			f[j] += f[j-a[i]];
		}
	 } 

	cout << f[m];
	return 0;
} 
