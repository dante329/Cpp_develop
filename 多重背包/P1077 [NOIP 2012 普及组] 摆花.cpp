#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N][N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j++) //可以正序也可以逆序，以为用不到当前行的格子 
		{
			for(int k=0;k<=a[i] && k<=j;k++) //k从0开始遍历，包含了不选和选k次所有情况 
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	//单独处理不选，防止空间优化出错 
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			//不选 
			f[i][j] = f[i-1][j];
			//选1~k次 
			for(int k=1;k<=a[i] && k<=j;k++)
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	cout << f[n][m];
	return 0;
}

//空间优化
#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N][N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;

	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=1;k<=a[i] && k<=j;k++)
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	cout << f[n][m];
	return 0;
} 
