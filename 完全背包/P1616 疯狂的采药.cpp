#include<iostream>

using namespace std;
typedef long long LL;
const int N = 1e4 + 10, M = 1e7 + 10;

LL f[M];
int v[N],w[N];
int n,m;

int main()
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=v[i];j<=m;j++)
		{
			f[j] = max(f[j],f[j-v[i]] + w[i]);
		}
	}
	
	cout << f[m] << endl;
	return 0;
} 
