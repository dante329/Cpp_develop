//����ֵ����ʽ |a-x| + |b-x| >= |a-b|   x��a,b�м�ʱȥ�� 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;

int main() 
{
	cin >> n;
	//������������ 
	for(int i=1;i<=n;i++) cin >> a[i];
	//���� 
	sort(a+1,a+n+1);
	int ret = 0;
	//����1��ֱ���ù�ʽ���� 
//	 
//	//nΪ����ʱ������λ�ÿ϶����м��Ǹ������ϣ��м��Ǹ����־�����յľ���Ϊ0������Ҫ���� 
//	for(int i=1;i<=n/2;i++) ret += abs(a[i]-a[n+1-i]);
//	 

	//����2������������������������ݵ��м䣬Ҫ��������ż����ô������ȡ���м�ֵ 
	for(int i=1;i<=n;i++) ret += abs(a[i]-a[(n+1)/2]);
	
	
	cout << ret; 
	return 0;
}
