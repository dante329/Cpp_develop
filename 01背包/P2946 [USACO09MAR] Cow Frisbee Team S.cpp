//���⣬��Ȼ��ȡģ�������һ�㣬�����Ҿ����ڳ�ʼ���߼��ϸ�ʤһ��������߼��� 
#include<iostream>

using namespace std;

const int N = 2010, M = 1010, MOD = 1e8; 

int a[N]; //f[i][j]��ʾ��1~i����ţ�У�ѡ������ţ��������ģm��Ϊj�ģ��ܷ����� 
int f[N][M];
int n,m;

int main()
{ 
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++) //jȡ����m 
		{
			f[i][j] = (f[i-1][j] + f[i-1][((j-a[i]%m)%m+m)%m]) % MOD;			
		}
	}	
	
	cout << f[n][0] - 1 << endl; //�ų�f[0][0] ��ţ��������ţ����>=1 
	
	return 0;
}


//�����⣬���ҵĳ�ʼ����ʽ��ͬ 
#include<iostream>

using namespace std;

const int N = 2010, M = 1010, MOD = 1e8; 

int a[N]; //f[i][j]��ʾ��1~i����ţ�У�ѡ������ţ��������ģm��Ϊj�ģ��ܷ����� 
int f[N][M];
int n,m;

int main()
{ 
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) 
	{
		int x; cin >> x;
		a[i] = x % m;
		f[i][a[i]] = 1; // ��ʼ��������ѡ�� i ͷ��ţ������Ϊ R[i] �ķ������� 1����Щ���������������1 
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++) //jȡ����m 
		{
			f[i][j] = (f[i-1][j] + f[i][j] + f[i-1][(j-a[i]+m)%m]) % MOD; //Ҫ����ԭ����f[i][j]�����ó�ʼ����ֵչ��		
		}
	}	
	
	cout << f[n][0] << endl;
	
	return 0;
}
