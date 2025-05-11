#include <iostream>
using namespace std;
const int N = 1e5 + 10, MOD = 1e5 + 3;

int f[N];
int n,k;

int main() 
{
	cin >> n >> k;
	
	f[0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k && i-j >= 0;j++)
		{
			f[i] = (f[i] + f[i-j]) % MOD;
		}
	}
	
	cout << f[n]; 
	return 0;
}
