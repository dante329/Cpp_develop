#include<iostream>
using namespace std;
typedef long long LL;

LL a,m;
string b;

LL get_phi(LL m)
{
	LL ret = m;
	for(int i=2;i<=m/i;i++)
	{
		if(m % i == 0) 
		{
			ret = ret * (i - 1) / i;
			while(m % i == 0) m /= i;
		}
	}
	if(m > 1) ret = ret * (m - 1) / m; //这里的判断条件必须是m>1，不能写成if(m)，这样m=1的时候也会进去 
	return ret;
}

LL get_newb(string& b, LL phi)
{
	LL t = 0;
	bool flag = false;
	for(auto ch:b)
	{
		t = t * 10 + ch - '0';
		if(t >= phi) 
		{
			t %= phi;
			flag = true;
		}
	}
	if(flag) t += phi;
	return t;
}

LL qpow(LL a, LL b ,LL m) 
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return ret;
}

int main()
{
	cin >> a >> m >> b; 
	
	LL phi = get_phi(m); //求单个数的欧拉函数：质因数分解+欧拉函数公式法
	
	LL new_b = get_newb(b,phi); //扩展欧拉定理降幂 
	
	cout << qpow(a,new_b,m) << endl;
	return 0;
} 
