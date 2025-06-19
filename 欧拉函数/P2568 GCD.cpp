#include<iostream>

using namespace std;
typedef long long LL;
const int N = 1e7 + 10;

int n,cnt,p[N],phi[N];
LL f[N];
bool st[N];

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
	
	for(int i=1;i<=n;i++)
	{
		f[i] = f[i-1] + phi[i];
	}
		
	LL ret = 0;
	for(int i=1;i<=cnt;i++)  
	{
		int t = p[i]; //Ã¶¾ÙÖÊÊý 
		ret += f[n/t] * 2 - 1;
	}
	
	cout << ret;
	
	return 0;
}
 
