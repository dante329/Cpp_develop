//P1305
//#include <iostream>
//using namespace std;
////二叉树链式存储（存左右结点）
//const int N = 300;
//char l[N],r[N];
//char root;
//int n;
//
//void dfs(char root)
//{
//	cout << root;
//	if(l[root] != '*') dfs(l[root]);
//	if(r[root] != '*') dfs(r[root]);
//}
//
////void dfs(char root)
////{
////	if(root == '*') return;
////	cout << root;
////	dfs(l[root]);
////	dfs(r[root]);
////}
//
//int main() 
//{
//	cin >> n;
//	cin >> root;
//	cin >> l[root] >> r[root];
////	cin >> root >> l[root] >> r[root]; cin是以空格为分隔符 
//	for(int i=2;i<=n;i++)
//	{
//		char t; cin >> t;
//		cin >> l[t] >> r[t];
//	}
//	dfs(root);
//	return 0;
//}

//B3642
//#include<iostream>
//using namespace std;
//const int N = 1e6 + 10;
//int l[N],r[N],n;
//
//void dfs1(int u)
//{
//	if(u == 0) return;
//	cout << u << " ";
//	dfs1(l[u]);
//	dfs1(r[u]);
//}
//
//void dfs2(int u)
//{
//	if(u == 0) return;
//	
//	dfs2(l[u]);
//	cout << u << " ";
//	dfs2(r[u]);
//}
//
//void dfs3(int u)
//{
//	if(u == 0) return;
//	
//	dfs3(l[u]);
//	dfs3(r[u]);
//	cout << u << " ";
//}
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<=n;i++)
//	{
//		cin >> l[i] >> r[i]; 
//	}
//	dfs1(1);
//	cout << endl; 
//	dfs2(1);
//	cout << endl; 
//	dfs3(1);
//	cout << endl; 
//	return 0;
//}

//P4913 
//TLE
//#include<iostream>
//using namespace std;
//const int N = 1e6+10;
//int n,l[N],r[N];
//
//int size(int u)
//{
//	if(u == 0) return 0;
//	return size(l[u]) > size(r[u]) ? size(l[u])+1:size(r[u])+1;
//}
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<n;i++)
//	{
//		cin >> l[i] >> r[i];	
//	}	
//	cout << size(1);
//	return 0;
//} 

//#include<iostream>
//using namespace std;
//const int N = 1e6+10;
//int n,l[N],r[N];
//
//int size(int u)
//{
//	if(u == 0) return 0;
//	return max(size(l[u]),size(r[u])) + 1;
//}
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<n;i++)
//	{
//		cin >> l[i] >> r[i];	
//	}	
//	cout << size(1);
//	return 0;
//} 

//P1030
//#include<iostream>
//#include<string>
//using namespace std;
//string s1,s2;
//
//void dfs(int l1,int r1,int l2,int r2)
//{
//	if(l1>r1) return; //对于任意一棵子树，其在中序遍历（s1）和后序遍历（s2）中的节点数是一样的。
//					  //也就是说，区间 [l1, r1] 的长度和 [l2, r2] 的长度是相同的。
//					  //因此，当中序区间为空（即 l1 > r1）时，对应的后序区间也必然为空（即 l2 > r2），
//					  //所以只检测其中一个区间是否为空就足够了。
//
//	char root = s2[r2];
//	cout << root;
//	int p = l1;
//	while(s1[p] != root) p++; //再中序的序列中寻找根节点的位置，以此为界限分割左右子树区间 
//	int len1 = p - l1; //int len2 = r1 - p;
//	//s1中序的左右子树区间(l1,p-1)(p+1,r1)
//	//s2后序的左右子树区间(l2,l2+len1-1)(l2+len1,r2-1)
//	//对于左子树可以重复相同子问题，然后对于右子树也是 
//	dfs(l1,p-1,l2,l2+len1-1); //先遍历左子树
//	dfs(p+1,r1,l2+len1,r2-1); //再遍历右子树 
//}
//
//int main()
//{
//	cin >> s1 >> s2;
//	dfs(0,s1.size()-1,0,s2.size()-1);	
//	return 0;
// } 

//P1827
//#include<iostream>
//using namespace std;
//const int N = 100;
//int l[N],r[N];
//string a,b;
//
//void dfs(int l1,int r1,int l2,int r2)
//{
//	if(l1>r1) return;
//	char root = b[l2];
//	int p = l1;
//	while(a[p] != root) p++;
//	//中序a分为左右子树区间(l1,p-1)(p+1,r1)
//	//前序b分为左右子树区间(l2+1,l2+p-l1)(l2+p-l1,r2)
//	dfs(l1,p-1,l2+1,l2+p-l1);
//	dfs(p+1,r1,l2+p-l1+1,r2);
//	cout << root;
//}
//
//int main()
//{
//	cin >> a >> b;
//	dfs(0,a.size()-1,0,b.size()-1);
//	return 0;
//}

//P3884
//思路错了，题目没有说明谁是左节点谁是右节点，就不应该用l，r存储节点，使用顺序存储或者链式前向星 
//#include<iostream>
//
//using namespace std;
//
//const int N = 110;
//int n,l[N],r[N];
//
//int dfs(int u)
//{
//	if(u == 0) return 0;
//	return max(dfs(l[u]),dfs(r[u])) + 1;
//}
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<n;i++)
//	{
//		int t; cin >> t;
//		if(!l[N]) cin >> l[t];
//		else cin >> r[t];
//	}
//	cout << dfs(1) << endl;
//	
//	return 0;
// } 

//AC 
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 110;
int n;
vector<int> edges[N]; //edges[N]的逻辑是将子节点存储到对应的父节点数组中 ，相当于得到了存储每个父节点的所有子节点的数组 
//我们现在想要自下而上去探索到根节点，然后记录每个节点与出发点的距离，这时候就需要一个记录父节点的数组来帮助完成向上遍历，并且还亚奥一个dis数组存储距离 
int fa[N]; //father
int dis[N]; //distance

int cal_dis(int x,int y)
{	
//	for(int i=x;i!=1;i=fa[i])
//	{
//		dis[fa[i]] = dis[i] + 1; 
//	}
	while(x != 1)
	{
		dis[fa[x]] = dis[x] + 1;
		x = fa[x];
	}
	int len = 0;
	while(y != 1 && dis[y] == 0)
	{
		len++;
		y = fa[y];
	}
	//当上面这个循环结束时，y走到了相交的地方 
	return dis[y] * 2 + len;
}

int dfs(int u)
{
	if(u == 0) return 0;
	int ret = 0;
	for(int v:edges[u]) //遍历u的所有子节点v，看谁的高度高，在遍历的过程中，ret始终有效在记录，只有出了这个函数它才没用了 
	{
		ret = max(dfs(v),ret);
		fa[v] = u;
	}
	return ret + 1;
}

int bfs()
{
	queue<int> q;
	q.push(1);
	int ret = 0;
	while(q.size())
	{
		int tmp = q.front(); q.pop();
		for(auto v:edges[tmp])
		{
			q.push(v);
		}
		int size = q.size();
		ret = max(ret,size);
	} 
	return ret;
}

//int bfs()
//{
//	queue<int> q;
//	q.push(1);
//	int ret = 0;
//	while(q.size())
//	{
//		int size = q.size(); //把size拿上来先计算有个好处，就是知道了大小之后可以指定一个内循环，弹出队列中的所有元素，并且将他们的子节点全部添加进来，这样更有逻辑 
//		ret = max(ret,size);
//		while(size--)
//		{
//			int tmp = q.front(); q.pop();
//			for(auto v:edges[tmp])
//			{
//				q.push(v);
//			}
//		}
//		
//	} 
//	return ret;
//}


int main()
{
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int a,b; cin >> a >> b;
		edges[a].push_back(b);
	}
	int x,y; cin >> x >> y;
	cout << dfs(1) << endl;
	cout << bfs() << endl;
	cout << cal_dis(x,y) << endl;
	return 0;
 } 






