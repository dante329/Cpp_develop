#include<iostream>
using namespace std;
int n,q;
const int N = 1e5 + 10;
int a[N];

int solve()
{
	int x,y; cin >> x >> y;
	int left = 1,right = n,ret_left = 0;
	while(left < right)
	{
		int mid = left + (right - left) / 2;
		if(a[mid] >= x) right = mid;
		else left = mid + 1;
	}
	if(a[left] < x) return 0;
	else if(a[left] == x) ret_left = left;
	else ret_left = left + 1;
	
	left = 1,right = n;
	while(left < right)
	{
		int mid = left + (right - left + 1) / 2;
		if(a[mid] <= y) left = mid;
		else right = mid - 1;
	}   
	if(a[left] > y) left--; 
	return left - ret_left + 1;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	cin >> q;
	while(q--)
	{
		cout << solve() << endl;
	}
	return 0;
 } 
