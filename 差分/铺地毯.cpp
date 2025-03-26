#include<iostream>
using namespace std;
const int N = 1010;
int f[N][N];
int n,m;

void insert(int x1,int y1,int x2,int y2,int k)
{
	f[x1][y1] += k;
	f[x1][y2+1] -= k;
	f[x2+1][y1] -= k;
	f[x2+1][y2+1] += k;
}
int main()
{
	cin >> n >> m;	
	while(m--)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		insert(x1,y1,x2,y2,1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//当你计算 f[i][j] 的前缀和时，你实际上是在 逐步累加差分值，最终得到 a[i][j]（即当前点的实际值）。
			f[i][j] = f[i][j-1] + f[i-1][j] - f[i-1][j-1] + f[i][j];		
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
