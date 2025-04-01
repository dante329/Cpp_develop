#include<iostream>
#include<algorithm>
using namespace std;
int n;
string a[25];

bool cmp(string a,string b)
{
	return a + b > b + a; //字符串是按照字典序来比较的，我们要保证拼数的结果是a + b要比b + a大，所以按照这个标准来sort，最后得到的结果直接拼在一起就是最大 
}
//如何证明ab，ba可以排序，那么要证明它们具有全序关系，完全性，反对称性，传递性 
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cout << a[i];
	return 0;
} 
