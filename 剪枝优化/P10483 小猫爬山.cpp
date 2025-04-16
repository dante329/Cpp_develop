#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int n,w;
int a[N];
int sum[N]; //ÿһ����Ŀǰ�������� 
int cnt; //ͳ�Ƶ�ǰ���ѣ�Ҳ�ǳ��������� 
int ret = N; //���շ���ֵ�����Ž� 

bool cmp(int a,int b)
{
	return a > b;
}

void dfs(int pos)
{
	//���Զ��������Լ�֦ 
	if(cnt >= ret) return;

	if(pos > n) //�����ߵ�������cntһ����С��ret�� 
	{
		ret = cnt;
		return;
	}
	
	//������:�Ȱ��ŵ����еĳ����ϣ���������¾��ؿ��� 
	for(int i=1;i<=cnt;i++) 
	{
		//����һ���������Ż� 
		if(sum[i] + a[pos] > w) continue;
		
		sum[i] += a[pos];
		dfs(pos + 1);
		sum[i] -= a[pos];
	}
	
	cnt++;
	sum[cnt] = a[pos];
	dfs(pos + 1);
	sum[cnt] = 0;
	cnt--;
}


int main()
{
	cin >> n >> w;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//���������Ż�����˳�� 
	sort(a+1,a+n+1,cmp);
	
	dfs(1);	
	
	cout << ret << endl;
	return 0;
}
