#include<iostream>

using namespace std;

const int N = 1e6 + 10; 

int p[N],cnt;
bool st[N]; 

void get_prime()
{
	for(int i=2;i<=1e6;i++)
	{
		if(!st[i]) p[++cnt] = i;
		for(int j=1;i * p[j] <= 1e6;j++)
		{
			st[i*p[j]] = true;
			if(i % p[j] == 0) break;
		}
	}
}

int main()
{
	get_prime();
	int n;
	while(cin >> n, n)
	{
		for(int i=3;i<=n/2;i++)
		{
			if(!st[i] && !st[n-i]) 
			{
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			 } 
		}
	}
	
	return 0;
 } 
