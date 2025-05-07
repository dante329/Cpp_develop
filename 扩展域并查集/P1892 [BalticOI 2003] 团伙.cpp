#include <iostream>
using namespace std;
const int N = 1010;
int fa[N * 2]; //��չ�򲢲鼯�����������ݷ�Χ����������˹�ϵ 
int n,m;

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x,int y)
{
	fa[find(y)] = find(x); //һ��Ҫ��������1~n�������ڵ� 
}

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n*2;i++) fa[i] = i; //��ʼ�� 
	
	while(m--)
	{
		char opt;
		int p,q;
		cin >> opt >> p >> q;
		if(opt == 'F')
		{
			un(p,q);
		}
		else
		{
			un(p,q+n);
			un(q,p+n);
		}
	}
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		if(fa[i] == i) ret++;
	}
	cout << ret;
	return 0;
}
