//自己想的方法，初始化了三角形的左右两条边来保证不越界，但实际上从下标为1开始存数据，本身就不会越界，对结果也没有影响，因为下标为0的存的都是0 
//#include<iostream>
//
//using namespace std;
//const int N = 1010;
//int a[N][N],n;
//int f[N][N]; //状态表示 
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	f[1][1] = a[1][1];
//	
//	for(int i=2;i<=n;i++) 
//	{
//		//初始化左边 
//		f[i][1] = f[i-1][1] + a[i][1];
//		//初始化右边 
//		f[i][i] = f[i-1][i-1] + a[i][i];
//	}
//	 
//	for(int i=3;i<=n;i++)
//	{
//		for(int j=2;j<=i-1;j++)
//		{
//			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
//		}
//	}
//	
//	if(n == 1)
//	{
//		cout << a[1][1] << endl;
//	}
//	else if(n == 2)
//	{
//		cout << max(a[2][1],a[2][2]) + a[1][1] << endl;
//	}
//	else
//	{
//		int ret = 0;
//		for(int i=1;i<=n;i++) ret = max(ret,f[n][i]);
//		cout << ret;
//	}
//	return 0; 
//}

//标答
#include<iostream>

using namespace std;
const int N = 1010;
int a[N][N],n;
int f[N][N]; //状态表示 

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin >> a[i][j];
		}
	}
	 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
		}
	}
	
	//空间优化，二维转一维，需要将f[N][N]改成f[N]。先考虑是否需要修改遍历顺序，再将f数组一维部分删掉即可 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			f[j] = max(f[j-1], f[j]) + a[i][j];
		}
	}

	int ret = 0;
	for(int i=1;i<=n;i++) ret = max(ret,f[n][i]);
	cout << ret;
	return 0; 
}
