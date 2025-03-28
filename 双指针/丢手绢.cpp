#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
int main()
{
	cin >> n;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	int left = 1,right = 1;
	int ret = 0,k = 0;
	while(right <= n)
	{
		k += a[right];
		while(2*k > sum)
		{
			ret = max(ret,sum-k);
			k -= a[left++];
		}
		ret = max(ret,k);
		right++;
	}
	cout << ret;
	return 0; 
}
