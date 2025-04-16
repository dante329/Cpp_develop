#include<iostream>
#include<algorithm>
using namespace std;

const int N = 20;
int n,w;
int a[N];
int sum[N]; //每一辆车目前的总重量 
int cnt; //统计当前花费，也是车辆的数量 
int ret = N; //最终返回值，最优解 

bool cmp(int a,int b)
{
	return a > b;
}

void dfs(int pos)
{
	//策略二：最优性剪枝 
	if(cnt >= ret) return;

	if(pos > n) //程序走到这来，cnt一定是小于ret的 
	{
		ret = cnt;
		return;
	}
	
	//策略三:先安排到已有的车辆上，如果塞不下就重开车 
	for(int i=1;i<=cnt;i++) 
	{
		//策略一：可行性优化 
		if(sum[i] + a[pos] > w) continue;
		
		sum[i] += a[pos];
		dfs(pos + 1);
		sum[i] -= a[pos];
	}
	
	cnt++;
	sum[cnt] = a[pos];
	dfs(pos + 1);
	sum[cnt] = 0;
	cnt--;
}


int main()
{
	cin >> n >> w;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	//策略三：优化搜索顺序 
	sort(a+1,a+n+1,cmp);
	
	dfs(1);	
	
	cout << ret << endl;
	return 0;
}
