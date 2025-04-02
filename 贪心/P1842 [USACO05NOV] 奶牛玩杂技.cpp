#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 5e4 + 10;
struct node
{
	LL w,s;	
}a[N];
int n;

//重点理解：在C++的sort函数中，如果cmp(a, b)返回true，则a会排在b前面。因此，当比较函数返回的条件满足时，n1应该排在n2前面。这里的条件应该是，当n1排在n2前面时，两者的最大压扁指数更小。
bool cmp(node n1,node n2)
{
	return  max(n1.w - n2.s, -n1.s) < max(n2.w - n1.s, -n2.s);
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].w >> a[i].s;
	sort(a+1,a+n+1,cmp);
	LL sum = 0, ret = -1e9 - 10;
	for(int i=1;i<=n;i++)
	{		
		ret = max(ret,sum - a[i].s);
		sum += a[i].w;
	}
	cout << ret;
	return 0;
}
