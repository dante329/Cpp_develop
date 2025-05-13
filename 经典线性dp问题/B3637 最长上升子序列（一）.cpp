//时间复杂度O(n^2) 数据量较小可使用 
#include <iostream>
using namespace std;
const int N = 5010;

int a[N];
int f[N]; //f[i]表示以a[i]为结尾的所有子序列中，最长上升子序列的长度 
int n;
 
int main() 
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		f[i] = 1; //最差情况，单独一个数成为子序列，所以起码长度为1，先初始化为1
		for(int j=1;j<i;j++)
		{
			if(a[j] < a[i])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}	
		ret = max(ret,f[i]);
	}	
	
	cout << ret;
	return 0;
}
