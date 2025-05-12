#include<iostream>

using namespace std;
typedef long long LL;
const int N = 25;

LL a[N][N];
LL f[N][N];
int n,m,o,p;
int x[] = {-1,-2,-2,-1,1,2,2,1};
int y[] = {2,1,-1,-2,-2,-1,1,2};

int main() 
{
	cin >> n >> m >> o >> p;
	
	n++,m++,o++,p++;
	
	//在a数组中标记马的位置 
	a[o][p] = 1;
	for(int k=0; k<8; k++) 
	{
		int i = o + x[k], j = p + y[k];

		if(i>=1 && i<=n && j>=1 && j<=m) a[i][j] = 1;
	}

	f[0][1] = 1;
	for(int i=1; i<=n; i++) 
	{
		for(int j=1; j<=m; j++) 
		{
			if(a[i][j] == 0) f[i][j] = f[i-1][j] + f[i][j-1];
		}
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
//
//	cout << endl;
//
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//
	cout << f[n][m];
	return 0;
}

//题解使用曼哈顿距离为3来判断是否在马的攻击范围内
bool check(int i,int j)
{
	return (i == o && j == p) || (abs(i-o) + abs(j-p) == 3 && i != o && j != p);
 } 

int main() 
{
	cin >> n >> m >> o >> p;

	n++,m++,o++,p++;

	f[0][1] = 1;
	for(int i=1; i<=n; i++)  
	{
		for(int j=1; j<=m; j++) 
		{
			if(!check(i,j)) f[i][j] = f[i-1][j] + f[i][j-1];
		}
	}

	cout << f[n][m];
	
	return 0;
}
