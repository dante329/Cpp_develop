#include<iostream>
using namespace std;
const int N = 10; 
int a[N][N];
bool col[N][N],row[N][N],st[N][N][N]; //0-based就是为了方便区间的映射
int n=9;

bool dfs(int i,int j)
{
	if(i == n) return true;
	if(j == n) return dfs(i+1,0);
	
	//如果写成下面这样，就必须先检查j再检查i，因为检查j的时候有可能会改变i使得i不合法
//	if(j == n) 
//	{
//	    i++;
//		j = 0;
//	}
//	if(i == n) return true;
	

	if(a[i][j]) return dfs(i,j+1); //这里一定要加treturn，如果i、j已经有元素了就要返回下一个位置的dfs，并且当前位置一定要结束，不然到最后还是返回到当前dfs中 
	
	for(int x=1;x<=n;x++)
	{
		if(row[i][x] || col[j][x] || st[i/3][j/3][x]) continue;
		
		a[i][j] = x;
		row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
		
		if(dfs(i,j+1)) return true;
		
		row[i][x] = col[j][x] = st[i/3][j/3][x] = false;
		a[i][j] = 0;
	}
	return false;
}

int main()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
			int x = a[i][j];
			if(x) row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
		}
	}
	
	dfs(0,0);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
 } 
