//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	string s1,s2;
//	cin >> s1 >> s2;
//	int len1 = s1.length(), len2 = s2.length();
//	int lenMax = max(len1,len2);
//	int a[len1+10],b[len2+10],c[lenMax]; //���������������飬��������ȫ���л��Ǿֲ��У���������Ĵ�Сһ��Ҫָ��Ϊ����������Ϊ�������߳������к��ٸ��� 
//	
//	for(int i=0;i<len1;i++) a[i] = s1[len1-1-i] - '0';
//	for(int i=0;i<len1;i++) b[i] = s2[len1-1-i] - '0'; //�۾�Ϲ��b������len1��ʼ����666 
//
//	int rem = 0;
//	for(int i=0;i<lenMax;i++)
//	{
//		int ret = (a[i] + b[i] + rem);
//		rem = ret / 10;
//		ret = ret % 10;
//		c[i] = ret;
//	}
//	if(rem)
//	{
//		c[++lenMax-1] = rem;
//	}
//	
//	
//	for(int i=lenMax-1;i>=0;i--)
//	{
//		cout << c[i];
//	}
//	return 0;
//}

//��ȷ�ⷨ 
//#include<iostream>
//
//using namespace std;
//const int N = 1e6 + 10; 
//int a[N],b[N],c[N];
//int main()
//{
//	string s1,s2;
//	cin >> s1 >> s2;
//	int len1 = s1.length(), len2 = s2.length();
//	int lenMax = max(len1,len2);
//	
//	
//	for(int i=0;i<len1;i++) a[i] = s1[len1-1-i] - '0';
//	for(int i=0;i<len2;i++) b[i] = s2[len2-1-i] - '0';
//
//	int rem = 0;
//	for(int i=0;i<lenMax;i++)
//	{
//		int ret = (a[i] + b[i] + rem);
//		rem = ret / 10;
//		ret = ret % 10;
//		c[i] = ret;
//	}
//	if(rem)
//	{
//		c[++lenMax-1] = rem;
//	}
//	
//	
//	for(int i=lenMax-1;i>=0;i--)
//	{
//		cout << c[i];
//	}
//	return 0;
//} 

//ģ��
#include<iostream>

using namespace std;
const int N = 1e6 + 10; 
int a[N],b[N],c[N];
int len1,len2,lenMax; //����Ҫ��ǰ������ȫ�֣��ں�����Ҫʹ�� 

void add(int c[],int a[],int b[])
{
	for(int i=0;i<lenMax;i++)
	{
		c[i] += a[i] + b[i]; //����һ����+= ����ΪҪ���� ��һλ ���Ľ�λֵ 
		c[i + 1] = c[i] / 10; //�ȴ����λ������һ��λ��
		c[i] %= 10; //��ȡģ����c[i] 
	}
	//���������λ��������Ҫ+1
	if(c[lenMax]) lenMax++; 
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	len1 = s1.length(), len2 = s2.length();
	lenMax = max(len1,len2);
	
	for(int i=0;i<len1;i++) a[i] = s1[len1-1-i] - '0';
	for(int i=0;i<len2;i++) b[i] = s2[len2-1-i] - '0';

	add(c,a,b); //a���顢b������ӵĽ������c���� 
	
	for(int i=lenMax-1;i>=0;i--) cout << c[i]; 
	return 0;
}
 
