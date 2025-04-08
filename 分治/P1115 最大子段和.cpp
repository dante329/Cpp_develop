#include<iostream>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;

int dfs(int left,int right)
{
	if(left == right) return a[left];
	
	int mid = (left + right) / 2;
	int ret = max(dfs(left,mid),dfs(mid+1,right));
	
	//处理跨区间最大子段和 
	
	//错误操作
	//使用 lmax 和 rmax 表示左右最大和，初始化为 0。
	//可能导致逻辑错误：如果所有数为负数，lmax 和 rmax 会被错误地赋值为 0（而非实际的最大负数和）。 
//	int sum = 0, lmax = 0;
//	for(int i=mid;i>=left;i--)
//	{
//		sum += a[i];
//		lmax = max(sum,lmax);
//	}
//	sum = 0; int rmax = 0;
//	for(int i = mid+1;i<=right;i++)
//	{
//		sum += a[i];
//		rmax = max(sum,rmax);
//	}
//	
//	ret = max(ret,lmax+rmax);
//	return ret;

	int sum = a[mid], lmax = sum;
	for(int i=mid-1;i>=left;i--)
	{
		sum += a[i];
		lmax = max(sum,lmax);
	}
	sum = a[mid+1]; int rmax = sum;
	for(int i = mid+2;i<=right;i++)
	{
		sum += a[i];
		rmax = max(sum,rmax);
	}
	
	ret = max(ret,lmax+rmax);
	return ret;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cout << dfs(1,n) << endl; 
	return 0;
 } 
