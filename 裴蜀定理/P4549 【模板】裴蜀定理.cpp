#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	int n; cin >> n;
	int ret; cin >> ret;
	ret = abs(ret);
	for(int i=2;i<=n;i++)
	{
		int x; cin >> x;
		ret = gcd(ret,abs(x));
	} 
	
	cout << ret;
	return 0;
}
