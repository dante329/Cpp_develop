//�Լ���ķ�������ʼ���������ε���������������֤��Խ�磬��ʵ���ϴ��±�Ϊ1��ʼ�����ݣ�����Ͳ���Խ�磬�Խ��Ҳû��Ӱ�죬��Ϊ�±�Ϊ0�Ĵ�Ķ���0 
//#include<iostream>
//
//using namespace std;
//const int N = 1010;
//int a[N][N],n;
//int f[N][N]; //״̬��ʾ 
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//	
//	f[1][1] = a[1][1];
//	
//	for(int i=2;i<=n;i++) 
//	{
//		//��ʼ����� 
//		f[i][1] = f[i-1][1] + a[i][1];
//		//��ʼ���ұ� 
//		f[i][i] = f[i-1][i-1] + a[i][i];
//	}
//	 
//	for(int i=3;i<=n;i++)
//	{
//		for(int j=2;j<=i-1;j++)
//		{
//			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
//		}
//	}
//	
//	if(n == 1)
//	{
//		cout << a[1][1] << endl;
//	}
//	else if(n == 2)
//	{
//		cout << max(a[2][1],a[2][2]) + a[1][1] << endl;
//	}
//	else
//	{
//		int ret = 0;
//		for(int i=1;i<=n;i++) ret = max(ret,f[n][i]);
//		cout << ret;
//	}
//	return 0; 
//}

//���
#include<iostream>

using namespace std;
const int N = 1010;
int a[N][N],n;
int f[N][N]; //״̬��ʾ 

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin >> a[i][j];
		}
	}
	 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
		}
	}
	
	//�ռ��Ż�����άתһά����Ҫ��f[N][N]�ĳ�f[N]���ȿ����Ƿ���Ҫ�޸ı���˳���ٽ�f����һά����ɾ������ 
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			f[j] = max(f[j-1], f[j]) + a[i][j];
		}
	}

	int ret = 0;
	for(int i=1;i<=n;i++) ret = max(ret,f[n][i]);
	cout << ret;
	return 0; 
}
