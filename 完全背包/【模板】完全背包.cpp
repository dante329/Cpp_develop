#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int v[N],w[N];
int f[N][N];
int n,m;

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= v[i])
			{
				f[i][j] = max(f[i-1][j],f[i][j-v[i]] + w[i]);
			}
		}
	}
	
	cout << f[n][m] << endl;
	
	memset(f,-0x3f3f3f3f,sizeof f);
	
	f[0][0] = 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= v[i])
			{
				f[i][j] = max(f[i-1][j],f[i][j-v[i]] + w[i]);
			}	
		}
	}
	
	if(f[n][m] < 0) cout << 0 << endl;
	else cout << f[n][m] << endl; 
	
	return 0;
}


//空间优化（滚动数组）
//01背包：第二层for循环从大到小
//完全背包：第二层for循环从小到大 
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int v[N],w[N];
int f[N];
int n,m;

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=v[i];j<=m;j++)
		{
			f[j] = max(f[j],f[j-v[i]] + w[i]);
		}
	}
	
	cout << f[m] << endl;
	
	memset(f,-0x3f3f3f3f,sizeof f);
	
	f[0] = 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[j] = max(f[j],f[j-v[i]] + w[i]);	
		}
	}
	
	if(f[m] < 0) cout << 0 << endl;
	else cout << f[m] << endl; 
	
	return 0;
}
