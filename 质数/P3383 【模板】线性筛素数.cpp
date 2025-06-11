#include<iostream>

using namespace std;

typedef long long LL; 

const int N = 1e8 + 10;

int n,q;
bool st[N];
int p[N],cnt;

//����ɸ
void get_prime1()
{
	for(LL i=2;i<=n;i++) //��LL 
	{
		if(!st[i]) //������ 
		{
			p[++cnt] = i;
			for(LL j=i*i;j<=n;j+=i) //��LL С�Ż�����i*i��ʼ���� 
			{
				st[j] = true;
			}
		}
	}
}

//����ɸ 
void get_prime2()
{
	for(LL i=2;i<=n;i++) //LL�Ƿ�ֹ i * p[j]��ʱ����� 
	{
		if(!st[i]) p[++cnt] = i; //û�б�Ǿ����������������������� 
		
		for(in t j=1;i * p[j] <= n;j++) //j��p������±꣬����ɸȥi�������� 
		{
			st[i * p[j]] = true; //�������ϱ�ǣ�ɸ�� 
			if(i % p[j] == 0) break; //���i�Ǹ������ı�����ֹͣ 
		}
	}
}

int main()
{
	scanf("%d%d",&n,&q);
	get_prime1();
	
	while(q--)
	{
		int k; cin >> k;
		printf("%d\n",p[k]);
	}
	return 0;
} 
