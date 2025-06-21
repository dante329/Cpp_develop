#include<iostream>
using namespace std;
typedef long long LL;

LL a,m;
string b;

LL get_phi(LL m)
{
	LL ret = m;
	for(int i=2;i<=m/i;i++)
	{
		if(m % i == 0) 
		{
			ret = ret * (i - 1) / i;
			while(m % i == 0) m /= i;
		}
	}
	if(m > 1) ret = ret * (m - 1) / m; //������ж�����������m>1������д��if(m)������m=1��ʱ��Ҳ���ȥ 
	return ret;
}

LL get_newb(string& b, LL phi)
{
	LL t = 0;
	bool flag = false;
	for(auto ch:b)
	{
		t = t * 10 + ch - '0';
		if(t >= phi) 
		{
			t %= phi;
			flag = true;
		}
	}
	if(flag) t += phi;
	return t;
}

LL qpow(LL a, LL b ,LL m) 
{
	LL ret = 1;
	while(b)
	{
		if(b & 1) ret = ret * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return ret;
}

int main()
{
	cin >> a >> m >> b; 
	
	LL phi = get_phi(m); //�󵥸�����ŷ���������������ֽ�+ŷ��������ʽ��
	
	LL new_b = get_newb(b,phi); //��չŷ�������� 
	
	cout << qpow(a,new_b,m) << endl;
	return 0;
} 
