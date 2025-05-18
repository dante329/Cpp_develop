#include<iostream>
#include<cstring>

using namespace std;

const int N = 110, M = 50010;

int p[N],c[N];
int f[N][M]; //f[i][j]表示从1~i个奶牛公司中，至少买j磅干草的最少花费
int n,m; 

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> p[i] >> c[i];
	
	memset(f,0x3f3f3f3f,sizeof f);
	
	f[0][0] = 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = min(f[i-1][j], f[i][max(j-p[i],0)] + c[i]);
		}
	}
	
	cout << f[n][m] << endl;
	
	return 0;
}
