//求单个数的欧拉函数 + 递归 
//#include <iostream>
//using namespace std;
//typedef long long LL;
//
//LL get_phi(LL x) {
//    LL ret = x;
//    for (int i = 2; i <= x / i; i++) {
//        if (x % i == 0) {
//            ret = ret / i * (i - 1);
//            while (x % i == 0) x /= i;
//        }
//    }
//    if (x > 1) ret = ret / x * (x - 1);
//    return ret;
//}
//
//LL qpow(LL a, LL b, LL p) {
//    LL ret = 1;
//    a %= p;
//    while (b) {
//        if (b & 1) ret = ret * a % p;
//        b >>= 1;
//        a = a * a % p;
//    }
//    return ret;
//}
//
//LL solve(LL p) {
//    if (p == 1) return 0;
//    LL phi = get_phi(p);
//    LL a = solve(phi);
//    return qpow(2, a + phi, p);
//}
//
//int main() {
//    int T; cin >> T;
//    while (T--) {
//        LL p; cin >> p;
//        cout << solve(p) << endl;
//    }
//    return 0;
//}

//欧拉筛打表欧拉函数 + 递归 
#include<iostream>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;

bool st[N];
int phi[N],cnt,p[N],n = 1e7;

void get_phi()
{
	phi[1] = 1;
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
		{
			phi[i] = i-1;
			p[++cnt] = i;
		}
		for(int j=1;i*p[j] <= n;j++)
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

LL qpow(LL a, LL b, LL x)
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % x;
		b >>= 1;
		a = a * a % x;
	}
	return ret;
}

int dfs(int x)
{
	if(x == 1) return 0;
	return qpow(2,dfs(phi[x])+phi[x],x);
}

int main()
{
	get_phi();
	
	int T; cin >> T;
	while(T--)
	{
		int p; cin >> p;
		
		cout << dfs(p) << endl;
	}
	
	return 0;
}
