#include<iostream>

using namespace std;

const int N = 3e4 + 10;
int n = 3e4;
int fa[N]; //ά���ϲ����� 
int d[N]; //ά��Ȩֵ 
int cnt[N]; //ά��ÿ�����ڵ��ϵ�Ԫ�س��� 

int find(int x)
{
	if(fa[x] == x) return x;
	
	int t = find(fa[x]);
	
	d[x] += d[fa[x]]; //ά��Ȩֵ 
	
	return fa[x] = t; //ѹ��·�� 
} 

void un(int x,int y)
{
	int fx = find(x), fy = find(y);
	
	if(fx != fy) //�ж�x��y����һ�����ϲſ��Ժϲ� 
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
