#include<iostream>

using namespace std;

const int N = 1e4 + 10;
int a[N][N];
int f[N][N];
int n,m;
int x,y,v;
int main()
{
	cin >> n >> m;
	//������ 
	while(n--)
	{		 
		cin >> x >> y >> v;
		a[++x][++y] += v; //���ܴ��ڶ��Ŀ����ͬһλ���ϵ������
	}
	//������άǰ׺�� 
	int edge = 5001; //��Ŀû�и���������ķ�Χ���������Ƕ���һ��edge��ʾm�����Χ 
	for(int i=1;i<=edge;i++)
	{
		for(int j=1;j<=edge;j++)
		{
			f[i][j] = f[i-1][j] + f[i][j-1] -f[i-1][j-1] + a[i][j]; 
		}
	}
	//ö��m�������½����������λ��
	int ret = 0;
	m = min(m,edge); 
	for(int x2=m;x2<=edge;x2++)	
	{
		for(int y2=m;y2<=edge;y2++)
		{
			int x1 = x2 - m + 1; 
			int y1 = y2 - m + 1;
			//��(x1,y1)��(x2,y2)�����ڵļ�ֵ�ͣ��õ�fǰ׺������ 
			ret = max(ret,f[x2][y2]-f[x1-1][y2]-f[x2][y1-1]+f[x1-1][y1-1]);
		}
	} 
	cout << ret << endl;
	return 0;
}
