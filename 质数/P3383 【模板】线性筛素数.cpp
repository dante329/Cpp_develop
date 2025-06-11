#include<iostream>

using namespace std;

typedef long long LL; 

const int N = 1e8 + 10;

int n,q;
bool st[N];
int p[N],cnt;

//埃氏筛
void get_prime1()
{
	for(LL i=2;i<=n;i++) //开LL 
	{
		if(!st[i]) //是质数 
		{
			p[++cnt] = i;
			for(LL j=i*i;j<=n;j+=i) //开LL 小优化：从i*i开始遍历 
			{
				st[j] = true;
			}
		}
	}
}

//线性筛 
void get_prime2()
{
	for(LL i=2;i<=n;i++) //LL是防止 i * p[j]的时候溢出 
	{
		if(!st[i]) p[++cnt] = i; //没有标记就是质数，加入质数的数组 
		
		for(in t j=1;i * p[j] <= n;j++) //j是p数组的下标，依次筛去i的质数倍 
		{
			st[i * p[j]] = true; //合数打上标记，筛掉 
			if(i % p[j] == 0) break; //如果i是该质数的倍数就停止 
		}
	}
}

int main()
{
	scanf("%d%d",&n,&q);
	get_prime1();
	
	while(q--)
	{
		int k; cin >> k;
		printf("%d\n",p[k]);
	}
	return 0;
} 
