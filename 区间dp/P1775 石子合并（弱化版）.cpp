#include<iostream> 
#include<cstring>

using namespace std;

const int N = 310;

int sum[N]; //ǰ׺�� 
int f[N][N]; //f[i][j]��ʾ�ϲ�[i,j]����������ʯ�ӵ���С���� 
int n;

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		int x; cin >> x;
		sum[i] = sum[i-1] + x;
	}
	
	memset(f,0x3f,sizeof f);
	
	for(int i=1;i<=n;i++) f[i][i] = 0;
	
	for(int len=2;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++)
		{
			int j = len+i-1;
			int cnt = sum[j] - sum[i-1];
			//[i,j]����ĺϲ��������������������ֵĺϲ�
			//ö�ٷָ��k���������Ϊ[i,k][k+1,j] 
			for(int k=i;k<j;k++)
			{				
				f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + cnt);
			}
		}
	}
	
	cout << f[1][n];
	
	return 0;
}
