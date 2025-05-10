#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N],n;
int tr[N * 32][2],idx;

void insert(int x)
{
	int cur = 0;
	
	for(int i=31;i>=0;i--)
	{
		int path = (x >> i) & 1;
		if(tr[cur][path] == 0) tr[cur][path] = ++idx;
		cur = tr[cur][path];	
	} 
}

int find(int x)
{
	int cur = 0;
	int ret = 0;
	for(int i=31;i>=0;i--)
	{
		int path = (x >> i) & 1;
		if(tr[cur][path ^ 1] == 0) //[path ^ 1]表示走相反的路，如果没有路就退而求其次
		{
			cur = tr[cur][path]; //走原本的路 
		} 
		else //[path ^ 1]有路 
		{
			ret |= (1 << i); //因为理想最大结果是011111111，如果走得通就是符合理想最大每一位上都是1，对应位与等上一个1即可，如果走不通就不管它，ret本身初始化的就是0 
			cur = tr[cur][path ^ 1];
		}	
	} 
	return ret;	
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i]; 
		insert(a[i]);
	}
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		ret = max(ret,find(a[i]));
	}
	cout << ret << endl;
	 
	return 0;
}
