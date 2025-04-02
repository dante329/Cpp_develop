#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 5e4 + 10;
struct node
{
	LL w,s;	
}a[N];
int n;

//�ص���⣺��C++��sort�����У����cmp(a, b)����true����a������bǰ�档��ˣ����ȽϺ������ص���������ʱ��n1Ӧ������n2ǰ�档���������Ӧ���ǣ���n1����n2ǰ��ʱ�����ߵ����ѹ��ָ����С��
bool cmp(node n1,node n2)
{
	return  max(n1.w - n2.s, -n1.s) < max(n2.w - n1.s, -n2.s);
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].w >> a[i].s;
	sort(a+1,a+n+1,cmp);
	LL sum = 0, ret = -1e9 - 10;
	for(int i=1;i<=n;i++)
	{		
		ret = max(ret,sum - a[i].s);
		sum += a[i].w;
	}
	cout << ret;
	return 0;
}
