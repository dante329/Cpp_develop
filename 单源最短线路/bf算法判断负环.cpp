//bf判断负环 
#include<iostream>
#include<cstring>

using namespace std;

const int N = 2010, M = 3010 * 2;

int pos;
struct node
{
	int x,y,z;
}e[M]; //存的是边，就要按照边的数据范围开辟 

int dist[N];

int n,m;

bool bf()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	bool flag;
	for(int i=1;i<=n;i++) //bf算法最多进行n-1次松弛操作，再多一次判断负环 
	{	 
		flag = false;
		for(int i=1;i<=pos;i++) //实际有pos条边 
		{
			int x = e[i].x, y = e[i].y, z = e[i].z;
			
			if(dist[x] == 0x3f3f3f3f) continue;
			
			if(dist[x] + z < dist[y])
			{
				dist[y] = dist[x] + z;
				flag = true;
			} 
		}	
		
		if(flag == false) return flag;		
	}
	
	return flag;

}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		pos = 0;
		cin >> n >> m;
		for(int i=1;i<=m;i++)
		{
			int u,v,w; cin >> u >> v >> w;
			pos++;
			e[pos].x = u, e[pos].y = v, e[pos].z = w;
			if(w >= 0)
			{
				pos++;
				e[pos].x = v, e[pos].y = u, e[pos].z = w;
			}
		}
		if(bf()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}
