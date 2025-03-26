#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e3 + 10;
//int a[N][N]; //不需要原数组，直接根据定义初始化差分数组 
LL f[N][N]; //差分数组 
int n,m,q;

int main()
{
	cin >> n >> m >> q;	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//直接利用定义初始化差分数组 
			int x; cin >> x;
			f[i][j] += x;
			f[i][j+1] -= x;
			f[i+1][j] -= x;
			f[i+1][j+1] += x;
		}
	} 
	while(q--)
	{
		int x1,y1,x2,y2,k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;	
		f[x1][y1] += k;
		f[x1][y2+1] -= k;
		f[x2+1][y1] -= k;
		f[x2+1][y2+1] += k;
	} 
	//还原数组 对差分数组求前缀和 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//还原出每一个位置的元素，那么就要用到前缀和的初始化公式 
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j]; 
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
