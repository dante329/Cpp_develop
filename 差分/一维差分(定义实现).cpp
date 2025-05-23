//方式二：根据差分数组定义初始化差分数组，此时不需要储存原始数据 
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10; 
//LL a[N]; //存储原始数据 
LL f[N]; //差分数组 
int n,m; //元素数量，操作次数 
int main() 
{
	cin >> n >> m; 
	//存储数据 同时初始化差分数组 
	for(int i=1;i<=n;i++) 
	{
		int x; cin >> x;
		f[i] += x;
		f[i+1] -= x; 
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
	//注意：使用差分数组的时候，必须要等所有操作完毕之后，再还原数组
	//因为还原数组的时间复杂度是O（n），如果需要频繁还原数组，那么就不建议使用差分数组，而是线段树 
	for(int i=1;i<=n;i++)
	{
		//怎么取理解这个公式，记住f[1] = a1  f[2] = a2 - a1，从第一个元素开始，把前一个元素和后一个相加得到的就是当前元素。之所以要赋值给f[i]，是因为这是递推公式，要不断计算出下一个值 
		f[i] = f[i] + f[i-1];
		cout << f[i] << " ";
	}
		 
	return 0;
}
