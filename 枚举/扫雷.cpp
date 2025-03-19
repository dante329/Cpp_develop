//枚举两种情况即可，第一个位置埋雷和不埋雷，然后根据数量限定推算其他位置，最后再看合不合法 
#include<iostream>
using namespace std;

const int N = 1e4 + 10;
int a[N],b[N];
int n,ret;

int check1()
{
	a[1] = 1;
	for(int i=2;i<=n+1;i++)
	{
		a[i] = b[i-1] - a[i-2] - a[i-1];
		if(a[i] < 0 || a[i] > 1) return 0;
	}
	if(a[n+1]) return 0;
	else return 1; 
} 
 
int check2()
{
	a[1] = 0;
	for(int i=2;i<=n+1;i++)
	{
		a[i] = b[i-1] - a[i-2] - a[i-1];
		if(a[i] < 0 || a[i] > 1) return 0;
	}
//	if(a[n+1]) return 0;
//	else return 1; 
	if(a[n+1] == 0) return 1;
	else return 0; 
 } 

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> b[i]; 
	ret += check1(); //一个位置埋雷
	ret += check2(); //第一个位置不埋雷
	cout << ret;
	return 0;
}
