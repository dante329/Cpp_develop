#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int f[N][N],a[N][N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	
	//将边缘值设置为无穷大，就不会影响状态转移方程的取最小值 
	memset(f[0],0x3f3f3f3f,sizeof f[0]);
	for(int i=1;i<=n;i++) f[i][0] = 0x3f3f3f3f; 
		
	//初始化
	f[1][1] = a[1][1];	
	
	//状态转移方程 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==1 && j==1) continue;
			f[i][j] = min(f[i-1][j],f[i][j-1]) + a[i][j];
		}

//调试	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}	
	
	cout << f[n][m] << endl;
	return 0;
}

//题解代码，不需要存原始的矩阵
int main()
{
	cin >> n >> m;
	
	//初始化
	memset(f,0x3f,sizeof f); //直接将整个f数组初始化为无穷大		
	
	f[0][1] = 0; //但是需要将[0,1]位置的值设置为0，要不然f[1][1]取不到正确的值。
	//在我的代码里求f[1][1]是直接手动初始化的，但是在循环中需要特判跳过[1,1]。题解的方法就更简洁 
	
	//状态转移方程 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int a; cin >> a;
			f[i][j] = min(f[i-1][j],f[i][j-1]) + a;
		}
	
	
	cout << f[n][m] << endl;
	return 0;
} 
