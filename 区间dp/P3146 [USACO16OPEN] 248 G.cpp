#include<iostream>

using namespace std;
const int N = 255;

int a[N];
int f[N][N]; //f[i][j]表示：在区间[i,j]中能合并成一个数字的最大值，非法为0 
int n;

int main()
{
	cin >> n;
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ret = max(ret, a[i]);
	}

	//全部初始化为0 
		
	//长度为1的区间的状态为它本身 
	for(int i=1;i<=n;i++) f[i][i] = a[i];
	
	for(int len=2;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++)
		{
			int j = len+i-1;
			for(int k=i;k<j;k++)
			{
				if(f[i][k] != 0 && f[i][k] == f[k+1][j]) f[i][j] = max(f[i][j],f[i][k] + 1);
			}
			ret = max(ret,f[i][j]);
		}
	}
	
	cout << ret;
	return 0;
 } 
