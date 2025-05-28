#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5010, M = 2e5 + 10, INF = 0x3f3f3f3f;

struct node
{
	int x,y,z; //x点与y点的边权值为z 
}a[M]; //a数组存的是边的信息，数组范围要开的符合边的数量 

int fa[N];
int n,m;

bool cmp(node& n1, node& n2)
{
	return n1.z < n2.z;
} 

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int kruskal()
{
	sort(a + 1, a + 1 + m, cmp); //按权值从小到大排序所有边
	
	int ret = 0, cnt = 0; //ret返回长度之和，cnt记录生成树中有多少条边 
	
	for(int i=1;i<=m;i++) //遍历m条边信息，可能存在重边 
	{
		int x = a[i].x, y = a[i].y, z = a[i].z; 
		
		int fx = find(x), fy = find(y);
		if(fx != fy)
		{
			ret += z;
			cnt++; //生成树边数+1 
			fa[fx] = fy; //标记x点和y点连通，通过并查集实现 
		}
	}
	
	//判断生成树边数如果等于n-1那么就是正确的生成树 
	return cnt == n-1 ? ret : INF;
}
 
int main()
{
	cin >> n >> m;
	
	//初始化fa数组
	for(int i=1;i<=n;i++) fa[i] = i; 
	//是否要考虑重边呢？ 有重边又怎样，我又不建图，而且我第一步就是把边从小到大排序，永远都是取最小的边 
	for(int i=1;i<=m;i++) cin >> a[i].x >> a[i].y >> a[i].z; 
	
	int ret = kruskal();
	
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	
	return 0;
} 
