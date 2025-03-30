//总结：遇到数据量大或者数据大小很大的，把所有能替换的int全部换成LL，不要尝试去理解逻辑 
#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N];
LL n,m;

LL clac(LL h)
{
	LL sum = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i] > h) sum += a[i] - h;
	}
	return sum;
}

int main()
{
	cin >> n >> m; //m是一个标准 
	for(int i=1;i<=n;i++) cin >> a[i];
	//二分高度 与需要的木材总长度m作比较
	LL left = 0,right = 1e6;
	while(left < right)
	{
		LL mid = (left + right + 1) / 2;
		if(clac(mid) >= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	return 0;
}
