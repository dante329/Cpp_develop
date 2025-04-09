#include<iostream>
#include<vector>
using namespace std;
vector<int> path;
bool st[15];
int n,k;

void dfs()
{
	if(path.size() == k)
	{
		for(auto x:path) cout << x << " ";
		cout << endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(st[i]) continue; 
		path.push_back(i);
		st[i] = true;
		dfs();
		path.pop_back(); //»Ö¸´ÏÖ³¡ 
		st[i] = false;
	}
}

int main()
{
	cin >> n >> k;
	dfs();	
	return 0;
}
