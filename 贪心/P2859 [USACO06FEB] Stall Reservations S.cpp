#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 5e4 + 10;
struct node
{
	int x; //��ţ��ʼʱ�� / ��������ʱ�� 
	int y; //��ţ����ʱ�� / ������� 
	int z; //��ţ��� 
	
	bool operator<(const node& other) const
	{
		return x > other.x; //���ں���С���� 
	}
}a[N];
int n;

bool cmp(node& n1,node& n2)
{
	return n1.x < n2.x;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].z = i;
	}
	sort(a+1,a+n+1,cmp);
	priority_queue<node> pq;
	int ret[N]; //���ڻ�Ҫ��ӡ�ڼ�����ţȥ����һ������������Ҫһ����������¼ 
	//�Ȱѵ�һ����ţ�Ž�ȥ���ӵڶ�����ʼ��
	int cnt = 1; //���ܼ�¼��Ҫ���ٲ��������ܱ��Ŀǰ���Ĳ����� 
	pq.push({a[1].y,1}); 
	ret[a[1].z] = 1; 
	for(int i=2;i<=n;i++)
	{
		int begin = a[i].x, end = a[i].y;
		node t = pq.top(); //��Ŀǰ��������ʱ����С���Ǹ��ó����Ƚ� 
		if(begin > t.x) //��С���Ǹ��Ѿ������� 
		{
			pq.pop(); //��ԭ������ţŪ�� 
			pq.push({end,t.y}); //�����µ���ţ�������Ż���ԭ���� 
			ret[a[i].z] = t.y; //��ret�м�¼�ڼ�ͷ��ţȥ�˵ڼ��Ų��� 
		}
		else //��Ҫ�¿�����
		{
			cnt++;
			pq.push({end,cnt});
			ret[a[i].z] = cnt;  
		} 
	}
	cout << cnt << endl;
	for(int i=1;i<=n;i++) cout << ret[i] << endl;
	return 0;
}
