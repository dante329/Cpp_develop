#include<iostream>

using namespace std;

typedef long long LL;

const int p = 1e9 + 7;

LL n,k;

LL qpow(LL a,LL b,LL p)
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % p;
		b >>= 1;
		a = a * a % p; 
	}
	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> n >> k;
		
		LL ret = (qpow(k+1,n+1,p) - k - 1) * qpow(k,p-2,p);
	
		cout << (ret + p) % p << endl; //¸ºÊý²¹Õý 		
	}
	
	return 0;
}
