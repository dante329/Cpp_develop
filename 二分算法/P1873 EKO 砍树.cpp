//�ܽ᣺������������������ݴ�С�ܴ�ģ����������滻��intȫ������LL����Ҫ����ȥ����߼� 
#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N];
LL n,m;

LL clac(LL h)
{
	LL sum = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i] > h) sum += a[i] - h;
	}
	return sum;
}

int main()
{
	cin >> n >> m; //m��һ����׼ 
	for(int i=1;i<=n;i++) cin >> a[i];
	//���ָ߶� ����Ҫ��ľ���ܳ���m���Ƚ�
	LL left = 0,right = 1e6;
	while(left < right)
	{
		LL mid = (left + right + 1) / 2;
		if(clac(mid) >= m) left = mid;
		else right = mid - 1;
	}
	cout << left << endl;
	return 0;
}
