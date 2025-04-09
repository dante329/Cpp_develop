#include<iostream>
#include<vector>
using namespace std;
vector<int> path;
bool st[15];
int n;

void dfs()
{
	if(path.size() == n)
	{
		for(int x:path) printf("%5d",x);
		puts(" ");
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(st[i]) continue;
		path.push_back(i);
		st[i] = true;
		dfs();
		path.pop_back();
		st[i] = false; 
	}
}

int main()
{
	cin >> n;
	dfs(); 
	
	return 0;
}
