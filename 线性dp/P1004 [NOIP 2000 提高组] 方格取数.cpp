#include<iostream>

using namespace std;

const int N = 10;

int a[N][N];
//本题使用四维数组f[i1][j1][i2][j2] 表示(i1,j1)(i2,j2)同时进行两条最大路径的搜索
//但是可以优化成三维数组f[sum][i1][i2] 因为(i1,j1)(i2,j2)必须同时移动，所以它们的横纵坐标和sum肯定相等，那么可以根据sum和i1,i2推算出j1,j2 
int f[N * 2][N][N]; 
int n;

int main()
{
	cin >> n;
	int x,y,v; 
	while(cin >> x >> y >> v, x && y && v)
	{	
		a[x][y] = v;
	}
	
	for(int s=2;s<=n*2;s++)
	{
		for(int i1=1;i1<=n;i1++)
		{
			for(int i2=1;i2<=n;i2++)
			{
				int j1 = s - i1, j2 = s - i2;
				if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) 
				{
					int t = f[s-1][i1][i2];
					t = max(t, f[s-1][i1-1][i2-1]);
					t = max(t, f[s-1][i1-1][i2]);
					t = max(t, f[s-1][i1][i2-1]);
					if(i1 == i2) 
					{
						f[s][i1][i2] = t + a[i1][j1];
					}
					else 
					{
						f[s][i1][i2] = t + a[i1][j1] + a[i2][j2];
					}
				}
			
			}
		}
	}
	
	cout << f[n*2][n][n];
	return 0;
} 

//自己写的 
//#include<iostream>
//
//using namespace std;
//
//const int N = 10;
//
//int a[N][N];
//int f[N][N];
//bool st[N][N];
//int n,ret;
//
//int my_max(int x,int y,int i,int j)
//{
//	int num1 = f[x][y], num2 = f[i][j];
//	if(num1 > num2)
//	{
//		st[x][y] = true;
//		return num1;
//	}
//	else
//	{
//		st[i][j] = true;
//		return num2;
//	}
//}
//
//int main()
//{
//	cin >> n;
//	
//	for(int i=1;i<=n;i++)
//	{
//		int x,y,v; cin >> x >> y >> v;
//		a[x][y] = v;
//	}
//	
//	cout << "a数组" << endl; 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			f[i][j] = my_max(i-1,j,i,j-1) + a[i][j];
//		}
//	}
//	ret += f[n][n];
//	
//	cout << "f数组" << endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	cout << "st数组" << endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout << st[i][j] << " ";
//		}
//		cout << endl;
//	}
//	
//	//把标记过的地方清零 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(st[i][j]) a[i][j] = 0;
//		}
//	}
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			f[i][j] = my_max(i-1,j,i,j-1) + a[i][j];
//		}
//	}
//	ret += f[n][n];
//	
//	cout << ret;
//	return 0;
//}
