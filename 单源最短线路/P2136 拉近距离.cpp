#include<iostream>
#include<cstring>

using namespace std;

const int N = 1010, M = 10010, INF = 0x3f3f3f3f;

struct node
{
	int x,y,z;
}e[M * 2];

int dist[N];
int n,m;

bool bf(int s)
{
	memset(dist,0x3f,sizeof dist);
	dist[s] = 0;
	
	bool flag;
	for(int i=1;i<=n;i++)
	{
		flag = false;
		for(int j=1;j<=m;j++)
		{
			int x = e[j].x, y = e[j].y, z = e[j].z;
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
	cin >> n >> m;
	
	for(int i=1;i<=m;i++)
	{
		int x,y,z; cin >> x >> y >> z;
		e[i].x = x, e[i].y = y, e[i].z = -z;
	}

//ֻ��1����ȥ���յ�n�Ǵ�� 
//	if(bf(1)) cout << "Forever love";
//	else cout << dist[n];
	
//��Ҫ����1��n��ҲҪ������nΪ���ȥ��1	
	int ret;
	
	if(bf(1)) 
	{
		cout << "Forever love";
		return 0;
	}
	else ret = dist[n];
	
	if(bf(n))
	{
		cout << "Forever love";
		return 0;
	}
	else ret = min(ret,dist[1]);
	
	cout << ret;
	
	return 0;
 } 
