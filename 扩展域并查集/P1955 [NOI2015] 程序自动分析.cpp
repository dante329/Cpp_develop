//离散化 + 并查集 
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 1e5 + 10;
int n;
struct node
{
	int x,y,e;	
}a[N];
//离散化
int disc[N * 2]; //要对x，y离散化，所以要开两倍的大小 
int pos;
unordered_map<int,int> mp;
//并查集
int fa[N * 2];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x,int y)
{
	fa[find(x)] = find(y);
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

bool solve()
{
	//离散化 
	cin >> n;
	//清空数据 (清空pos和mp)
	pos = 0;
	mp.clear();
	for(int k=1;k<=n;k++)
	{
		cin >> a[k].x >> a[k].y >> a[k].e;
		disc[++pos] = a[k].x;
		disc[++pos] = a[k].y;
	}
	
	sort(disc + 1, disc + 1 + pos);
	
	int cnt = 0;
	for(int i=1;i<=pos;i++)
	{
		int t = disc[i];
		if(mp.count(t)) continue;
		
		cnt++;
		mp[t] = cnt;
	}
	//初始化并查集 
	for(int i=1;i<=cnt;i++) fa[i] = i;
	
	//先遍历数组，执行所有合并操作 
	for(int i=1;i<=n;i++)
	{
		int x = a[i].x, y = a[i].y, e = a[i].e;
		if(e == 1)
		{
			un(mp[x],mp[y]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x = a[i].x, y = a[i].y, e = a[i].e;
		if(e == 0)
		{
			if(issame(mp[x],mp[y])) return false;
		}
	}
	return true;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		if(solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
