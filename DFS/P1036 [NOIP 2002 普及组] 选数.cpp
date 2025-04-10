#include <iostream>
using namespace std;
const int N = 25;
int a[N];
int ret,path;
int n,k;

bool is_prime(int x)
{
	if(x <= 1) return false;
	for(int i = 2;i <= x/i;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
} 

void dfs(int pos,int begin) //pos为当前位置，begin为当前位置从哪个数开始填 
{
	if(pos > k) 
	{
		if(is_prime(path)) ret++;
		return;
	}
	for(int i=begin;i<=n;i++)
	{
		path += a[i];
		dfs(pos+1,i+1);
		path -= a[i];
	}	
}

int main() 
{
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	dfs(1,1); 	
	cout << ret << endl; 
	return 0;
}
