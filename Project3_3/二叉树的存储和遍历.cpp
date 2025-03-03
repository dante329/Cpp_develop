#include<iostream>
#include<queue>

using namespace std;

const int N = 1e5 + 10;
int l[N],r[N]; //链式存储树 
int n;

void dfs_pre(int u)
{
	cout << u << " ";
	if(l[u]) dfs_pre(l[u]);
	if(r[u]) dfs_pre(r[u]);
}

void dfs_in(int u)
{
	if(l[u]) dfs_in(l[u]);
	cout << u << " ";
	if(r[u]) dfs_in(r[u]);
}

void dfs_post(int u)
{	
	if(l[u]) dfs_post(l[u]);
	if(r[u]) dfs_post(r[u]);
	cout << u << " ";
}

void bfs()
{
	queue<int> q;
	q.push(1);
	while(q.size())
	{
		int t = q.front(); q.pop();
		cout << t << " ";
		if(l[t]) q.push(l[t]);
		if(r[t]) q.push(r[t]); 
 	}
}

int main()
{
	cin >> n; //先读取一个数n，表示这个树有n个结点，并且接下来有n个结点信息 
	for(int i=1;i<=n;i++)
	{
		cin >> l[i] >> r[i]; //第i行的两个整数l、r表示结点i的左右子结点的值 
	}
	dfs_pre(1);
	cout << endl;
	dfs_in(1);
	cout << endl;
	dfs_post(1);
	cout << endl;
	bfs();
	return 0;
}
