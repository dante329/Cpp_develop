//��ʽһ�����ݵ��ƹ�ʽ��ʼ��������飬��ʱ��Ҫ����ԭʼ���� 
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10; 
LL a[N]; //�洢ԭʼ���� 
LL f[N]; //������� 
int n,m; //Ԫ���������������� 
int main() 
{
	cin >> n >> m; 
	//�洢���� ͬʱ��ʼ��������� 
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		f[i] = a[i] - a[i-1];
	}
	//�������ݣ�m�β���
	//�ԣ�l��r������ͳһ����k���ȼ�����f[l]+=k f[r+1]-=k 
	while(m--)
	{
		int l,r,k;
		cin >> l >> r >> k;
		f[l] += k; f[r+1] -= k;
	}
	//��ԭ���飬�Բ��������ǰ׺�;Ϳ��Ի�ԭ 
	for(int i=1;i<=n;i++)
	{
		//a[i] = a[i-1] + f[i] �ǵ�����ʽ���ʺϱ��ʵ�֡�
		//a[i] = f[1] + f[2] + ... + f[i] ����ʽ��ʽ���ʺ���ѧ������
		a[i] = a[i-1] + f[i];
		cout << a[i] << " ";
	}
		 
	return 0;
}
