#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e4 + 10;

int in[N];
vector<int> edge[N];
int len[N],f[N];
int n; 

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) 
	{
		int x,y;
		cin >> y >> len[y];
		while(cin >> x, x)
		{
			edge[x].push_back(y);
			in[y]++;
		}
	}
	
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 0) q.push(i);
	}
	
	int ret = 0;
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		f[t] += len[t];
		ret = max(ret,f[t]);
		
		for(auto p:edge[t])
		{
			in[p]--;
			f[p] = max(f[p], f[t]);
			if(in[p] == 0) q.push(p);
		}
	}
	
	cout << ret << endl;
	
	return 0;
 } 
