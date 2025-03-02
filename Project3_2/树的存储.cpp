//vector数组 实现孩子表示法 （无根树/根未知） 
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//vector<int> edges[N];
//int n;
//
//int main() 
//{
//	cin >> n; //给出n个节点 
//	for(int i=1;i<n;i++) //读入n-1条边 
//	{
//		//a和b之间有一条边 
//		int a,b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);
//	}
//	return 0;
//}

//链式前向星 实现孩子表示法
//原则：当x有一个孩子y的时候，将y头插到x的链表中 
//#include <iostream>
//using namespace std;
//
//const int N = 1e5 + 10;
//int h[N],e[N*2],ne[N*2],id; //h数组中的第i位用来充当以i为首的链表的的头节点 ，e用来存放数据，ne用来存放孩子信息，相当于是很多个链表存储在了同一个数组中 
//
//int n;
//
//void push_front(int x,int y)
//{
//	id++;
//	e[id] = y;
//	ne[id] = h[x];
//	h[x] = id; 
//}
//
//int main() 
//{
//	cin >> n; //给出n个节点 
//	for(int i=1;i<n;i++)
//	{
//		int a,b; cin >> a >> b; //题目给出一组a和b，代表着a和b之间有一条边，但是不知道谁是谁的父亲节点，有两种可能，a是b的父节点，b是a的父节点，所以都要分别添加到他们自己的链表中
//		push_front(a,b);
//		push_front(b,a);
//	}
//	return 0;
//} 




