//B3616
//#include<iostream>
//using namespace std;
//
//const int N = 10010;
//int a[N],h,t;
//
//void push(int x)
//{
//	a[++t] = x;
//}
//
//void pop()
//{
//	h++;
//}
//
//int query()
//{
//	return a[h+1];
//}
//
//int size()
//{
//	return t-h;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	while(n--)
//	{
//		int op;
//		cin >> op;
//		switch(op)
//		{
//			case 1:
//				int x; cin >> x;
//				push(x);
//				break;
//			case 2:
//				if(size()) pop();
//				else cout << "ERR_CANNOT_POP" << endl;
//				break;
//			case 3:
//				if(size()) cout << query() << endl;	
//				else cout << "ERR_CANNOT_QUERY" << endl;					
//				break;
//			case 4:
//				cout << size() << endl;
//				break;
//		}
//	}	
//	return 0;
//}

//P1540
//WA，有一些小细节搞错了 
//#include<iostream> 
//using namespace std;
//
//const int N = 1010; 
//
//int me[N],h,t;
//
//int count; 
//
//bool search(int x)
//{
//	for(int i=h;i<=t;i++)
//	{
//		if(me[i] == x) return true;
//	}
//	count++;
//	return false;
//}
//
//int main()
//{
//	int m,n;
//	cin >> m >> n;
//	int tmp;
//	while(n--)
//	{
//		cin >> tmp;
//		if(search(tmp)) continue;
//		else
//		{
//			me[++t] = tmp;
//			if(t-h>m) h++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//#include<iostream> 
//using namespace std;
//
//const int N = 1010; 
//
//int me[N],h,t;
//
//int count; 
//
//bool search(int x)
//{
//	if(t==h) //防止死循环 
//	{
//		count++;
//		return false;
//	} 
//	for(int i=h+1;i<=t;i++) //要从h+1的位置开始遍历 
//	{
//		if(me[i] == x) return true;
//	}
//	count++;
//	return false;
//}
//
//int main()
//{
//	int m,n;
//	cin >> m >> n;
//	int tmp;
//	while(n--)
//	{
//		cin >> tmp;
//		if(search(tmp)) continue;
//		else
//		{
//			me[++t] = tmp;
//			if(t-h>m) h++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

#include<iostream> 
#include<queue>
using namespace std;

//需要将时刻和乘客的国籍信息联系起来，时刻用来控制队列的长度，国籍用来统计有多少不同的国家】
typedef pair<int,int> PII;
queue<PII> q;
 
const int N = 1e5 + 10;
int cnt[N],kind;
 
int main()
{
	int n; cin >> n;
	while(n--)
	{
		int t,k;
		cin >> t >> k;
		//入队 
		for(int i=1;i<=k;i++) 
		{
			int tmp; cin >> tmp;
			if(cnt[tmp]++ == 0) kind++;
			q.push({t,tmp});	
		}
		//出队
		while(q.size() && q.back().first - q.front().first >= 86400)
		{
			if(cnt[q.front().second]-- == 1) kind--;
			q.pop();		
		} 
		cout << kind << endl; 	
	}
	
	
	return 0;
}









