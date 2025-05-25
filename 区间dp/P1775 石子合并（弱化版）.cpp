#include<iostream> 
#include<cstring>

using namespace std;

const int N = 310;

int sum[N]; //前缀和 
int f[N][N]; //f[i][j]表示合并[i,j]区间内所有石子的最小代价 
int n;

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		int x; cin >> x;
		sum[i] = sum[i-1] + x;
	}
	
	memset(f,0x3f,sizeof f);
	
	for(int i=1;i<=n;i++) f[i][i] = 0;
	
	for(int len=2;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++)
		{
			int j = len+i-1;
			int cnt = sum[j] - sum[i-1];
			//[i,j]区间的合并就是区间内任意两部分的合并
			//枚举分割点k，将区间分为[i,k][k+1,j] 
			for(int k=i;k<j;k++)
			{				
				f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + cnt);
			}
		}
	}
	
	cout << f[1][n];
	
	return 0;
}
