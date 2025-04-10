#include<iostream>
#include<cstring> 
using namespace std;
const int N = 15;
int t[N],d[N],l[N];
int T,n;
bool st[N];
//这里是理解错了题意，我以为是要按照飞机编号顺序降落，这样就是简单的重复子问题 
//bool dfs(int pos,int fly) //pos：第i架飞机  fly：当前飞机实际起飞的时间 
//{	
//	if(fly > d[pos+1])
//	{
//		return false;
//	}
//	if(fly <= t[pos]) dfs(pos+1,t[pos]+l[pos]);
//	else dfs(pos+1,fly+l[pos]);
//	return true;
//}	

//第二次尝试，错误的编排 
//bool dfs(int pos,int end)
//{
//	if(pos > n) return true;
//	if(end > t[pos+1] + d[pos+1]) return false;
//	for(int i=1;i<=n;i++)
//	{
//		if(st[pos]) continue;
//		st[i] = true;
//		dfs(pos+1,max(end,t[pos+1])+l[pos+1]); 
//		st[pos] = false;
//	}
//}

bool dfs(int pos,int end) //在错误的思路中pos：第i架飞机，但实际上第i架飞机是根据循环中的i来决定的，pos是在统计飞机的数量，当pos>n这时递归的出口 
{
	if(pos > n) return true;
	
	for(int i=1;i<=n;i++)
	{
		if(st[i]) continue;
		if(end > t[i] + d[i]) continue; 
		
		st[i] = true; //在某一架飞机的前提下，我去选择剩下的某一架飞机，我就要将选择的飞机标为true，等前提下的递归结束后，我要将这架飞机标回false，因为我的前提要改变了，新前提下一切又都是新的 
		int new_end = max(end,t[i])+l[i];
		if(dfs(pos+1,new_end)) return true; //每次重新进入dfs都重新有n次机会去选择不同的i，再根据st[i]去筛选 
		st[i] = false; //还原现场 
	}
	return false; //递归是多层的，在很多个分治都可能走到这，如果走到这pos仍然小于n，就 return false 表示当前分支失败 
	//当所有飞机都尝试过但仍然无法安排时，说明当前路径无效，必须返回 false 让上层递归尝试其他可能性。
}

int main()
{
	cin >> T;
	while(T--)
	{
		memset(st,0,sizeof(st)); //多组测试用例要清空数据！！！！！ 
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> t[i] >> d[i]	>> l[i];	 
		}
		if(dfs(1,0)) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}	
	return 0;
}
