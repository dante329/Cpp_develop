#include<iostream> 
using namespace std;
const int N = 2010;
int f[N][N]; //f[i][j]��ʾ����a�ַ�����[1,i]�ִ����b�ַ�����[1,j]�ִ���Ҫ����С�������� 
string a,b;

int main()
{
	cin >> a >> b;
	
	int n = a.size(), m = b.size();
	
	a = " " + a, b = " " + b;
	
	//�����ĳ�ʼ�����൱��Ҫ�ģ�iΪ0ʱ����a�ǿմ���jΪ0ʱ����b�ǿմ����о�ת����ϵ��֪��γ�ʼ�� 
	for(int i=1;i<=n;i++) f[i][0] = i;	
	for(int i=1;i<=m;i++) f[0][i] = i;
	
	//״̬ת�Ʒ��� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i] == b[j]) f[i][j] = f[i-1][j-1];
			else  
			{
				//���ֲ���ɾ�����滻������ֱ���f[i-1][j]��f[i-1][j-1]��f[i][j-1]
				//����ĳ��״̬������Ӧ�ַ���ͬʱ�����������ı仯ֻ�п������������ֲ����������ǵ���Сֵ 
				int t = f[i-1][j];
				t = min(t, f[i-1][j-1]);
				t = min(t, f[i][j-1]);
				f[i][j] = t + 1;
			}
		}
	}
	
	cout << f[n][m];
	return 0; 
}
