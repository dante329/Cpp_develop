#include<iostream> 

using namespace std;

string a; 
int b;

//����a�ر�������ַ��������ģ�����Ҫͨ������ַ�������ת����������
//ֱ�Ӱ�ʮ����λ��Ȩֵ������������̫���ˣ��������Ǹ��ݰ�Ȩֵ��������ʽ�ӵ�����������ʹ���ؾ����㷨
 
int calc() //�ؾ����㷨������a����ֵ 
{
	long long ret = 0;
	for(auto ch:a)
	{
		ret = (ret * 10 + ch - '0') % b;
	}
	return ret;
}

//int calc(string a)
//{
//	a = " " + a;
//	int len = a.size();
//	long long ret = 0;
//	for(int i=1;i<len;i++)
//	{
//		ret = (ret * 10 + a[i] - '0') % b;
//	}
//	return ret;
//}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b,a%b);	
}

int main()
{
	cin >> a >> b;
	
	cout << gcd(calc(),b) << endl;
	
	return 0;
}
