#include<iostream>
#include<algorithm>

using namespace std;

const int N = 310, M = 8010;

struct node
{
	int x,y,z;
}e[M];

int fa[N];
int n,m;
int ret; //最小生成树中的最大分值 

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool cmp(node& a, node& b)
{
	return a.z < b.z;
}

void kk()
{
	sort(e + 1, e + 1 + m, cmp);
		
	for(int i=1;i<=m;i++)
	{
		int x = e[i].x, y = e[i].y, z = e[i].z;
		
		int fx = find(x), fy = find(y);
		if(fx != fy)
		{
			ret = max(ret,z);
			fa[fx] = fy;
		}
	}
}

int main()
{	
	cin >> n >> m;
	
	for(int i=1;i<=m;i++) cin >> e[i].x >> e[i].y >> e[i].z;
	
	for(int i=1;i<=n;i++) fa[i] = i;
	
	cout << n-1 << " "; 
	
	kk();
	
	cout << ret << endl;
	
	return 0;
} 
