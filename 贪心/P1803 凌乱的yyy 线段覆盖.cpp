//区间贪心
#include<iostream>
#include<algorithm> 
using namespace std; 
const int N = 1e6 + 10;
struct node
{
	int l,r;	
}a[N];
int n;

bool cmp(node& n1,node& n2)
{
	return n1.l < n2.l;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].l >> a[i].r;
	sort(a+1,a+n+1,cmp);
	int r = a[1].r , ret = 1;
	for(int i=2;i<=n;i++)
	{
		if(r > a[i].l) //保留右区间较小的那个
		{
			r = min(r,a[i].r);
		}
		else 
		{
			r = a[i].r;
			ret++;	
		} 
	}
	cout << ret;
	return 0;
}
