#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5010, M = 2e5 + 10, INF = 0x3f3f3f3f;

struct node
{
	int x,y,z; //x����y��ı�ȨֵΪz 
}a[M]; //a�������Ǳߵ���Ϣ�����鷶ΧҪ���ķ��ϱߵ����� 

int fa[N];
int n,m;

bool cmp(node& n1, node& n2)
{
	return n1.z < n2.z;
} 

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int kruskal()
{
	sort(a + 1, a + 1 + m, cmp); //��Ȩֵ��С�����������б�
	
	int ret = 0, cnt = 0; //ret���س���֮�ͣ�cnt��¼���������ж������� 
	
	for(int i=1;i<=m;i++) //����m������Ϣ�����ܴ����ر� 
	{
		int x = a[i].x, y = a[i].y, z = a[i].z; 
		
		int fx = find(x), fy = find(y);
		if(fx != fy)
		{
			ret += z;
			cnt++; //����������+1 
			fa[fx] = fy; //���x���y����ͨ��ͨ�����鼯ʵ�� 
		}
	}
	
	//�ж������������������n-1��ô������ȷ�������� 
	return cnt == n-1 ? ret : INF;
}
 
int main()
{
	cin >> n >> m;
	
	//��ʼ��fa����
	for(int i=1;i<=n;i++) fa[i] = i; 
	//�Ƿ�Ҫ�����ر��أ� ���ر������������ֲ���ͼ�������ҵ�һ�����ǰѱߴ�С����������Զ����ȡ��С�ı� 
	for(int i=1;i<=m;i++) cin >> a[i].x >> a[i].y >> a[i].z; 
	
	int ret = kruskal();
	
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	
	return 0;
} 
