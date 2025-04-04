#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1010;
struct node
{
	double l,r; //一个点投射到x轴上的区间的左右端点	
}a[N];
int n;
double d;

bool cmp(node& n1,node& n2)
{
	return n1.l < n2.l;
}

int main()
{
	int cnt = 0;
	while(cin >> n >> d,n && d)
	{
		cnt++;
		bool flag = true;
		for(int i=1;i<=n;i++)	
		{
			double x,y; cin >> x >> y;
			if(d<y)
			{
				flag = false;
				cout << "Case " << cnt << ": -1" << endl;	
				break;
			}
			double l = sqrt(d*d-y*y);
			a[i].l = x-l, a[i].r = x+l;
		}
		sort(a+1,a+n+1,cmp);
		int ret = 1;
		double r = a[1].r;
		for(int i=2;i<=n;i++)
		{
			if(a[i].l > r) 
			{
				ret++;
				r = a[i].r;
			}
			else 
			{
				r = min(r,a[i].r);
			}
		}
		if(flag)
		{
			cout << "Case " << cnt << ": " << ret << endl;
		}
	}	
	return 0;
}
