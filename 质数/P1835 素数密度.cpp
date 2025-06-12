#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL; 

const int N = 1e6 + 10;

int l,r;

//��[2,sqrt(r)]�ڵ����� 
bool st[N]; 
int p[N],cnt;

//��¼[l,r]�ڵĺ������� 
bool ret[N];

//��[2,sqrt(r)]�ڵ����������԰���ɸ��Ҳ��������ɸ 
void get_prime()
{
	int n = sqrt(r);
	for(LL i=2;i<=n;i++)
	{
		if(!st[i])
		{
			p[++cnt] = i;
			for(LL j=i*i;j<=n;j+=i)
			{
				st[j] = true;
			}
		}
	}
}

int main()
{
	cin >> l >> r;
	
	l = l == 1 ? 2 : l; 
	
	get_prime();
	
	//ɸ[l,r]�ڵ�������ֻ�ܰ���ɸ����Ϊ����Ҫ��������ɸ 
	for(LL i=1;i<=cnt;i++)
	{
		int x = p[i];
		for(LL j=max(2*x,(x+l-1)/x*x);j<=r;j+=x) //��СҪȡi*x�Ǳ�����Լ�ɸ�� 
		{
			ret[j-l+1] = true;
		}
	} 
	
	int sum = 0;
	for(int i=l;i<=r;i++)
	{
		if(!ret[i-l+1]) sum++;
	}
	cout << sum;
	
	return 0;
} 
