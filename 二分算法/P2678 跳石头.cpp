#include<iostream>
using namespace std;
typedef long long LL;
const int N = 5e4 + 10;
LL a[N];
LL l,n,m;

LL calc(LL x)
{
	LL ret = 0;
	for(int i=0;i<=n;i++)
	{		
		int j = i + 1;  
		while(j <= n && a[j] - a[i] < x) j++;
		ret += j - i - 1;
		i = j - 1;
	}
	return ret;
}

int main()
{
	cin >> l >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	a[n+1] = l;
	n++;
	LL left = 1,right = l;
	while(left < right)
	{
		LL mid = (left + right + 1) / 2;
		if(calc(mid) > m) right = mid - 1;
		else left = mid;
	}
	cout << left;
	return 0;
 } 
