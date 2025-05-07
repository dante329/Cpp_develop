//��ɢ�� + ���鼯 
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 1e5 + 10;
int n;
struct node
{
	int x,y,e;	
}a[N];
//��ɢ��
int disc[N * 2]; //Ҫ��x��y��ɢ��������Ҫ�������Ĵ�С 
int pos;
unordered_map<int,int> mp;
//���鼯
int fa[N * 2];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void un(int x,int y)
{
	fa[find(x)] = find(y);
}

bool issame(int x, int y)
{
	return find(x) == find(y);
}

bool solve()
{
	//��ɢ�� 
	cin >> n;
	//������� (���pos��mp)
	pos = 0;
	mp.clear();
	for(int k=1;k<=n;k++)
	{
		cin >> a[k].x >> a[k].y >> a[k].e;
		disc[++pos] = a[k].x;
		disc[++pos] = a[k].y;
	}
	
	sort(disc + 1, disc + 1 + pos);
	
	int cnt = 0;
	for(int i=1;i<=pos;i++)
	{
		int t = disc[i];
		if(mp.count(t)) continue;
		
		cnt++;
		mp[t] = cnt;
	}
	//��ʼ�����鼯 
	for(int i=1;i<=cnt;i++) fa[i] = i;
	
	//�ȱ������飬ִ�����кϲ����� 
	for(int i=1;i<=n;i++)
	{
		int x = a[i].x, y = a[i].y, e = a[i].e;
		if(e == 1)
		{
			un(mp[x],mp[y]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x = a[i].x, y = a[i].y, e = a[i].e;
		if(e == 0)
		{
			if(issame(mp[x],mp[y])) return false;
		}
	}
	return true;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		if(solve()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
