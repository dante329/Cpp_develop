#include <iostream>
using namespace std;
typedef long long LL;
const int N = 65;
LL f[N];
int n;

int main() 
{
	cin >> n;
	
	//��ʼ�� 
	f[0] = 1,f[1] = 1,f[2] = 2;
	
	for(int i=3;i<=n;i++)
	{
		//״̬ת�Ʒ��� 
		f[i] = f[i-1] + f[i-2] + f[i-3];
	}	
	cout << f[n];
	
	//���������
//	int a = 1,b = 1,c = 2;
//	for(int i=3;i<=n;i++)
//	{
//		int t = a + b + c;
//		a = b;
//		b = c;
//		c = t;
//	}
//	if(n == 1) cout << b;
//	else cout << c; 
	return 0;
}
