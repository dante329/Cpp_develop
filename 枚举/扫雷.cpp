//ö������������ɣ���һ��λ�����׺Ͳ����ף�Ȼ����������޶���������λ�ã�����ٿ��ϲ��Ϸ� 
#include<iostream>
using namespace std;

const int N = 1e4 + 10;
int a[N],b[N];
int n,ret;

int check1()
{
	a[1] = 1;
	for(int i=2;i<=n+1;i++)
	{
		a[i] = b[i-1] - a[i-2] - a[i-1];
		if(a[i] < 0 || a[i] > 1) return 0;
	}
	if(a[n+1]) return 0;
	else return 1; 
} 
 
int check2()
{
	a[1] = 0;
	for(int i=2;i<=n+1;i++)
	{
		a[i] = b[i-1] - a[i-2] - a[i-1];
		if(a[i] < 0 || a[i] > 1) return 0;
	}
//	if(a[n+1]) return 0;
//	else return 1; 
	if(a[n+1] == 0) return 1;
	else return 0; 
 } 

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> b[i]; 
	ret += check1(); //һ��λ������
	ret += check2(); //��һ��λ�ò�����
	cout << ret;
	return 0;
}
