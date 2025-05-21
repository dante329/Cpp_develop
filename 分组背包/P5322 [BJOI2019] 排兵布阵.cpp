#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110, M = 2e4 + 10;

int a[N][N]; //a[i][j]:1~i���Ǳ���1~j����ң�(i,j)��ʾi�����j�Ǳ��ı��� 
int f[N][M]; //f[i][j]:��1~i���Ǳ��У�ѡ���ܱ���������j�ķ�����ʹ���ܵ÷���� 
int s,n,m;

int main()
{
	cin >> s >> n >> m;
	
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> a[j][i];
			a[j][i] = a[j][i] * 2 + 1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+1+s);
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = f[i-1][j];
			for(int k=1;k<=s && a[i][k]<=j;k++)
			{
				f[i][j] = max(f[i][j],f[i-1][j-a[i][k]] + i*k);
			}
		}
	}
	
	cout << f[n][m];
	
	return 0;
} 
