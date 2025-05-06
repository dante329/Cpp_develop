#include<iostream>

using namespace std;

const int N = 5010;

int fa[N];
int n,m,p;

int find(int x)
{
	return fa[x] == x ? x : find(fa[x]);
}

int main()
{
	cin >> n >> m >> p;
	for(int i=1;i<=n;i++) fa[i] = i;
	for(int i=1;i<=m;i++)
	{
		int x,y; cin >> x >> y;
		int fx = find(x), fy = find(y);
		fa[fx] = fy;
	}
	
	for(int i=1;i<=p;i++)
	{
		int x,y; cin >> x >> y;
		if(find(x) == find(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
		
	}
	
 	return 0;
}
