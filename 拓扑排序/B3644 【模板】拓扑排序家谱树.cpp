#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

const int N = 110;

vector<int> edge[N];

int in[N];
int n;

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int j; 
		while(cin >> j, j)
		{		
			edge[i].push_back(j);
			in[j]++;
		}
	}
	
	queue<int> q;
	
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 0) q.push(i);
	}
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		cout << t << " ";
			
		for(auto p:edge[t])
		{
			in[p]--;
			if(in[p] == 0) q.push(p);	
		}
	}
	
	return 0;
}
