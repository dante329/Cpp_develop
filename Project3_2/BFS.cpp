//vector存储树 
//#include<iostream>
//#include<vector>
//#include<queue> 
//using namespace std;
//
//const int N = 1e5 + 10;
//vector<int> edges[N]; 
//bool st[N];
//queue<int> q;  //队列的定义可以放到bfs函数内，因为在其他全局的地方用不上这个队列，仅仅是bfs的实现需要队列 
//int n;
// 
//void bfs()
//{
//	//这一部分是针对根节点的入队和标记操作 
//	q.push(1); //这个1也可以作为参数传入bfs 
//	st[1] = true;
//	
//	while(q.size()) //这有一个外层循环，当队列还有元素的时候就会一直执行 
//	{
//		int t = q.front(); q.pop();
//		cout << t << " ";
//		
//		for(auto v:edges[t]) //实际上遍历t的结点不只是t的子结点，因为我们是针对无根树进行的存储，这里还会遍历到t的父结点，所以标记已经入队的结点相当重要，不然就会陷入死循环 
//		{
//			if(!st[v])
//			{
//				q.push(v); //只要入队，就要在st中标记这个结点 
//				st[v] = true;
//			}	
//		} 
//	}
//}
// 
//int main()
//{
//	cin >> n; 
//	for(int i=1;i<n;i++)
//	{
//		int a,b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);   
//	}
//	bfs();
//	return 0;
//}

//链式前向星 DFS
#include<iostream>
#include<queue>
using namespace std;

const int N = 1e5 + 10;
int id,h[N],e[N*2],ne[N*2];
int n;
bool st[N];

void add(int a, int b)
{
	id++;
	e[id] = b;
	ne[id] = h[a];
	h[a] = id;
}

void bfs()
{
	queue<int> q;
	q.push(1);
	st[1] = true;
	while(q.size())
	{
		int t = q.front(); q.pop();
		cout << t << " ";
		for(int i=h[t];i;i=ne[i])
		{
			if(!st[e[i]])
			{
				q.push(e[i]);
				st[e[i]] = true;
			} 
		}
	}
}

int main()
{
	//建树 
    cin >> n;
    for(int i=1;i<n;i++)
    {
    	int a,b; cin >> a >> b;
    	add(a,b); add(b,a);
	}
	//BFS遍历 
	bfs();
	return 0;
}

 
