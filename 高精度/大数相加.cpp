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
//	int a[len1+10],b[len2+10],c[lenMax]; //不能这样定义数组，无论是在全局中还是局部中，定义数组的大小一定要指定为常量，不可为变量或者程序运行后再给出 
//	
//	for(int i=0;i<len1;i++) a[i] = s1[len1-1-i] - '0';
//	for(int i=0;i<len1;i++) b[i] = s2[len1-1-i] - '0'; //眼睛瞎了b数组用len1初始化，666 
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

//正确解法 
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

//模板
#include<iostream>

using namespace std;
const int N = 1e6 + 10; 
int a[N],b[N],c[N];
int len1,len2,lenMax; //长度要提前定义在全局，在函数中要使用 

void add(int c[],int a[],int b[])
{
	for(int i=0;i<lenMax;i++)
	{
		c[i] += a[i] + b[i]; //这里一定是+= ，因为要加上 上一位 给的进位值 
		c[i + 1] = c[i] / 10; //先处理进位，给下一个位置
		c[i] %= 10; //再取模存入c[i] 
	}
	//处理整体进位后结果长度要+1
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

	add(c,a,b); //a数组、b数组相加的结果放在c数组 
	
	for(int i=lenMax-1;i>=0;i--) cout << c[i]; 
	return 0;
}
 
