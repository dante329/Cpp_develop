#include<iostream>
using namespace std;
const int N = 5010;
int f[N][N]; //f[i][j]表示a字符串的1~i、b字符串的1~j当中最长子序列的长度 
string a,b;

int main()
{
	while(cin >> a >> b)
	{
		int len1 = a.size(), len2 = b.size();
		a = " " + a, b = " " + b;
		
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i-1][j], f[i][j-1]); //在二维数组图中：f[i-1][j]在f[i][j]的上面，f[i][j-1]在f[i][j]的左边，这两个在遍历到f[i][j]之前都已经处理过了，是可以直接拿它们的值来用的 
			}
		}
			
		cout << f[len1][len2] << endl;
	}
		
	
	return 0;
 } 
