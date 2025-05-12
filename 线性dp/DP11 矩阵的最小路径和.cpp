#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int f[N][N],a[N][N];
int n,m;

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	
	//����Եֵ����Ϊ����󣬾Ͳ���Ӱ��״̬ת�Ʒ��̵�ȡ��Сֵ 
	memset(f[0],0x3f3f3f3f,sizeof f[0]);
	for(int i=1;i<=n;i++) f[i][0] = 0x3f3f3f3f; 
		
	//��ʼ��
	f[1][1] = a[1][1];	
	
	//״̬ת�Ʒ��� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==1 && j==1) continue;
			f[i][j] = min(f[i-1][j],f[i][j-1]) + a[i][j];
		}

//����	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout << f[i][j] << " ";
//		}
//		cout << endl;
//	}	
	
	cout << f[n][m] << endl;
	return 0;
}

//�����룬����Ҫ��ԭʼ�ľ���
int main()
{
	cin >> n >> m;
	
	//��ʼ��
	memset(f,0x3f,sizeof f); //ֱ�ӽ�����f�����ʼ��Ϊ�����		
	
	f[0][1] = 0; //������Ҫ��[0,1]λ�õ�ֵ����Ϊ0��Ҫ��Ȼf[1][1]ȡ������ȷ��ֵ��
	//���ҵĴ�������f[1][1]��ֱ���ֶ���ʼ���ģ�������ѭ������Ҫ��������[1,1]�����ķ����͸���� 
	
	//״̬ת�Ʒ��� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int a; cin >> a;
			f[i][j] = min(f[i-1][j],f[i][j-1]) + a;
		}
	
	
	cout << f[n][m] << endl;
	return 0;
} 
