//1

//#include<iostream>
//#include<stdio.h>
//#include<vector>
//using namespace std;
//
//int n,m;
//
//int main()
//{
//	cin >> n >> m;
//	vector<int> a1(n);
//	vector<int> a2(m);
//	for(int i=0;i<n;++i)
//	{
//		scanf("%d",&a1[i]);
//	}
//	for(int i=0;i<m;++i)
//	{
//		scanf("%d",&a2[i]);
//		printf("%d\n",a1[a2[i]-1]);
//	}
//	return 0;
//}

//2
//2.1 固定了柜子的数量，浪费了较多空间，可以根据n的大小来约束二维数组的大小 
//#include<iostream>
//#include<vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//
//vector<int> a[N];
//
//int n,q;
//
//int op,i,j,k;
//
//int main()
//{
//	cin >> n >> q;
//	while(q--)
//	{
//		cin >> op >> i >> j;
//		if(op==1)
//		{
//			if(a[i].size() <= j)
//			{
//				a[i].resize(j+1);				
//			}
//			cin >> k;
//			a[i][j] = k;
//		}
//		else
//		{
//			cout << a[i][j] << endl;
//		}
//	}
//	
//	return 0;
//}

//2.2
#include<iostream>
#include<vector>
using namespace std; 

vector<vector<int>> lockers; //2.1  vector<int> a[N];
//2.1是通过N来创建二维数组的，我们这里可以先创建一个空的，再根据题目给出的n来resize 

int main()
{
	int n,q; 
	cin >> n >> q;
	lockers.resize(n+1); //可以从1开始存储
	while(q--) //n次询问逻辑一样 
	{
		int op,i,j,k;
		cin >> op >> i >> j;
		if(op==1)
		{
			if(lockers[i].size() <= j)
			{
				lockers[i].resize(j+1);				
			}
			cin >> k;
			lockers[i][j] = k;
		}
		else
		{
			cout << lockers[i][j] << endl;
		}
	 } 
	
	retrun 0;
 } 

