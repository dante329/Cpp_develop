#include<iostream>
#include<algorithm>
using namespace std;
int n;
string a[25];

bool cmp(string a,string b)
{
	return a + b > b + a; //�ַ����ǰ����ֵ������Ƚϵģ�����Ҫ��֤ƴ���Ľ����a + bҪ��b + a�����԰��������׼��sort�����õ��Ľ��ֱ��ƴ��һ�������� 
}
//���֤��ab��ba����������ôҪ֤�����Ǿ���ȫ���ϵ����ȫ�ԣ����Գ��ԣ������� 
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout << a[i];
	return 0;
} 
