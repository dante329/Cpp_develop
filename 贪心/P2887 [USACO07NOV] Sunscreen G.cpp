#include<iostream> 
#include<algorithm>
using namespace std;
const int N = 3000;
struct node
{
	int x; //��Сֵ  / ά��ֵ 
	int y; //���ֵ / ���� 
}a[N],b[N];
int n,m;

bool cmp(node& n1,node& n2)
{
	return n1.x > n2.x;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i].x >> a[i].y;
	for(int i=1;i<=m;i++) cin >> b[i].x >> b[i].y;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp); 
	int ret = 0;
	for(int i=1;i<=n;i++) //ѭ��ţ 
	{	
		int left = a[i].x,right = a[i].y;
		for(int j=1;j<=m;j++) //ѭ����ɹ˪ 
		{
			int w = b[j].x, &cnt = b[j].y;
			if(w > right) continue; //��ǰ�ķ�ɹ˪���ˣ�ȥ����һ����ɹ˪ 
			if(w < left) break; //���ķ�ɹ˪�����㲻����ͷţ��ֱ��ȥ����һͷţ 
			if(cnt == 0) continue;
			cnt--;	
			ret++;
			break; //�ߵ����˾����ҵ����ʵķ�ɹ˪�˾Ͳ�Ҫ���������� 
		}
	}
	cout << ret << endl;
	return 0;
}
