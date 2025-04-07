#include<iostream>
using namespace std;
const int N = 11;

int f[1 << N]; //前缀和 
int n;

void dfs(int l,int r)
{
	if(l > r) return; 
	//判断这个区间是什么串
	char ret;
	int sum = f[r] - f[l-1];
	if(sum == 0) ret = 'B';
	else if(sum == (r-l+1)) ret = 'I';
	else ret = 'F';
	if(l == r) 
	{
		cout << ret;
		return;
	}
	//判断左右子串 
	int mid = (l + r) / 2;
	dfs(l,mid);
	dfs(mid+1,r);
	//后序遍历，最后输出根节点
	cout << ret;  
}

int main()
{
	cin >> n;	
	n = (1 << n);
	//读数据，但不需要构建树，直接存到全局的前缀和数组中，在dfs中利用前缀和判断FBI串 
	for(int i=1;i<=n;i++)
	{
		char ch; cin >> ch;
		f[i] = f[i-1] + (ch - '0');
	}
	dfs(1,n);
	return 0;
}
