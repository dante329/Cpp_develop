//vector数组存储树的 DFS 
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//vector<int> edges[N]; //存储树 
//int n;
//
//bool st[N]; //用来标记结点是否已经被遍历过了 
//
//void dfs(int x)
//{
//	cout << x << " ";
//	st[x] = true; //告诉全局的dfs这个点已经访问过了 
//	for(auto v:edges[x])
//	{
//		if(!st[v]) dfs(v);
//	}
//}
//
//
//int main() 
//{
//	//建树 
//	cin >> n; //给出n个节点 
//	for(int i=1;i<n;i++) //读入n-1条边 
//	{
//		//a和b之间有一条边 
//		int a,b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);
//	}
//	
//	//深度优先遍历 
//	dfs(1); //假设1为根节点，以1为根dfs遍历 
//	
//	return 0;
//}

//链式前向星存储树的 DFS 
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int id,e[N*2],ne[N*2],h[N];//存储树 
int n;

bool st[N]; //用来标记结点是否已经被遍历过了 

void dfs(int x)
{
	cout << x << " ";
	st[x] = true;
	for(int i = h[x];i;i=ne[i])
	{
		int v = e[i]; //孩子 
		if(!st[v]) 
		{
//			cout << v << " ";
			dfs(v); 
		}
	}
}

void add(int x,int y) //这个add函数就是头插
{
	id++;
	e[id] = y;
	ne[id] = h[x];
	h[x] = id;
} 

int main() 
{
	//建树  //将a的子节点b头插到a的链表中 
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int a,b; cin >> a >> b;
		add(a,b); add(b,a);
	}
	//深度优先遍历
	dfs(1); //还是假设1为根 
	
	
	return 0;
}



