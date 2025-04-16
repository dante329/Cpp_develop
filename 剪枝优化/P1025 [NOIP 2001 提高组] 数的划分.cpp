#include <iostream>
using namespace std; 

int n,k;
int path,ret;

void dfs(int pos,int begin) //pos起始位置，从0开始；begin从哪个数开始遍历，避免等效冗余 
{
	if(pos == k)
	{
		if(path == n) ret++;
		return; 
	}	
	
	for(int i=begin;i<=n;i++)
	{
		if(path + i*(k-pos) > n) return;
		path += i;
		dfs(pos+1,i);
		path -= i;
	}
}
int main() 
{
	cin >> n >> k;
	
	dfs(0,1);
	
	cout << ret << endl; 
	return 0;
}
