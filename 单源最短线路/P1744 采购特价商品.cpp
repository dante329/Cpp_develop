#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

const int N = 110, M = 1010;

struct node
{
	int x,y;
	double z;
}e[M]; //不开双倍等下就要松弛两次 

double x[N],y[N];
double dist[N];
int n,m,s,t;

double calc(int i, int j)
{
	double fx = x[i] - x[j];
	double fy = y[i] - y[j];
	return sqrt(fx * fx + fy * fy);
}

void bf()
{
//	memset(dist,0x3f,sizeof dist);  memset(dist, 0x3f, sizeof dist) 对 double 类型不适用，0x3f 是 int 的初始化方式
	for(int i=1;i<=n;i++) dist[i] = 1e10; 
	
	dist[s] = 0;
	
	bool flag;
	
	for(int i=1;i<n;i++)
	{
		flag = false;
		for(int j=1;j<=m;j++)
		{
			int x = e[j].x, y = e[j].y;
			double z = e[j].z;
			if(dist[x] + z < dist[y]) 
			{
				dist[y] = dist[x] + z;
				flag = true;
			}
			if(dist[y] + z < dist[x]) 
			{
				dist[x] = dist[y] + z;
				flag = true;
			}
		}
		if(flag == false) break;
	}
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
	cin >> m;
	for(int i=1;i<=m;i++)
	{
		int a,b; cin >> a >> b;
		e[i].x = a, e[i].y = b, e[i].z = calc(a,b);
	}
	cin >> s >> t;
	
	bf();
	
	printf("%.2f\n",dist[t]);
	
	return 0;
}
