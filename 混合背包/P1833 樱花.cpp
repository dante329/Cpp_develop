//原始版本，但是会MLE 
#include <iostream>

using namespace std; 

const int N = 1e4 + 10;

int t[N],c[N],p[N];
int f[N][N]; //f[i][j]表示在1~i个樱花树中选，总时间不超过j，能得到的最大美学值 
int n,m;

int main()
{
	char ch1,ch2;
	int h1,m1,h2,m2; cin >> h1 >> ch1 >> m1 >> h2 >> ch2 >> m2 >> n;
	m = h2 * 60 + m2 - (h1 * 60 + m1);
	
	for(int i=1;i<=n;i++) cin >> t[i] >> c[i] >> p[i];
	
	for(int i=1;i<=n;i++)
	{		
		if(p[i] == 1)
		{
			for(int j=0;j<=m;j++)
			{
				//不选 
				f[i][j] = f[i-1][j];
				//选 
				if(j >= t[i]) f[i][j] = max(f[i-1][j], f[i-1][j-t[i]] + c[i]);
			}
		}
		else if(p[i] == 0)
		{
			for(int j=0;j<=m;j++)
			{
				//不选 
				f[i][j] = f[i-1][j];
				//选 
				if(j >= t[i]) f[i][j] = max(f[i-1][j], f[i][j-t[i]] + c[i]);
			}		
		}
		else 
		{
			for(int j=0;j<=m;j++)
			{
				//不选 
				f[i][j] = f[i-1][j];
				//选 
				for(int k=1;k<=p[i] && k*t[i]<=j;k++)
				{
					f[i][j] = max(f[i][j],f[i-1][j-k*t[i]] + k*c[i]);
				}
			}	
		}
	}

	cout << f[n][m] << endl;
	
	return 0;
}

//空间优化 
#include <iostream>

using namespace std; 

const int N = 1e4 + 10;

int t[N],c[N],p[N];
int f[N]; 
int n,m;

int main()
{
	char ch;
	int h1,m1,h2,m2; cin >> h1 >> ch >> m1 >> h2 >> ch >> m2 >> n;
	m = h2 * 60 + m2 - (h1 * 60 + m1);
	
	for(int i=1;i<=n;i++) cin >> t[i] >> c[i] >> p[i];
	
	for(int i=1;i<=n;i++)
	{		
		if(p[i] == 1) //01背包 
		{
			for(int j=m;j>=t[i];j--)
			{
				f[j] = max(f[j], f[j-t[i]] + c[i]);
			}
		}
		else if(p[i] == 0) //完全背包 
		{
			for(int j=t[i];j<=m;j++)
			{
				f[j] = max(f[j], f[j-t[i]] + c[i]);
			}		
		}
		else //多重背包 
		{
			for(int j=m;j>=t[i];j--)
			{
				for(int k=1;k<=p[i] && k*t[i]<=j;k++)
				{
					f[j] = max(f[j],f[j-k*t[i]] + k*c[i]);
				}
			}	
		}
	}

	cout << f[m] << endl;
	
	return 0;
}

//实际上多重背包k=1时就是01背包，所以它们俩可以写到一起去 
//#include <iostream>
//
//using namespace std; 
//
//const int N = 1e4 + 10;
//
//int t[N],c[N],p[N];
//int f[N]; 
//int n,m;
//
//int main()
//{
//	char ch;
//	int h1,m1,h2,m2; cin >> h1 >> ch >> m1 >> h2 >> ch >> m2 >> n;
//	m = h2 * 60 + m2 - (h1 * 60 + m1);
//	
//	for(int i=1;i<=n;i++) cin >> t[i] >> c[i] >> p[i];
//	
//	for(int i=1;i<=n;i++)
//	{		
//		if(p[i] == 0) //完全背包 
//		{
//			for(int j=t[i];j<=m;j++)
//			{
//				f[j] = max(f[j], f[j-t[i]] + c[i]);
//			}		
//		}
//		else //多重背包 或者 01背包  
//		{
//			for(int j=m;j>=t[i];j--)
//			{
//				for(int k=1;k<=p[i] && k*t[i]<=j;k++)
//				{
//					f[j] = max(f[j],f[j-k*t[i]] + k*c[i]);
//				}
//			}	
//		}
//	}
//
//	cout << f[m] << endl;
//	
//	return 0;
//}
