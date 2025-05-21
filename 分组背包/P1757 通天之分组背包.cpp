#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1010;

vector<PII> g[N];
int f[N][N]; //f[i][j]表示：在1~n组物品中选，重量不超过j，最大价值 
int n,m,cnt; //cnt用来记录有多少组物品 

int main() 
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		int a,b,c; cin >> a >> b >> c;
		cnt = max(cnt,c); 
		g[c].push_back({a,b}); 
	}
	
	for(int i=1;i<=cnt;i++) //循环组数 
	{
		for(int j=m;j>=0;j--)
		{
			//必须要先考虑不选的情况然后给f[i][j]赋值，以为有可能j<a根本进不去判断 
			f[i][j] = f[i-1][j];
			for(auto& t:g[i])
			{
				int a = t.first, b = t.second;
				if(j >= a)
				{
					f[i][j] = max(f[i][j],f[i-1][j-a]+b);
				}
			}
		}
	}
	
	cout << f[cnt][m];
	
	return 0;
}

//空间优化
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1010;

vector<PII> g[N];
int f[N]; //f[i][j]表示：在1~n组物品中选，重量不超过j，最大价值 
int n,m,cnt; //cnt用来记录有多少组物品 

int main() 
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		int a,b,c; cin >> a >> b >> c;
		cnt = max(cnt,c); 
		g[c].push_back({a,b}); 
	}
	
	for(int i=1;i<=cnt;i++) //循环组数 
	{
		for(int j=m;j>=0;j--)
		{
			for(auto& t:g[i])
			{
				int a = t.first, b = t.second;
				if(j >= a)
				{
					f[j] = max(f[j],f[j-a]+b);
				}
			}
		}
	}
	
	cout << f[m];
	
	return 0;
} 
