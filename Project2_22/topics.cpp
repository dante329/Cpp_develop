//B3630
//#include<iostream>
//using namespace std;
//const int N = 1e6 + 10;
//
//int ne[N],h;
//
//int main()
//{
//	int n;
//	cin >> n;
//	for(int i = 1;i<=n;i++)
//	{
//		cin >> ne[i];
//	}
//	cin >> h;
//	for(int i = h;i;i = ne[i])
//	{
//		cout << i << " ";
//	}
//	
//	return 0;
//}

//B3631
//#include<iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//const int M = 1e6 + 10; 
//
//int e[N],ne[N],mp[M];
//
//int id = 1;
//
//int find(int x)
//{
//	return mp[x];
//}
//
//void insert(int p,int y)
//{
//	id++;
//	e[id] = y;
//	ne[id] = ne[p];
//	ne[p] = id;
//	mp[y] = id;
//}
//
//void erase_back(int p)
//{
//	ne[p] = ne[ne[p]];
//}
//
////void print()
////{
////	for(int i=1;i;i=ne[i])
////	{
////		cout << e[i] << " ";
////	}
////	cout << endl;
////}
//
//int main()
//{
//	e[1] = 1;
//	mp[1] = 1;
//	int q,x;
//	cin >> q;
//	while(q--)
//	{
//		int op;
//		cin >> op;
//		if(op == 1)
//		{
//			int y;
//			cin >> x >> y;
//			insert(find(x),y);
////			print();
//		}
//		else if(op == 2)
//		{
//			cin >> x;
//			cout << e[ne[find(x)]] << endl;
////			print();
//		}
//		else
//		{
//			cin >> x; 
//			erase_back(find(x));
////			print();
//		}
//	}
//	return 0;
//}

//P1160
//#include<iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int e[N], pre[N], ne[N], h, mp[N], id;
//
//
//int find(int x)
//{
//	return mp[x];
//}
//
//void insert_front(int p, int x)
//{
//	id++;
//	e[id] = x;
//	mp[x] = id;
//
//	ne[id] = p;
//	pre[id] = pre[p];
//
//	ne[pre[p]] = id;
//	pre[p] = id;
//}
//
//void insert_back(int p, int x)
//{
//	id++;
//	e[id] = x;
//	mp[x] = id;
//
//	ne[id] = ne[p];
//	pre[id] = p;
//
//	pre[ne[p]] = id;
//	ne[p] = id;
//}
//
//void erase(int p)
//{
//	if (p == 0) return;
//	else if (ne[p] == 0) ne[pre[p]] = ne[p]; mp[e[p]] = 0;
//	ne[pre[p]] = ne[p];
//	pre[ne[p]] = pre[p];
//	mp[e[p]] = 0;
//}
//
//void print()
//{
//	for (int i = ne[h]; i; i = ne[i])
//	{
//		cout << e[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int n, k, p;
//	cin >> n;
//	id++;
//	e[id] = 1;
//
//	pre[id] = h;
//	ne[id] = ne[h];
//
//	ne[h] = id;
//
//	mp[1] = 1;
//	n--;
//	int count = 1;
//	while (n--)
//	{
//		count++;
//		cin >> k >> p;
//		if (p == 0) insert_front(find(k), count);
//		else insert_back(find(k), count);
//	}
//	int m, x;
//	cin >> m;
//	while (m--)
//	{
//		cin >> x;
//		erase(find(x));
//	}
//	print();
//	return 0;
//}
//	


//P1996
//WA 
//#include<iostream>
//#include<list>
//using namespace std;
//
//int main()
//{
//	int m, n;
//	cin >> n >> m;
//	list<int> l;
//	for (int i = 1; i <= n; i++)
//	{
//		l.push_back(i);
//	}
//	int count = 0;
//	for (auto i = l.begin(); i != l.end(); )
//	{
//		if (l.empty()) break;
//		count++;
//		if (count == 3)
//		{
//			cout << *i << " ";
//			l.erase(i);
//			count = 0;
//			continue;
//		}
//		if (i == --l.end())
//		{
//			i = l.begin();
//			continue;
//		}
//		i++;
//	}
//	
//	return 0;
//}

//AC
//#include<iostream>
//#include<list>
//using namespace std;
//
//const int N = 110; 
//
//int ne[N]; //��Ϊ��������������ݶ��Ǵ�һ��N����������������������û��Ҫ����e����ȥ�������� 
//
//
//int main()
//{
//	int n,m;
//	cin >> n >> m;
//	for(int i=1;i<=n;i++)
//	{
//		ne[i] = i+1;
//	}
//	ne[n] = 1; //��β�ͺ�ѭ�����±�Ϊ1�Ľڵ㣬����ȫ�̺�����0�ڵ� 
//	
//	int count = 0;
//	
//	//�����뷨��������ѭ����Զͣ����������Ϊ����������m���ڵ㣬ɾ������ڵ���αɾ�� //��ȷ˼�����򣺿���ɾ�����߼�������ʲô����ʲô�����ɾ�����bug��������������������ۣ�����
//	for(int i=1;i;i=ne[i]) 
//	{
//		count++;
//		if(count == m-1)
//		{
//			if(ne[i] == ne[ne[i]]) //��ʣ��һ���ڵ� 
//			{
//				cout << i << " "; 
//				break;			
//			}
//			
//			cout << ne[i] << " ";
//			ne[i] = ne[ne[i]]; //����ɾ���߼���������һ���ڵ㣬ֻʣ�������ڵ�ʱִ������߼������������ٳ�һ���ڵ㡣����һ���ڵ�ִ������߼�������ٳ�0���ڵ㣬�޷�����forѭ�������ƣ�����Ҫȥ����������������� 
//			count = 0;
//		}
//		
//	}
//	return 0;
//}

#include <iostream>
using namespace std;

const int N = 110;

int n, m;

int ne[N];

int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		ne[i] = i+1;
	}
	ne[n] = 1;
	
	int t = n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			t = ne[t];
		}
		cout << ne[t] << " ";
		ne[t] = ne[ne[t]];
	}
	return 0;
}

