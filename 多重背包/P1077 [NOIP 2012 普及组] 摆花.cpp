#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N][N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j++) //��������Ҳ����������Ϊ�ò�����ǰ�еĸ��� 
		{
			for(int k=0;k<=a[i] && k<=j;k++) //k��0��ʼ�����������˲�ѡ��ѡk��������� 
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	//��������ѡ����ֹ�ռ��Ż����� 
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			//��ѡ 
			f[i][j] = f[i-1][j];
			//ѡ1~k�� 
			for(int k=1;k<=a[i] && k<=j;k++)
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	cout << f[n][m];
	return 0;
}

//�ռ��Ż�
#include<iostream> 

using namespace std;

const int N = 110, MOD = 1e6 + 7;

int f[N][N],a[N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;

	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=1;k<=a[i] && k<=j;k++)
			{
				f[i][j] = (f[i][j] + f[i-1][j-k]) % MOD;
			}
		}
	}
	
	cout << f[n][m];
	return 0;
} 
