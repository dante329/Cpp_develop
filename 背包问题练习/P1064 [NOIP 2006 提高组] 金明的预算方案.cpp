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
//int cnt; //ͳ���ж��ٸ����� 
//int a[N]; //�����ļ۸� 
//int ap[N]; //������Ҫ��
////vector<PII> b[N]; //������<�۸���Ҫ��>
//
//int b[N]; //���������ϲ���ļ۸� 
//int bp[N];
//int pos;
//
//bool st[N]; //�����Щ����û�и��� 
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
//	//��û�и���������׷�ӵ�ȫ����Ʒ������ 
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

int cnt; //ͳ���ж��ٸ����� 
int a[N]; //������Ʒ�ļ۸� 
int ap[N]; //������Ʒ��Ҫ��
vector<PII> b[N]; //������<�۸���Ҫ��> b[i]��i�������ĸ�����Ϣ 

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
		else b[q].push_back({v,p}); //���q������0���洢������Ϣ���������ܵ������� 
	}	
	
	for(int i=1;i<=cnt;i++)
	{
		int tmpv[2], tmpp[2], pos=0; 
		for(auto t:b[i])
		{
			int v = t.first, p = t.second;
			//��һ������ 
			a[++cnt] = v + a[i];
			ap[cnt] = p + ap[i]; 
			tmpv[++pos] = v, tmpp[pos] = p;
		}
		if(pos == 2) //���������������Ҫ������������ 
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
 
 					
