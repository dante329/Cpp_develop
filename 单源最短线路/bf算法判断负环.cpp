//bf�жϸ��� 
#include<iostream>
#include<cstring>

using namespace std;

const int N = 2010, M = 3010 * 2;

int pos;
struct node
{
	int x,y,z;
}e[M]; //����Ǳߣ���Ҫ���ձߵ����ݷ�Χ���� 

int dist[N];

int n,m;

bool bf()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	bool flag;
	for(int i=1;i<=n;i++) //bf�㷨������n-1���ɳڲ������ٶ�һ���жϸ��� 
	{	 
		flag = false;
		for(int i=1;i<=pos;i++) //ʵ����pos���� 
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
