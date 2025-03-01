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
//WA����һЩСϸ�ڸ���� 
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
//	if(t==h) //��ֹ��ѭ�� 
//	{
//		count++;
//		return false;
//	} 
//	for(int i=h+1;i<=t;i++) //Ҫ��h+1��λ�ÿ�ʼ���� 
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

//��Ҫ��ʱ�̺ͳ˿͵Ĺ�����Ϣ��ϵ������ʱ���������ƶ��еĳ��ȣ���������ͳ���ж��ٲ�ͬ�Ĺ��ҡ�
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
		//��� 
		for(int i=1;i<=k;i++) 
		{
			int tmp; cin >> tmp;
			if(cnt[tmp]++ == 0) kind++;
			q.push({t,tmp});	
		}
		//����
		while(q.size() && q.back().first - q.front().first >= 86400)
		{
			if(cnt[q.front().second]-- == 1) kind--;
			q.pop();		
		} 
		cout << kind << endl; 	
	}
	
	
	return 0;
}









