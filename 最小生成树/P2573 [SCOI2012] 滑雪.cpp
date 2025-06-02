#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e5 + 10, M = 2e6 + 10;

int fa[N];
int h[N];
int n,m;
bool st[N];

vector<PII> edge[N]; //存图，用来dfs 

int pos;
struct node
{
	int x,y,z; //结构体用来存每个点到下一个点的信息 
}e[M]; //计算kruskal算法 

LL cnt; //统计最多能到达多少个景点
LL ret; //此时最短的滑行距离总和 

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

void dfs(int u)
{
	cnt++;
	st[u] = true;
	for(auto& p:edge[u]) //遍历u可以到达的地方 
	{
		int y = p.first, z = p.second; 
		pos++;
		e[pos].x = u, e[pos].y = y, e[pos].z = z;
		if(!st[y]) dfs(y); 
	}
}

bool cmp(node& a, node& b)
{
	int y1 = a.y, z1 = a.z, y2 = b.y, z2 = b.z;
	if(h[y1] != h[y2]) return h[y1] > h[y2];
	else return z1 < z2; 
}

void kk()
{
	for(int i=1;i<=n;i++) fa[i] = i;
	
	sort(e + 1,e + 1 + pos, cmp);
	
	for(int i=1;i<=pos;i++) //循环到pos即可，不需要循环到m 
	{
		int x = e[i].x, y = e[i].y, z = e[i].z;
		int fx = find(x), fy = find(y);
		if(fx != fy)
		{
			ret += z;
			fa[fx] = fy;
		}		
	}
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> h[i];
	
	//存图 
	for(int i=1;i<=m;i++)
	{
		int x,y,z; cin >> x >> y >> z;
		//方向就是从高高低 
		if(h[x] >= h[y]) edge[x].push_back({y,z});
		if(h[y] >= h[x]) edge[y].push_back({x,z});
	}
	
	dfs(1); //dfs出最多能到达多少个景点，并且记录这个连通图的每条边的信息。 
	
	cout << cnt << " "; 
	
	kk();
	
	cout << ret << endl;
	
	return 0;
 } 
