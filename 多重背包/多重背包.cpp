//多重背包模板 
#include <iostream>

using namespace std;

const int N = 110;

int x[N],w[N],v[N],f[N][N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> x[i] >> w[i] >> v[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			//先不选
			f[i][j] = f[i-1][j];
			//再枚举选1~k次
			for(int k=1;k<=x[i] && k*w[i]<=j;k++)
			{
				f[i][j] = max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			}
			//如果不进行空间优化，确实可以写成下面这样，k=0的时候就代表着“不选”这种情况，后面的1~kmax就代表选1~k次。
			//但是一但空间优化就错了，所以还是要将不选和选的情况分开来
			//for(int k=0;k<=x[i] && k*w[i]<=j;k++)
			//{
			//	  f[i][j] = max(f[i-1][j],f[i-1][j-k*w[i]]+k*v[i]);
			//}
		}
	}
	
	cout << f[m];
	
	return 0;
}
//空间优化
#include <iostream>

using namespace std;

const int N = 110;

int x[N],w[N],v[N],f[N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> x[i] >> w[i] >> v[i];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			for(int k=1;k<=x[i] && k*w[i]<=j;k++) //注意这里k是从1开始循环的
			{
				f[j] = max(f[j],f[j-k*w[i]]+k*v[i]);
			}
		}
	}
	
	cout << f[m];
	
	return 0;
}

//二进制优化
#include <iostream>

using namespace std;

const int N = 110 * 5; //pos的数量最大是原来物品数量的5倍 

int w[N],v[N],pos; //pos用来记录拆分后的物品的数量 
int f[N];
int n,m;
 
int main() 
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) 
	{
		int x,y,z; cin >> x >> y >> z;
		
		int t = 1;
		
		while(x >= t)
		{
			pos++;
			w[pos] = t * y;
			v[pos] = t * z;
			x -= t;
			t *= 2;  
		}
		if(x)
		{
			pos++;
			w[pos] = x * y;
			v[pos] = x * z;
		}	
	}
	
	//针对拆分之后的物品做一次01背包 
	for(int i=1;i<=pos;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			f[j] = max(f[j],f[j-w[i]] + v[i]);
		}
	}
	
	cout << f[m];
	
	return 0;
} 
