#include<iostream> 
using namespace std;
const int N = 2010;
int f[N][N]; //f[i][j]表示：将a字符串的[1,i]字串变成b字符串的[1,j]字串需要的最小操作次数 
string a,b;

int main()
{
	cin >> a >> b;
	
	int n = a.size(), m = b.size();
	
	a = " " + a, b = " " + b;
	
	//这道题的初始化是相当重要的，i为0时代表a是空串，j为0时代表b是空串，研究转换关系可知如何初始化 
	for(int i=1;i<=n;i++) f[i][0] = i;	
	for(int i=1;i<=m;i++) f[0][i] = i;
	
	//状态转移方程 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i] == b[j]) f[i][j] = f[i-1][j-1];
			else  
			{
				//三种操作删除、替换、插入分别是f[i-1][j]和f[i-1][j-1]和f[i][j-1]
				//分析某个状态，当对应字符不同时，操作次数的变化只有可能来自这三种操作，求他们的最小值 
				int t = f[i-1][j];
				t = min(t, f[i-1][j-1]);
				t = min(t, f[i][j-1]);
				f[i][j] = t + 1;
			}
		}
	}
	
	cout << f[n][m];
	return 0; 
}
