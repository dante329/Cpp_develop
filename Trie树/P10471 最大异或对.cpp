#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N],n;
int tr[N * 32][2],idx;

void insert(int x)
{
	int cur = 0;
	
	for(int i=31;i>=0;i--)
	{
		int path = (x >> i) & 1;
		if(tr[cur][path] == 0) tr[cur][path] = ++idx;
		cur = tr[cur][path];	
	} 
}

int find(int x)
{
	int cur = 0;
	int ret = 0;
	for(int i=31;i>=0;i--)
	{
		int path = (x >> i) & 1;
		if(tr[cur][path ^ 1] == 0) //[path ^ 1]��ʾ���෴��·�����û��·���˶������
		{
			cur = tr[cur][path]; //��ԭ����· 
		} 
		else //[path ^ 1]��· 
		{
			ret |= (1 << i); //��Ϊ�����������011111111������ߵ�ͨ���Ƿ����������ÿһλ�϶���1����Ӧλ�����һ��1���ɣ�����߲�ͨ�Ͳ�������ret�����ʼ���ľ���0 
			cur = tr[cur][path ^ 1];
		}	
	} 
	return ret;	
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i]; 
		insert(a[i]);
	}
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		ret = max(ret,find(a[i]));
	}
	cout << ret << endl;
	 
	return 0;
}
