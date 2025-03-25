#include<iostream>
using namespace std;
typedef long long LL;

const int N = 1e3 + 10;
LL f[N][N];

int n,m,q;

int main()
{
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x; cin >> x; 
			//二维前缀和递推公式 
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + x;	
		}
	}
	
	int x1,x2,y1,y2;
	while(q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		LL ret = f[x2][y2] - f[x1-1][y2] - f[x2][y1-1] + f[x1-1][y1-1];
		cout << ret << endl; 
	}
	
	return 0;
}
