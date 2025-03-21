//绝对值不等式 |a-x| + |b-x| >= |a-b|   x在a,b中间时去等 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;

int main() 
{
	cin >> n;
	//读入无序数据 
	for(int i=1;i<=n;i++) cin >> a[i];
	//排序 
	sort(a+1,a+n+1);
	int ret = 0;
	//方法1：直接用公式计算 
//	 
//	//n为奇数时，货舱位置肯定在中间那个数字上，中间那个数字距离货舱的距离为0，不需要计算 
//	for(int i=1;i<=n/2;i++) ret += abs(a[i]-a[n+1-i]);
//	 

	//方法2：将货仓设置在排完序的数据的中间，要考虑奇数偶数怎么样才能取到中间值 
	for(int i=1;i<=n;i++) ret += abs(a[i]-a[(n+1)/2]);
	
	
	cout << ret; 
	return 0;
}
