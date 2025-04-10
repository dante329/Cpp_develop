#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
const int N = 15;
//一行只选一个
bool col[N]; //判断列 
bool st1[N*2],st2[N*2]; //判断主副对角线
//int a[N];
int n;
int ret;

void dfs(int pos)
{
	if(pos > n)
	{
		ret++;
		if(ret<=3) 
		{
			for(auto x:a) cout << x << " ";
			cout << endl;
		}
		
		return;
	}
	//每行已经有pos来控制了 
	for(int j=1;j<=n;j++) //每列 
	{
		if(col[j]) continue;
		if(st1[pos-j+n] || st2[pos+j]) continue;
		a.push_back(j); //记录结果 
		//打标记 
		st1[pos-j+n] = true; 
		st2[pos+j] = true;
		col[j] = true;
		//递归 
		dfs(pos+1);
		//还原现场 
		a.pop_back();
		st1[pos-j+n] = false; 
		st2[pos+j] = false;
		col[j] = false;			
	}
	
 } 
 
int main()
{
	cin >> n;
	dfs(1);
	cout << ret;	
	return 0;
}
