#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL; //����Զ�ȡģ 
const int N = 1e4 + 10;
ULL a[N]; //�����洢�ַ���ϣ֮�����ֵ 
int n;
int P = 131; //��������һ��Ϊ 131 / 13331 / ���� 

ULL gethash(string& s)
{
	int ret = 0;
	for(int i=0;i<s.size();i++)
	{
		ret = ret * P + s[i];
	}
	return ret;
}

int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		string s; cin >> s;
		a[i] = gethash(s); //���ַ�����ϣ������ 
	}	

//���㲻�ظ�����	
//��ʽһ��sort + uniqueȥ�� 
	sort(a + 1, a + n + 1);
	int ret = unique(a + 1,a + n + 1) - (a + 1);

//��ʽ����sort + ����һ��ָ�룬�������ظ�Ԫ�ؾ�ret++ 
//	int ret = 1;
//	for(int i=2;i<=n;i++)
//	{
//		if(a[i] != a[i-1]) ret++;
//	 } 
	cout << ret;
	return 0;
}
