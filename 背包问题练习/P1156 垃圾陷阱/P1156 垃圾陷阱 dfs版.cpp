#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

//bool dp[10010][110][110];
map<int,map<int,map<int,bool>>> dp; //数组空间不够时用map

struct node
{
	int t,f,h;
}a[110];

int d, g;
int ans1 = 1e9, ans2 = 0;

bool cmp(node& a, node& b)
{
	return a.t < b.t;
}

void dfs(int f,int h,int pos)
{
	if(h >= d) 
	{
		ans1 = min(ans1, a[pos-1].t);
		return;
	}
	if(f < a[pos].t || pos > g)
	{
		ans2 = max(ans2, f);
		return;
	}
	
	if(dp[f][h][pos]) return;
	dp[f][h][pos] = true;
	
	dfs(f + a[pos].f, h, pos + 1);
	dfs(f, h + a[pos].h, pos + 1);
	return;
}

int main()
{
	cin >> d >> g;
	
	for(int i=1;i<=g;i++)
	{
		cin >> a[i].t >> a[i].f >> a[i].h;
	}
	
	sort(a + 1,a + 1 + g,cmp);
	
	dfs(10,0,1);
	
	if(ans1 == 1e9) cout << ans2;
	else cout << ans1;
	
	return 0; 
}