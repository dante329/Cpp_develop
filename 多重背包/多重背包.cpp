//���ر���ģ�� 
#include <iostream>

using namespace std;

const int N = 110;

int x[N],w[N],v[N],f[N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> x[i] >> w[i] >> v[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=0;k<=x[i] && k*w[i]<=j;k++)
			{
				f[j] = max(f[j],f[j-k*w[i]]+k*v[i]);
			}
		}
	}
	
	cout << f[m];
	
	return 0;
}

//�������Ż�
#include <iostream>

using namespace std;

const int N = 110 * 5; //pos�����������ԭ����Ʒ������5�� 

int w[N],v[N],pos; //pos������¼��ֺ����Ʒ������ 
int f[N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) 
	{
		int x,y,z; cin >> x >> y >> z;
		
		int t = 1;
		
		while(x >= t)
		{
			pos++;
			w[pos] = t * y;
			v[pos] = t * z;
			x -= t;
			t *= 2;  
		}
		if(x)
		{
			pos++;
			w[pos] = x * y;
			v[pos] = x * z;
		}	
	}
	
	//��Բ��֮�����Ʒ��һ��01���� 
	for(int i=1;i<=pos;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			f[j] = max(f[j],f[j-w[i]] + v[i]);
		}
	}
	
	cout << f[m];
	
	return 0;
} 
