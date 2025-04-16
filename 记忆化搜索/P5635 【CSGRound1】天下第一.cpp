#include<iostream>

using namespace std;
const int N = 1e4 + 10;
char f[N][N];
int x,y,p;

int dfs(int x,int y)
{
	if(f[x][y]) return f[x][y];
	//一进来就先标记为3，后面如果检测到重复状态就直接return了，这是值得学习的代码思维 
	f[x][y] = '3';
	if(x == 0) return f[x][y] = '1';
	if(y == 0) return f[x][y] = '2';
		
	return f[x][y] = dfs((x+y)%p,(x+y+y)%p);
}

int main()
{
	int T; cin >> T >> p;
	while(T--)
	{
		cin >> x >> y;	
		char ch = dfs(x,y);
		if(ch == '1') cout << 1 << endl;
		else if(ch == '2') cout << 2 << endl;
		else cout << "error" << endl;
	}	
	return 0;
}
