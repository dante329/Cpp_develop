//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef long long LL;
//int m,n;
//const int N = 1e5 + 10;
//LL a[N];
//
//int main()
//{
//	cin >> m >> n;
//	for(int i=1;i<=m;i++) cin >> a[i];
//	a[0] = 1e7;
//	sort(a+1,a+m+1,less<LL>());
//	LL ret = 0;
//	for(int i=1;i<=n;i++) 
//	{
//		LL b; cin >> b;
//		auto it = lower_bound(a+1,a+n+1,b);
//		LL big = abs(*it - b);
//		LL sml = abs(*(it-1) - b);
//		ret += min(big,sml);
//	}
//	cout << ret;
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
int m,n;
const int N = 1e5 + 10;
LL a[N];

int find(LL x)
{
	LL* pos = lower_bound(a+1,a+m+1,x);
	int ret = pos - a;
	return ret > m ? m:ret;
}

//int find(LL x)
//{
//	int left = 1, right = m;
//	while(left < right)
//	{
//		int mid = (left + right)/2;
//		if(a[mid] >= x) right = mid;
//		else left = mid + 1;
//	}
//	return left;
//}


int main()
{
	cin >> m >> n;
	for(int i=1;i<=m;i++) cin >> a[i];
	a[0] = 1e7;
	sort(a+1,a+m+1,less<LL>());
	LL ret = 0;
	for(int i=1;i<=n;i++) 
	{
		LL b; cin >> b;
		int pos = find(b);
		ret += min(abs(a[pos] - b),abs(a[pos-1] - b));
	}
	cout << ret;
	return 0;
}
