#include <iostream>
#include <cstring> 

using namespace std;

const int N = 1010;

int f[N][N];
int v[N],w[N];
int n,m; //n����Ʒ���������m 

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	//��һ�� 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) //��v[i]�п��ܵ���0ʱ��j�����0��ʼ��ʼ������Ϊj>=v[i]����һ������Խ�� 
		{ 
			f[i][j] = f[i - 1][j]; //һ�����ȼ��費ѡ 
			if(j >= v[i]) //����������¸�ֵ 
			{
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);		
			}
			
			//��������������д��ע�����֡���f[i][j] = f[i - 1][j]������������������Ǹ�if�в��ж�������ȡmax����Ȼf[i][j]��ֵ��0 
//			if(j >= v[i]) //������� 
//			{
//				f[i][j] = f[i-1][j-v[i]] + w[i];		
//			}		
//			else //������� 
//			{
//				f[i][j] = f[i-1][j];
//			}
		}
	} 

	cout << f[n][m] << endl;
	
	//�ڶ���
	memset(f,-0x3f3f3f3f,sizeof f);
	f[0][0] = 0; 
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) 
		{
			f[i][j] = f[i - 1][j]; 
			if(j >= v[i]) 
			{
				f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);		
			}
		}
	} 

	if(f[n][m] < 0) cout << 0 << endl;
	else cout << f[n][m] << endl;
	
	return 0;
}


//�ռ��Ż��棨�������飩
#include <iostream>
#include <cstring> 

using namespace std;

const int N = 1010;

int f[N];
int v[N],w[N];
int n,m; //n����Ʒ���������m 

int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> v[i] >> w[i];
	
	//��һ�� 
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=v[i];j--) 
		{ 
			f[j] = max(f[j], f[j - v[i]] + w[i]);		
		}
	} 

	cout << f[m] << endl;
	
	//�ڶ���
	memset(f,-0x3f3f3f3f,sizeof f);
	f[0] = 0; 
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=v[i];j--) 
		{
			f[j] = max(f[j], f[j - v[i]] + w[i]);		
		}
	} 

	if(f[m] < 0) cout << 0 << endl;
	else cout << f[m] << endl;
	
	return 0;
} 
