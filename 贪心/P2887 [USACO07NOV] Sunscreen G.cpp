#include<iostream> 
#include<algorithm>
using namespace std;
const int N = 3000;
struct node
{
	int x; //最小值  / 维持值 
	int y; //最大值 / 数量 
}a[N],b[N];
int n,m;

bool cmp(node& n1,node& n2)
{
	return n1.x > n2.x;
}

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i].x >> a[i].y;
	for(int i=1;i<=m;i++) cin >> b[i].x >> b[i].y;
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp); 
	int ret = 0;
	for(int i=1;i<=n;i++) //循环牛 
	{	
		int left = a[i].x,right = a[i].y;
		for(int j=1;j<=m;j++) //循环防晒霜 
		{
			int w = b[j].x, &cnt = b[j].y;
			if(w > right) continue; //当前的防晒霜大了，去找下一个防晒霜 
			if(w < left) break; //最大的防晒霜都满足不了这头牛，直接去找下一头牛 
			if(cnt == 0) continue;
			cnt--;	
			ret++;
			break; //走到这了就是找到合适的防晒霜了就不要再往下找了 
		}
	}
	cout << ret << endl;
	return 0;
}
