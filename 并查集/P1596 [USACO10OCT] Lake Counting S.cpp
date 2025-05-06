#include<iostream>
using namespace std;

const int N = 110;
char a[N][N];
//���鼯Ҫ���ǵ� n * m 
int fa[N * N]; 
int n,m;
//��Ϊ�������鼯������Ҫ�����������飬������ģ���ֻ��Ҫ�������µ��ĸ��������� 
int dx[] = {1,1,1,0};
int dy[] = {-1,0,1,1};

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x,int y)
{
	fa[find(x)] = find(y);
}

int main()
{
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> a[i][j];
		}
	}
	
	//��ʼ�����鼯
	for(int i=0;i<n*m;i++) fa[i] = i;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == '.') continue;
			
			for(int k=0;k<4;k++)
			{
				int x = i + dx[k], y = j + dy[k];
				if(y >= 0 && a[x][y] == 'W')
				{
					un(i*m+j,x*m+y); //��ά����תһά 
				}
			}
		}
	}
	
	int ret = 0;
	for(int i=0;i<n*m;i++)
	{
		//һάת��ά 
		int x = i / m, y = i % m;
		if(a[x][y] == 'W' && fa[i] == i) ret++;
	}
	cout << ret;
	return 0;
 } 
