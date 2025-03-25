#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL f[N];
int n,m;

int main()
{
	cin >> n >> m;
	//利用差分数组计算每段路线分别走多少次 
//	for(int i=1;i<=m;i++) 
//	{
//		cin >> x >> y; //如果这样读入两个站点的话，数据个数为奇数个怎么办。 
//	}
	int x; cin >> x; //先读入一个x，再循环读入y，在每次循环结束时将y赋值给x 
	//初始化差分数组（统计路段次数） 
	for(int i=2;i<=m;i++)
	{
		int y; 
		cin >> y;
		if(x > y) //从大站点到小站点要反过来加减差分数组 
		{
			f[x]--;
			f[y]++;
		 } 
		else
		{
			f[x]++;
			f[y]--;
		}
		x = y; 
	}
	//还原数组 
	LL ret = 0;
	for(int i=1;i<n;i++)
	{
		f[i] += f[i-1]; //改变后的数组 直接存在 差分数组中
		//读取a,b,c
		int a,b,c;
		cin >> a >> b >> c; 	
		//f中此时存了每段路的经过次数
		ret += min(a * f[i], c + b * f[i]); //直接买票，买ic卡	
	}
	cout << ret;
	return 0;
} 
