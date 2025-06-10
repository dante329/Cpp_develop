#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std; 

const int N = 110, T = 1e5 + 10;

int f[N][T]; //dp表：f[i][j]表示处理完第i个垃圾之后，高度为j时的最大血量。 处理完第i个垃圾之后！！ 
int d,n; //垃圾井深度、垃圾的数量 
struct node
{
	int t,w,h; //扔下的时间、维持生命的时间、能垫高的高度 
}a[N];

bool cmp(node& a, node& b)
{
	return a.t < b.t;
}

int main() 
{
	cin >> d >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].t >> a[i].w >> a[i].h;	
	}	
	
	sort(a + 1, a + 1 + n, cmp); //排序哪个垃圾最先落下 
		
	f[0][0] = 10;
	
	for(int i=1;i<=n;i++)
	{	
		for(int j=0;j<=d;j++)
		{			
			if(f[i-1][j] >= a[i].t) //能拿到这个垃圾 
			{
				if(j + a[i].h >= d) //拿完就出去了，那就直接返回这个物品掉落的时间  
				{
					cout << a[i].t << endl;
					return 0;
				}
				
				//当前物品不能直接垫出去
				//记住：状态表示是处理完第i个物品！那么处理完会导致两种可能。而不是在1~i个物品中选择，第i个物品的状态是由两种可能性导致的 
				f[i][j] = max(f[i][j],f[i-1][j] + a[i].w); //吃掉第i个物品导致的状态
				f[i][j+a[i].h] = max(f[i][j+a[i].h],f[i-1][j]); //堆起来第i个物品导致的状态			 
			}
			
		}
	}
		
	int ret = 10;
	for(int i=1;i<=n;i++)
	{
		if(ret < a[i].t) break;
		else ret += a[i].w;
	}
	cout << ret << endl;
	
	
	return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std; 

const int N = 110, T = 1e5 + 10;

int f[N][T]; //dp表：f[i][j]表示处理完第i个垃圾之后，高度为j时的最大血量。 处理完第i个垃圾之后！！ 
int d,n; //垃圾井深度、垃圾的数量 
struct node
{
	int t,w,h; //扔下的时间、维持生命的时间、能垫高的高度 
}a[N];

bool cmp(node& a, node& b)
{
	return a.t < b.t;
}

int main() 
{
	cin >> d >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].t >> a[i].w >> a[i].h;	
	}	
	
	sort(a + 1, a + 1 + n, cmp); //排序哪个垃圾最先落下 
	
	memset(f, -0x3f, sizeof f); //负无穷表示无法到达的状态	
	f[0][0] = 10;
	
	for(int i=1;i<=n;i++)
	{
		int delta = a[i].t - a[i-1].t;
		
		for(int j=0;j<=d;j++)
		{
			if(f[i-1][j] < delta) continue; //撑不到垃圾来就死了
			 
			//能拿到垃圾 
			if(j + a[i].h >= d) //拿完就出去了，那就直接返回这个物品掉落的时间  
			{
				cout << a[i].t << endl;
				return 0;
			}
			
			//当前物品不能直接垫出去
			//记住：状态表示是处理完第i个物品！那么处理完会导致两种可能。而不是在1~i个物品中选择，第i个物品的状态是由两种可能性导致的 
			f[i][j] = max(f[i][j], f[i-1][j] - delta + a[i].w); //吃掉第i个物品导致的状态
			f[i][j+a[i].h] = max(f[i][j+a[i].h], f[i-1][j] - delta); //堆起来第i个物品导致的状态			 
			
		}
	}
		
	int ret = 10;
	for(int i=1;i<=n;i++)
	{
		if(ret < a[i].t) break;
		else ret += a[i].w;
	}
	cout << ret << endl;
	
	
	return 0;
}
