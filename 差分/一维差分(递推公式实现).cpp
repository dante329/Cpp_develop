//方式一：根据递推公式初始化差分数组，此时需要储存原始数据 
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10; 
LL a[N]; //存储原始数据 
LL f[N]; //差分数组 
int n,m; //元素数量，操作次数 
int main() 
{
	cin >> n >> m; 
	//存储数据 同时初始化差分数组 
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		f[i] = a[i] - a[i-1];
	}
	//处理数据，m次操作
	//对（l，r）序列统一加上k，等价于在f[l]+=k f[r+1]-=k 
	while(m--)
	{
		int l,r,k;
		cin >> l >> r >> k;
		f[l] += k; f[r+1] -= k;
	}
	//还原数组，对差分数组求前缀和就可以还原 
	for(int i=1;i<=n;i++)
	{
		//a[i] = a[i-1] + f[i] 是递推形式，适合编程实现。
		//a[i] = f[1] + f[2] + ... + f[i] 是显式形式，适合数学分析。
		a[i] = a[i-1] + f[i];
		cout << a[i] << " ";
	}
		 
	return 0;
}
