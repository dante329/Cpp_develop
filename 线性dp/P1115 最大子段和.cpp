#include <iostream>
using namespace std;
const int N = 2e5 + 10;

int f[N];
int n;

int main() 
{
	cin >> n;
	
	int ret = -0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		int a; cin >> a;
		f[i] = max(f[i-1],0) + a;
		ret = max(ret,f[i]); 
	}
	
	cout << ret; 
	return 0;
}
