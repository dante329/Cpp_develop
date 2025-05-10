#include <iostream>
using namespace std;
typedef long long LL;
const int N = 65;
LL f[N];
int n;

int main() 
{
	cin >> n;
	
	//初始化 
	f[0] = 1,f[1] = 1,f[2] = 2;
	
	for(int i=3;i<=n;i++)
	{
		//状态转移方程 
		f[i] = f[i-1] + f[i-2] + f[i-3];
	}	
	cout << f[n];
	
	//滚动数组版
//	int a = 1,b = 1,c = 2;
//	for(int i=3;i<=n;i++)
//	{
//		int t = a + b + c;
//		a = b;
//		b = c;
//		c = t;
//	}
//	if(n == 1) cout << b;
//	else cout << c; 
	return 0;
}
