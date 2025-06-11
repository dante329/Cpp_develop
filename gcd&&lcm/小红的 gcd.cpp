#include<iostream> 

using namespace std;

string a; 
int b;

//由于a特别大，是用字符串给出的，我们要通过这个字符串将它转换成整数。
//直接按十进制位的权值来计算数据量太大了，所以我们根据按权值计算的这个式子的特征，可以使用秦九绍算法
 
int calc() //秦九绍算法，计算a的数值 
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
