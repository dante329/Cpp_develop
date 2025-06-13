//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//const int N = 70, M = 4e4 + 10;
//
//int n,m;
//
//int f[N][M];
//
//int cnt; //统计有多少个主件 
//int a[N]; //主件的价格 
//int ap[N]; //主件重要度
////vector<PII> b[N]; //附件的<价格，重要度>
//
//int b[N]; //主件附件合并后的价格 
//int bp[N];
//int pos;
//
//bool st[N]; //标记哪些主件没有附件 
//
////int main()
////{
////	cin >> m >> n;
////	
////	for(int i=1;i<=n;i++)
////	{
////		int v,p,q; cin >> v >> p >> q;
////		if(q == 0) 
////		{
////			a[++cnt] = v; 
////			ap[cnt] = p;
////		}
////		else a[q].push_back({v,p}); 
////	}	
////	
////	for(int i=1;i<=cnt;i++)
////	{
////		for(auto t:b[i])
////	}
////	
////	return 0;
//// } 
// 
//int main()
//{
//	cin >> m >> n;
//	
//	for(int i=1;i<=n;i++)
//	{
//		int v,p,q; cin >> v >> p >> q;
//		if(q == 0) 
//		{
//			a[++cnt] = v; 
//			ap[cnt] = p;
//		}
//		else 
//		{
//			b[++pos] = v + a[q];
//			bp[pos] = p + ap[q];
//			st[q] = true;
//		 } 
//	}	
//	
//	//将没有附件的主件追加到全部物品数组中 
//	for(int i=1;i<=cnt;i++)
//	{
//		if(!st[i])
//		{
//			b[++pos] = a[i];
//			bp[pos] = ap[i];
//		}
//	}
//	
//	for(int i=1;i<=pos;i++) 
//	{
////		cout << "cnt:" << cnt << endl;
////		cout << "pos:" << pos << endl;
//		cout << "b[i]:" << b[i] << " ";
//		cout << "bp[i]:" << bp[i] << " " << endl;
//	}
//	
//	for(int i=1;i<=pos;i++)
//	{
//		for(int j=0;j<=m;j++)
//		{
//			f[i][j] = f[i-1][j];
//			if(j >= b[i])
//			{
//				f[i][j] = max(f[i][j],f[i-1][j-b[i]] + b[i] * bp[i]);
//			}
//		}	
//	}
//	
////	for(int i=1;i<=pos;i++)
////	{
////		for(int j=0;j<=m;j++)
////		{
////			cout << f[i][j] << " ";
////		}	
////		cout << endl;
////	}
//	
//	cout << f[pos][m];
//	
//	return 0;
// } 
// 	

#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 70, M = 4e4 + 10;

int n,m;

int f[N][M];

int cnt; //统计有多少个主件 
int a[N]; //所有物品的价格 
int ap[N]; //所有物品重要度
vector<PII> b[N]; //附件的<价格，重要度> b[i]：i号主件的附件信息 

int main()
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		int v,p,q; cin >> v >> p >> q;

		if(q == 0)
		{
			a[++cnt] = v; 
			ap[cnt] = p;
		}		
		else b[q].push_back({v,p}); //如果q不等于0，存储附件信息，附件不能单独购买 
	}	
	
	for(int i=1;i<=cnt;i++)
	{
		int tmpv[2], tmpp[2], pos=0; 
		for(auto t:b[i])
		{
			int v = t.first, p = t.second;
			//买一个附件 
			a[++cnt] = v + a[i];
			ap[cnt] = p + ap[i]; 
			tmpv[++pos] = v, tmpp[pos] = p;
		}
		if(pos == 2) //如果有两个附件就要考虑两个都买 
		{
			a[++cnt] = tmpv[1] + tmpv[2] + a[i];
			ap[cnt] = tmpp[1] + tmpp[2] + ap[i];
		}
	}
	
//	for(int i=1;i<=cnt;i++) 
//	{
//		cout << "cnt:" << cnt << endl;
//		cout << "a[i]:" << a[i] << " ";
//		cout << "ap[i]:" << ap[i] << " " << endl;
//	}
	
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<=m;j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= a[i])
			{
				f[i][j] = max(f[i][j],f[i-1][j-a[i]] + a[i] * ap[i]);
			}
		}	
	}
	
	cout << f[cnt][m];
	
	return 0;
 } 
 
 					
