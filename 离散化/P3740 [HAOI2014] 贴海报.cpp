#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 1010;
int n,m;
int a[N],b[N];
int disc[N * 4],pos; //disc要离散化a、b及其每个元素的相邻元素 
unordered_map<int,int> mp;

int main()
{
	cin >> n >> m;
	//存数据
	for(int i=1;i<=m;i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; disc[++pos] = a[i]+1; 
		disc[++pos] = b[i]; disc[++pos] = b[i]+1; 
	}
	//离散化	
	sort(disc+1,disc+1+pos);
	int cnt = 0;
	for(int i=1;i<=pos;i++)
	{
		if(mp.count(disc[i])) continue;
		mp[disc[i]] = ++cnt;	
	} 
	//模拟贴海报 
	int w[N * 4];
	for(int i=1;i<=m;i++)
	{
		//用离散化之后的值去代替左右边界 a[i] ~ b[i] 
		int l = mp[a[i]], r = mp[b[i]];
		for(int j=l;j<=r;j++) w[j] = i;	
	} 
	//检查有多少个不同的数字 
	bool st[N * 4];
	int ret = 0;
	for(int i=1;i<=cnt;i++) //在w中贴完海报之后，海报最大的右边界是b[i]，而这个值在离散化后的最大范围是cnt 
	{
		int x = w[i];
		if(st[x] == true || x == 0) continue;
		ret++;
		st[x] = true;
	}
	cout << ret << endl;
	return 0;
}
