#include<iostream>

using namespace std;

const int N = 2010;

int n;
int a[N];
int f[N][N];

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//全部初始化为0，非法的格子取到0也没事，不会对去max有影响
	 
	//状态转移方程 
	for(int len=1;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++)
		{
			int j = len + i - 1;
			int cnt = n - len + 1; //第cnt天 
			
			f[i][j] = max(f[i+1][j] + a[i]*cnt, f[i][j-1] + a[j]*cnt);	
		}
	 } 
	
	cout << f[1][n];
	return 0;
}
