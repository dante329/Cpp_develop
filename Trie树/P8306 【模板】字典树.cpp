#include <iostream>
#include <cstring>
using namespace std;
const int N = 3e6 + 10;
int tree[N][62],p[N];
//int e[N]; 只求前缀不需要e数组 
int idx;

int get_num(char ch)
{
	if(ch >= 'a' && ch <= 'z') return ch - 'a';
	else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
	else return ch - '0' + 52;
}

//存储字符串到Trie树 
void insert(string& s)
{
	int cur = 0; //定义一个cur从根节点开始走，并记录当前走哪了 
	p[cur]++; 
	
	for(auto ch:s)
	{
		int path = get_num(ch); //求当前字符应该填的位置
		if(tree[cur][path] == 0) tree[cur][path] = ++idx;		 
		cur = tree[cur][path]; //这的cur不能直接更新为idx，只有新开辟结点的时候cur才等于idx；如果tree[cur][path]已经有值了，那么cur就要更新为tree[cur][path] 
		p[cur] += 1; 
	}
 } 

//查询Trie树中有多少个符合该前缀的 
int query(string& s)
{
	int cur = 0;
	
	for(auto ch:s)
	{
		int path = get_num(ch);
		if(tree[cur][path] == 0) return 0;
		cur = tree[cur][path];
	}
	return p[cur];
}

//数据范围太大了，用memset清空会超时 
//void clear()
//{
//	idx = 0; 
//	memset(tree,0,sizeof tree);
//	memset(p,0,sizeof p);
//}

//idx表示开辟的结点数量，我们应该根据idx来清空数据 
void clear()
{
	for(int i=0;i<idx;i++)
	{
		memset(tree[i],0,sizeof tree[i]);
	}
	
	for(int i=0;i<idx;i++)
	{
		p[i] = 0;
	}
	 
	idx = 0; //别忘了清空idx 
}

int main() 
{
	int T; cin >> T;
	while(T--)
	{	
		int n,q;
		cin >> n >> q;
		for(int i=1;i<=n;i++)
		{
			string s; cin >> s;
			insert(s);
		}
		for(int i=1;i<=q;i++)
		{
			string s; cin >> s;
			cout << query(s) << endl;
		}
		
		for(int i=0;i<idx;i++)
		{
			memset(tree[i],0,sizeof tree[i]);
		}
		for(int i=0;i<idx;i++)
		{
			p[i] = 0;
		}	
	
		clear(); //清空数据 
	}
	return 0;
}
