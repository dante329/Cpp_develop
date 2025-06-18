#include <iostream>

using namespace std;

const int N = 4e4 + 10;

int n;
bool st[N];
int cnt,p[N],phi[N];

void get_phi()
{
	phi[1] = 1;
	for(int i=2;i<=n;i++)
	{
		if(!st[i]) 
		{
			p[++cnt] = i;
			phi[i] = i - 1;
		}
		for(int j=1;i*p[j]<=n;j++)
		{
			int x = i * p[j];
			st[x] = true;
			if(i % p[j] == 0)
			{
				phi[x] = phi[i] * p[j];
				break;
			}
			else
			{
				phi[x] = phi[i] * (p[j] - 1);
			}
		}
	}
}

int main() 
{
	cin >> n;
	
	get_phi();
	
	int ret = 0;
	for(int i=1;i<n;i++)
	{
		ret += phi[i];
	}
	
	if(n==1) cout << 0;
	else cout << ret * 2 + 1; 
	return 0;
}
