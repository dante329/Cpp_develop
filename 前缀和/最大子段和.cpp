#include<iostream>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;

LL f[N];
int n;

int main()
{
	cin >> n;
	LL ret = -1e11;
	LL premini = 0;  
	for(int i=1;i<=n;i++)
	{
		int x; cin >> x;
		f[i] = f[i-1] + x;
		//最大子段和是 f[i] - f[x]  (1 <= x < i)
		//先求ret的最大值 
		ret = max(f[i] - premini,ret);
		//再更新premini的最小值 premini就是f[x]，f[x]在求最小的时候是不能取到i位置的 
		premini = min(f[i],premini); 
		
	}
	cout << ret; 
	return 0;
 } 
