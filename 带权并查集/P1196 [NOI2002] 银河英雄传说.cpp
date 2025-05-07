#include<iostream>

using namespace std;

const int N = 3e4 + 10;
int n = 3e4;
int fa[N]; //维护合并集合 
int d[N]; //维护权值 
int cnt[N]; //维护每个根节点上的元素长度 

int find(int x)
{
	if(fa[x] == x) return x;
	
	int t = find(fa[x]);
	
	d[x] += d[fa[x]]; //维护权值 
	
	return fa[x] = t; //压缩路径 
} 

void un(int x,int y)
{
	int fx = find(x), fy = find(y);
	
	if(fx != fy) //判断x和y不在一个集合才可以合并 
	{
		fa[fx] = fy;
	
		d[fx] = cnt[fy];
		cnt[fy] += cnt[fx];
	}
}

int query(int x,int y)
{
	int fx = find(x), fy = find(y);
	if(fx != fy) return -1;
	else return abs(d[y] - d[x]) - 1;
}

int main()
{
	int T; cin >> T;
	
	for(int i=1;i<=n;i++)
	{
		fa[i] = i;
		cnt[i] = 1;
	}
	
	while(T--)
	{
		char op; 
		int x,y;
		cin >> op >> x >> y;
		if(op == 'M')
		{
			un(x,y);			
		}
		else
		{
			cout << query(x,y) << endl;
		}
	}
	
	return 0;
 } 
