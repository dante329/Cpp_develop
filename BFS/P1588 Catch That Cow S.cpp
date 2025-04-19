#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int dist[N];
int n = 1e5;
int x,y;

void bfs()
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while(q.size())
	{
		int t = q.front(); q.pop();
		//枚举三种情况，分支进行bfs
		int a = t + 1, b = t - 1, c = t * 2;
		
		if(a <= n && dist[a] == -1)
		{
			dist[a] = dist[t] + 1;
			q.push(a); 
		} 
		if(b >= 1 && dist[b] == -1)
		{
			dist[b] = dist[t] + 1;
			q.push(b); 
		}
		if(c <= n && dist[c] == -1)
		{
			dist[c] = dist[t] + 1;
			q.push(c); 
		}
			
		if(a == y || b == y || c == y) return;
	} 
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		memset(dist,-1,sizeof dist);
		cin >> x >> y;
		bfs();
		cout << dist[y] << endl;
	}
	
	
	return 0;
 } 
