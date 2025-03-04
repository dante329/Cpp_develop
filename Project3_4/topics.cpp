//P1305
//#include <iostream>
//using namespace std;
////��������ʽ�洢�������ҽ�㣩
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
////	cin >> root >> l[root] >> r[root]; cin���Կո�Ϊ�ָ��� 
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
//	if(l1>r1) return; //��������һ���������������������s1���ͺ��������s2���еĽڵ�����һ���ġ�
//					  //Ҳ����˵������ [l1, r1] �ĳ��Ⱥ� [l2, r2] �ĳ�������ͬ�ġ�
//					  //��ˣ�����������Ϊ�գ��� l1 > r1��ʱ����Ӧ�ĺ�������Ҳ��ȻΪ�գ��� l2 > r2����
//					  //����ֻ�������һ�������Ƿ�Ϊ�վ��㹻�ˡ�
//
//	char root = s2[r2];
//	cout << root;
//	int p = l1;
//	while(s1[p] != root) p++; //�������������Ѱ�Ҹ��ڵ��λ�ã��Դ�Ϊ���޷ָ������������� 
//	int len1 = p - l1; //int len2 = r1 - p;
//	//s1�����������������(l1,p-1)(p+1,r1)
//	//s2�����������������(l2,l2+len1-1)(l2+len1,r2-1)
//	//���������������ظ���ͬ�����⣬Ȼ�����������Ҳ�� 
//	dfs(l1,p-1,l2,l2+len1-1); //�ȱ���������
//	dfs(p+1,r1,l2+len1,r2-1); //�ٱ��������� 
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
//	//����a��Ϊ������������(l1,p-1)(p+1,r1)
//	//ǰ��b��Ϊ������������(l2+1,l2+p-l1)(l2+p-l1,r2)
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
//˼·���ˣ���Ŀû��˵��˭����ڵ�˭���ҽڵ㣬�Ͳ�Ӧ����l��r�洢�ڵ㣬ʹ��˳��洢������ʽǰ���� 
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
vector<int> edges[N]; //edges[N]���߼��ǽ��ӽڵ�洢����Ӧ�ĸ��ڵ������� ���൱�ڵõ��˴洢ÿ�����ڵ�������ӽڵ������ 
//����������Ҫ���¶���ȥ̽�������ڵ㣬Ȼ���¼ÿ���ڵ��������ľ��룬��ʱ�����Ҫһ����¼���ڵ������������������ϱ��������һ��ǰ�һ��dis����洢���� 
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
	//���������ѭ������ʱ��y�ߵ����ཻ�ĵط� 
	return dis[y] * 2 + len;
}

int dfs(int u)
{
	if(u == 0) return 0;
	int ret = 0;
	for(int v:edges[u]) //����u�������ӽڵ�v����˭�ĸ߶ȸߣ��ڱ����Ĺ����У�retʼ����Ч�ڼ�¼��ֻ�г��������������û���� 
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
//		int size = q.size(); //��size�������ȼ����и��ô�������֪���˴�С֮�����ָ��һ����ѭ�������������е�����Ԫ�أ����ҽ����ǵ��ӽڵ�ȫ����ӽ��������������߼� 
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






