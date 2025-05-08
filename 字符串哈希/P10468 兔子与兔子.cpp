#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL; 

const int N = 1e6 + 10, P = 131;

ULL f[N]; //ǰ׺��ϣֵ����
ULL p[N]; //��¼p��n���ݵ�ֵ 
string s;
int n;

void init_hash()
{
	p[0] = 1; //p��0��Ϊ1
	f[0] = 0;  
	for(int i=1;i<=n;i++)
	{
		f[i] = f[i-1] * P + s[i];
		p[i] = p[i-1] * P; 
	}
}

ULL get_hash(int l,int r)
{
	return f[r] - f[l-1] * p[r - l + 1];
}

int main() 
{
	int m;
	cin >> s >> m;
	s = " " + s; //���ַ���ǰ���һ���ո񣬾Ϳ��Դ��±�Ϊ1��ʼ�����ַ��� 
	n = s.size(); //���ַ������� 
	init_hash();
	while(m--)
	{
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if(get_hash(l1,r1) == get_hash(l2,r2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
