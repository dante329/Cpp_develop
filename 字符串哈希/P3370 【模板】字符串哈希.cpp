#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL; //溢出自动取模 
const int N = 1e4 + 10;
ULL a[N]; //用来存储字符哈希之后的数值 
int n;
int P = 131; //进制数，一般为 131 / 13331 / 质数 

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
		a[i] = gethash(s); //将字符串哈希成数字 
	}	

//计算不重复数字	
//方式一：sort + unique去重 
	sort(a + 1, a + n + 1);
	int ret = unique(a + 1,a + n + 1) - (a + 1);

//方式二：sort + 定义一个指针，遇到不重复元素就ret++ 
//	int ret = 1;
//	for(int i=2;i<=n;i++)
//	{
//		if(a[i] != a[i-1]) ret++;
//	 } 
	cout << ret;
	return 0;
}
