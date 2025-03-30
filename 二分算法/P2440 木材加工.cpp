#include<iostream>
using namespace std;
typedef long long LL;
int n,k;
const int N = 1e5 + 10;
LL a[N];

int calc(int l)
{
	LL ret = 0;
	for(int i=1;i<=n;i++)
	{
		ret += a[i]/l;
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	//读数据，并求最大长度
	LL maxLen = 0;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		maxLen = max(a[i],maxLen);
	}  
	//从大到小枚举长度会超时 
//	for(int l=maxLen;l>=1;l--)
//	{
//			
//	} 
	//用二分优化
	LL left = 0, right = maxLen, mid = 0;
	while(left < right)
	{
		mid = (left+right+1)/2;
		if(calc(mid) >= k) left = mid;
		else right = mid - 1;
	} 
	cout << left << endl;
    return 0;
}
