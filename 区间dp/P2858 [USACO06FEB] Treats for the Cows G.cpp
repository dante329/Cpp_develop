#include<iostream>

using namespace std;

const int N = 2010;

int n;
int a[N];
int f[N][N];

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//ȫ����ʼ��Ϊ0���Ƿ��ĸ���ȡ��0Ҳû�£������ȥmax��Ӱ��
	 
	//״̬ת�Ʒ��� 
	for(int len=1;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++)
		{
			int j = len + i - 1;
			int cnt = n - len + 1; //��cnt�� 
			
			f[i][j] = max(f[i+1][j] + a[i]*cnt, f[i][j-1] + a[j]*cnt);	
		}
	 } 
	
	cout << f[1][n];
	return 0;
}
