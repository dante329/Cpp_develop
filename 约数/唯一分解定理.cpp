#include<iostream> 

using namespace std;

const int N = 1000;

int n,c[N]; //c[N]�����ڼ�¼ÿ�������ӳ��ֵĴ��� 

int main()
{
	cin >> n;
	int x = n;
	for(int i=2;i<=n/i;i++)
	{
		int cnt = 0;
		while(n % i == 0) 
		{
			n /= i;
			cnt++;
		}
		c[i] += cnt;
	} 
	if(n > 1) c[n]++;
	
	//�������������ָ��
	for(int i=2;i<=x;i++)
	{
		if(c[i]) printf("%d^%d ",i,c[i]); 
	} 
	
	return 0;
}
