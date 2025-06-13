//注意测试数据中的主件的编号是根据当前主件在第几行确定的，而不是按顺序1、2、3、4给出的。这一点题目中未说明 
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 70, M = 4e4 + 10;

int n,m;

int v[N][3], w[N][3]; //v[i][0]：主件 v[i][1]：附件1 v[i][2]：附件2 

int f[N][M];

int main()
{
	cin >> m >> n ;
	
	for(int i=1;i<=n;i++)
	{
		int a,p,q; cin >> a >> p >> q;
		if(q == 0)
		{
			v[i][0] = a;
			w[i][0] = a * p; 
		}
		else 
		{
//			if(v[q][0] == 0) continue; // 如果主件 q 不存在，跳过
			if(v[q][1] == 0) //v[i][1]是空的就填入
			{
				v[q][1] = a;
				w[q][1] = a * p;
			} 
			else //有附件1了就填入附件2 
			{
				v[q][2] = a;
				w[q][2] = a * p;
			}		
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			//不选 
			f[i][j] = f[i-1][j];
			
			//如果v[i][0]不是主件就跳过，优先考虑主件
			if(v[i][0] == 0) continue;
			
			//选主件 
			if(j >= v[i][0])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]]+w[i][0]);
			} 		 
			//主+附件1
			if(j >= v[i][0] + v[i][1])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]-v[i][1]]+w[i][0]+w[i][1]);
			}
			//主+附件2
			if(j >= v[i][0] + v[i][2])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]-v[i][2]]+w[i][0]+w[i][2]);
			}
			//主+附件1+附件2 
			if(j >= v[i][0] + v[i][1] + v[i][2])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]-v[i][1]-v[i][2]]+w[i][0]+w[i][1]+w[i][2]);
			}
		}
	}
	
	cout << f[n][m];
	return 0;
 } 



