#include<iostream>

using namespace std;
const int N = 255;

int a[N];
int f[N][N]; //f[i][j]��ʾ��������[i,j]���ܺϲ���һ�����ֵ����ֵ���Ƿ�Ϊ0 
int n;

int main()
{
	cin >> n;
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		ret = max(ret, a[i]);
	}

	//ȫ����ʼ��Ϊ0 
		
	//����Ϊ1�������״̬Ϊ������ 
	for(int i=1;i<=n;i++) f[i][i] = a[i];
	
	for(int len=2;len<=n;len++)
	{
		for(int i=1;len+i-1<=n;i++)
		{
			int j = len+i-1;
			for(int k=i;k<j;k++)
			{
				if(f[i][k] != 0 && f[i][k] == f[k+1][j]) f[i][j] = max(f[i][j],f[i][k] + 1);
			}
			ret = max(ret,f[i][j]);
		}
	}
	
	cout << ret;
	return 0;
 } 
