#include <iostream>
using namespace std; 
const int N = 1e4 + 10;
int a[N],b[N],g[N],k[N];
int n;
int x,y;
int ret;
int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i] >> b[i] >> g[i] >> k[i];
	cin >> x >> y;
	for(int i=n;i>=1;i--) 
	{
		if(x>=a[i] && x<=a[i]+g[i] && y>=b[i] && y<=b[i]+k[i]) 
		{
			ret = i;
			break; 
		 } 
	}
	if(!ret) cout << -1;
	else cout << ret; 
	return 0;
}
