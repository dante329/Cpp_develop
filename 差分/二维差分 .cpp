#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e3 + 10;
//int a[N][N]; //����Ҫԭ���飬ֱ�Ӹ��ݶ����ʼ��������� 
LL f[N][N]; //������� 
int n,m,q;

int main()
{
	cin >> n >> m >> q;	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//ֱ�����ö����ʼ��������� 
			int x; cin >> x;
			f[i][j] += x;
			f[i][j+1] -= x;
			f[i+1][j] -= x;
			f[i+1][j+1] += x;
		}
	} 
	while(q--)
	{
		int x1,y1,x2,y2,k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;	
		f[x1][y1] += k;
		f[x1][y2+1] -= k;
		f[x2+1][y1] -= k;
		f[x2+1][y2+1] += k;
	} 
	//��ԭ���� �Բ��������ǰ׺�� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			//��ԭ��ÿһ��λ�õ�Ԫ�أ���ô��Ҫ�õ�ǰ׺�͵ĳ�ʼ����ʽ 
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + f[i][j]; 
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
