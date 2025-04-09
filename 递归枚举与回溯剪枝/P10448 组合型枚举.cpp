#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> path;
void dfs(int pos,int begin)
{
	if(pos > m) 
	{
		for(auto x:path) cout << x << " ";
		cout << endl; 
		return;
	}
	for(int i=begin;i<=n;i++)
	{ 
		path.push_back(i);
		dfs(pos+1,i+1);
		path.pop_back(); 
	}
}
int main()
{
	cin >> n >> m;
	dfs(1,1);	
	return 0;
 } 
