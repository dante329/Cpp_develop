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

vector<PII> edge[N]; //��ͼ������dfs 

int pos;
struct node
{
	int x,y,z; //�ṹ��������ÿ���㵽��һ�������Ϣ 
}e[M]; //����kruskal�㷨 

LL cnt; //ͳ������ܵ�����ٸ�����
LL ret; //��ʱ��̵Ļ��о����ܺ� 

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

void dfs(int u)
{
	cnt++;
	st[u] = true;
	for(auto& p:edge[u]) //����u���Ե���ĵط� 
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
	
	for(int i=1;i<=pos;i++) //ѭ����pos���ɣ�����Ҫѭ����m 
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
	
	//��ͼ 
	for(int i=1;i<=m;i++)
	{
		int x,y,z; cin >> x >> y >> z;
		//������ǴӸ߸ߵ� 
		if(h[x] >= h[y]) edge[x].push_back({y,z});
		if(h[y] >= h[x]) edge[y].push_back({x,z});
	}
	
	dfs(1); //dfs������ܵ�����ٸ����㣬���Ҽ�¼�����ͨͼ��ÿ���ߵ���Ϣ�� 
	
	cout << cnt << " "; 
	
	kk();
	
	cout << ret << endl;
	
	return 0;
 } 
