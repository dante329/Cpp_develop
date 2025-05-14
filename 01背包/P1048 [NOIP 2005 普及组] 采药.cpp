//#include<iostream>
//
//using namespace std;
//
//const int N = 1010;
//
//int t[N],w[N];
//int f[N][N]; //f[i][j]��ʾ ��1~i����ҩ�У�ʱ�䲻����j���ܲ�ҩ����ֵ 
//int n,m; 
//
//int main()
//{
//	cin >> m >> n;
//	
//	for(int i=1;i<=n;i++) cin >> t[i] >> w[i];
//	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=m;j++)
//		{
//			f[i][j] = f[i-1][j];
//			if(j >= t[i])
//			{
//				f[i][j] = max(f[i][j], f[i-1][j-t[i]] + w[i]);
//			}
//		}
//	}
//	cout << f[n][m];
//	return 0;
// } 
 
//�ռ��Ż�
#include<iostream>

using namespace std;

const int N = 1010;

int t[N],w[N];
int f[N]; //f[i][j]��ʾ ��1~i����ҩ�У�ʱ�䲻����j���ܲ�ҩ����ֵ 
int n,m; 

int main()
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++) cin >> t[i] >> w[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=t[i];j--)
		{
			f[j] = max(f[j], f[j-t[i]] + w[i]);
		}
	}
	cout << f[m];
	return 0;
 }  
