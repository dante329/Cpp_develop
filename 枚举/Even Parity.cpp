#include<iostream>
#include<cstring>
using namespace std;

const int N = 20;
int n;
int a[N];
int t[N];

int calc(int x,int y)
{
	int cnt = 0;
	for(int i=0;i<=n;i++)
	{
		//(x & (1<<i) == 1) 只有在 i=0 时才有意义，因为 1<<0 是 1。对于 i>0，1<<i 是 2, 4, 8, ...，所以 (x & (1<<i) == 1) 永远不会为真（除非 i=0）
		//比如 10010011 & 00010000 结果为 00010000
//		if((x & (1<<i) == 0) && (y & (1<<i) == 1)) cnt++;
//		if((x & (1<<i) == 1) && (y & (1<<i) == 0)) return -1;
    	//如果你想检查第 i 位是否为 1，应该使用以下写法：
		if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1) cnt++;
 		if(((x >> i) & 1) == 1 && ((y >> i) & 1) == 0) return -1;
	}
	return cnt;
}

int solve()
{
		int ret = 0x3f3f3f3f;			 
		for(int st=0;st<=(1<<n)-1;st++) //枚举n位合法二进制，枚举的每个二进制用st表示 
		{
			memcpy(t,a,sizeof a); //拷贝到t中处理
			int	change = st;
			int cnt = 0;
			bool flag = 1;
			for(int i=1;i<=n;i++)
			{
				//先判断change对于t[i]是否合法 
				int c = calc(t[i],change);
				if(c == -1)
				{
					flag = 0;
					break; 
				}
				cnt += c;
				//对t[i]进行改变
				t[i] = change;
				change = t[i-1] ^ (t[i]<<1) ^ (t[i]>>1);
				change &= (1<<n) - 1;
			}
			if(flag) ret = min(ret,cnt);
		}
		if(ret == 0x3f3f3f3f) ret = -1;
		return ret;
 } 

int main()
{
	int T; cin >> T;
	for(int k=1;k<=T;k++)
	{
		memset(a,0,sizeof a);
		//读数据，存到a 
		cin >> n;
		for(int i=1;i<=n;i++) //a数组从下标1开始存，因为在进行操作时要用到上两行的数据 
		{
			for(int j=0;j<n;j++)
			{
				int x; cin >> x; 
				if(x == 1) a[i] |= (1 << j);
			}
		}  
			
		//处理数据 

		printf("Case %d: %d\n",k,solve());
	}	
	return 0;
} 
