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
//int ne[N]; //因为这整个输入的数据都是从一到N连续的正整数，所以我们没必要创建e数组去保存数据 
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
//	ne[n] = 1; //到尾巴后循环到下标为1的节点，我们全程忽略了0节点 
//	
//	int count = 0;
//	
//	//错误想法：这样的循环永远停不下来，因为我们数到第m个节点，删除这个节点是伪删除 //正确思考方向：考虑删除的逻辑到底是什么，在什么情况下删除会出bug，考虑特殊情况分类讨论！！！
//	for(int i=1;i;i=ne[i]) 
//	{
//		count++;
//		if(count == m-1)
//		{
//			if(ne[i] == ne[ne[i]]) //就剩下一个节点 
//			{
//				cout << i << " "; 
//				break;			
//			}
//			
//			cout << ne[i] << " ";
//			ne[i] = ne[ne[i]]; //这是删除逻辑，跳过下一个节点，只剩下两个节点时执行这个逻辑不会出错，会减少成一个节点。但是一个节点执行这个逻辑不会减少成0个节点，无法跳出for循环的限制，所以要去处理这种特殊情况。 
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

