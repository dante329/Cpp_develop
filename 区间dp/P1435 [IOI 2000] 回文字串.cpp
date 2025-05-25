#include <iostream>

using namespace std;
 
const int N = 1010;
int f[N][N];
 
int main() 
{
	string s; cin >> s;
	int n = s.size();
	
	s = " " + s;
	
	for(int len=1;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++) //j=len+i-1，j是大于等于i的，以j为边界 
		{
			int j = len + i - 1;
			
			if(s[i] == s[j]) f[i][j] = f[i+1][j-1];
			else f[i][j] = min(f[i+1][j],f[i][j-1]) + 1;
		}
	}
	
	cout << f[1][n] << endl;
	
	return 0;
}
