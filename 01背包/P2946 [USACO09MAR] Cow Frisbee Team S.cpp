//正解，虽然在取模上难理解一点，但是我觉得在初始化逻辑上更胜一筹，更具有逻辑性 
#include<iostream>

using namespace std;

const int N = 2010, M = 1010, MOD = 1e8; 

int a[N]; //f[i][j]表示在1~i个奶牛中，选出的奶牛的总能力模m后为j的，总方案数 
int f[N][M];
int n,m;

int main()
{ 
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	f[0][0] = 1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++) //j取不到m 
		{
			f[i][j] = (f[i-1][j] + f[i-1][((j-a[i]%m)%m+m)%m]) % MOD;			
		}
	}	
	
	cout << f[n][0] - 1 << endl; //排除f[0][0] 奶牛队伍中奶牛数量>=1 
	
	return 0;
}


//洛谷题解，与我的初始化方式不同 
#include<iostream>

using namespace std;

const int N = 2010, M = 1010, MOD = 1e8; 

int a[N]; //f[i][j]表示在1~i个奶牛中，选出的奶牛的总能力模m后为j的，总方案数 
int f[N][M];
int n,m;

int main()
{ 
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) 
	{
		int x; cin >> x;
		a[i] = x % m;
		f[i][a[i]] = 1; // 初始化：单独选第 i 头奶牛，余数为 R[i] 的方案数是 1。这些格子里的数起码是1 
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++) //j取不到m 
		{
			f[i][j] = (f[i-1][j] + f[i][j] + f[i-1][(j-a[i]+m)%m]) % MOD; //要加上原来的f[i][j]，利用初始化的值展开		
		}
	}	
	
	cout << f[n][0] << endl;
	
	return 0;
}
