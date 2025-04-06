#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<int,int> mp;
typedef long long LL;
const int N = 2e4 + 10;
LL a[N],b[N],n;
LL disc[N*2],pos;  //对所有数据离散化，a、b数组要用的时候再去disc中找
LL f[N*2];

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; 
		disc[++pos] = b[i];
	}
	//离散化 
	sort(disc+1,disc+1+pos); 
	pos = unique(disc+1,disc+1+pos) - (disc+1);

	for(int i=1;i<=pos;i++)
	{
		int x = disc[i]; 
		mp[x] = i; 	
	}
	//构建差分数组 
	for(int i=1;i<=n;i++)
	{
		int l = mp[a[i]], r = mp[b[i]]; //x,y表示离散后的值 
		f[l]++, f[r]--;
	}
	//还原数组
	for(int i=1;i<=pos;i++) 
	{
		f[i] += f[i-1];
	}
	//找连续区间
	int ret = 0;
	for(int i=1;i<=pos;i++) 
	{
		int j =  i;
		while(j<=pos && f[j]>0) j++; //j停下的位置就是0 
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;
	return 0;
}
