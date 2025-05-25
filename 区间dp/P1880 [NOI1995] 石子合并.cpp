#include<iostream>
#include<cstring>

using namespace std;

const int N = 210;

int s[N]; //�����������ݣ�Ȼ��ĳ�ǰ׺������
int f[N][N],g[N][N]; //f[i][j]����Сֵ��g[i][j]�����ֵ 
int n;

int main()
{
	cin >> n;
	
	for(int i=1;i<=n;i++) 
	{
		cin >> s[i];
		s[i+n] = s[i]; //���������⣬��д 
	}
	
	//ǰ׺��
	for(int i=1;i<=2*n;i++)
	{
		s[i] += s[i-1];
	} 
	
	//��ʼ��dp�� 
	memset(f,0x3f,sizeof f); //�������ʼ��Ϊ0x3f����ôԭ����ֵ����0��ȡmin��ʱ��ͻ�ȡ��0
	memset(g,-0x3f,sizeof g);
	
	//��ʼ����ȷ���߼� 
	//��[i,j]��������У������䳤��Ϊ1ʱ�����������һ���ˣ�����Ҫ�ٺϲ������Ժϲ��Ĵ�����0 
	for(int i=1;i<=2*n;i++)
	{
		f[i][i] = 0;
		g[i][i] = 0;
	}
	  
	//״̬ת�Ʒ���len��2��ʼ���� 
	for(int len=2;len<=n;len++)
	{
		//ö����˵� 
		for(int i=1;len+i-1<=2*n;i++)
		{
			int j = len + i - 1;
			int cnt = s[j] - s[i-1];
			//ö�ٷָ��[i,k][k+1,j] 
			for(int k=i;k<j;k++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + cnt);	
				g[i][j] = max(g[i][j],g[i][k] + g[k+1][j] + cnt);
			} 
		}
	}
	
	//ȡ���
	int ret1 = 0x3f3f3f3f, ret2 = -0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		ret1 = min(ret1,f[i][n+i-1]);
		ret2 = max(ret2,g[i][n+i-1]);
	} 
	
	cout << ret1 << endl << ret2;
	
	return 0;
}
