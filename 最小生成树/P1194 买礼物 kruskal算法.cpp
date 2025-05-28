#include<iostream>
#include<algorithm>

using namespace std;

const int N = 124750 + 10;

int n,v;  
int fa[N];

int pos; //�����洢node 
struct node
{
	int x,y,z;
}e[N];

int ret,cnt; //ret��kk()�������С���ѣ�cnt������ɭ�ֵ��ܱ��� 

bool cmp(node& a, node& b)
{
	return a.z < b.z;
}

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void kk()
{
	//��Ȩֵ��С�������� 
	sort(e + 1, e + 1 + pos, cmp);	
	
	for(int i=1;i<=pos;i++) //����ȡ������ı�
	{
		int x = e[i].x, y = e[i].y, z = e[i].z;
		int fx = find(x), fy = find(y);
		if(fx != fy) //��֤�˵㲻���� 
		{
			ret += z;
			cnt++;
			fa[fx] = fy;	
		}
	}
}

int main()
{	
	cin >> v >> n;

	for(int i=1;i<=n;i++) fa[i] = i;
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x; cin >> x;
			if(i >= j || x == 0 || x > v) continue;
			pos++;
			e[pos].x = i, e[pos].y = j, e[pos].z = x;
		}
	}
	
	kk();
	
	cout << ret + (n - cnt) * v; 
	return 0;
}

