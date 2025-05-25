#include<iostream>
#include<cstring>

using namespace std;

const int N = 210;

int s[N]; //先用来存数据，然后改成前缀和数组
int f[N][N],g[N][N]; //f[i][j]存最小值，g[i][j]存最大值 
int n;

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) 
	{
		cin >> s[i];
		s[i+n] = s[i]; //处理环形问题，复写 
	}
	
	//前缀和
	for(int i=1;i<=2*n;i++)
	{
		s[i] += s[i-1];
	} 
	
	//初始化dp表 
	memset(f,0x3f,sizeof f); //如果不初始化为0x3f，那么原来的值就是0，取min的时候就会取到0
	memset(g,-0x3f,sizeof g);
	
	//初始化正确的逻辑 
	//在[i,j]这个区间中，当区间长度为1时，它本身就是一堆了，不需要再合并，所以合并的代价是0 
	for(int i=1;i<=2*n;i++)
	{
		f[i][i] = 0;
		g[i][i] = 0;
	}
	  
	//状态转移方程len从2开始遍历 
	for(int len=2;len<=n;len++)
	{
		//枚举左端点 
		for(int i=1;len+i-1<=2*n;i++)
		{
			int j = len + i - 1;
			int cnt = s[j] - s[i-1];
			//枚举分割点[i,k][k+1,j] 
			for(int k=i;k<j;k++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + cnt);	
				g[i][j] = max(g[i][j],g[i][k] + g[k+1][j] + cnt);
			} 
		}
	}
	
	//取结果
	int ret1 = 0x3f3f3f3f, ret2 = -0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		ret1 = min(ret1,f[i][n+i-1]);
		ret2 = max(ret2,g[i][n+i-1]);
	} 
	
	cout << ret1 << endl << ret2;
	
	return 0;
}
