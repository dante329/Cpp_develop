#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL; 

const int N = 1e6 + 10;

int l,r;

//求[2,sqrt(r)]内的质数 
bool st[N]; 
int p[N],cnt;

//记录[l,r]内的合数个数 
bool ret[N];

//求[2,sqrt(r)]内的质数，可以埃氏筛，也可以线性筛 
void get_prime()
{
	int n = sqrt(r);
	for(LL i=2;i<=n;i++)
	{
		if(!st[i])
		{
			p[++cnt] = i;
			for(LL j=i*i;j<=n;j+=i)
			{
				st[j] = true;
			}
		}
	}
}

int main()
{
	cin >> l >> r;
	
	l = l == 1 ? 2 : l; 
	
	get_prime();
	
	//筛[l,r]内的质数，只能埃氏筛，因为我们要用质因子筛 
	for(LL i=1;i<=cnt;i++)
	{
		int x = p[i];
		for(LL j=max(2*x,(x+l-1)/x*x);j<=r;j+=x) //最小要取i*x是避免把自己筛掉 
		{
			ret[j-l+1] = true;
		}
	} 
	
	int sum = 0;
	for(int i=l;i<=r;i++)
	{
		if(!ret[i-l+1]) sum++;
	}
	cout << sum;
	
	return 0;
} 
