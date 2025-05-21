#include <iostream>
#include <cstring> 

using namespace std;

const int N = 1010;

int f[N][N];
int v[N],w[N];
int n,m; //n个物品，背包体积m 

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	//第一问 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) //在v[i]有可能等于0时，j必须从0开始初始化。因为j>=v[i]所以一定不会越界 
		{ 
			f[i][j] = f[i - 1][j]; //一进来先假设不选 
			if(j >= v[i]) //体积够就重新赋值 
			{
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);		
			}
			
			//不能像下面这样写，注意区分。先f[i][j] = f[i - 1][j]这样如果进入了下面那个if中才有东西可以取max，不然f[i][j]的值是0 
//			if(j >= v[i]) //还有体积 
//			{
//				f[i][j] = f[i-1][j-v[i]] + w[i];		
//			}		
//			else //体积不够 
//			{
//				f[i][j] = f[i-1][j];
//			}
		}
	} 

	cout << f[n][m] << endl;
	
	//第二问
	memset(f,-0x3f3f3f3f,sizeof f);
	f[0][0] = 0; 
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) 
		{
			f[i][j] = f[i - 1][j]; 
			if(j >= v[i]) 
			{
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);		
			}
		}
	} 

	if(f[n][m] < 0) cout << 0 << endl;
	else cout << f[n][m] << endl;
	
	return 0;
}


//空间优化版（滚动数组）
#include <iostream>
#include <cstring> 

using namespace std;

const int N = 1010;

int f[N];
int v[N],w[N];
int n,m; //n个物品，背包体积m 

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	//第一问 
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=v[i];j--) 
		{ 
			f[j] = max(f[j], f[j - v[i]] + w[i]);		
		}
	} 

	cout << f[m] << endl;
	
	//第二问
	memset(f,-0x3f3f3f3f,sizeof f);
	f[0] = 0; 
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=v[i];j--) 
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);		
		}
	} 

	if(f[m] < 0) cout << 0 << endl;
	else cout << f[m] << endl;
	
	return 0;
} 
