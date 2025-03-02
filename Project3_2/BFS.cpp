//vector�洢�� 
//#include<iostream>
//#include<vector>
//#include<queue> 
//using namespace std;
//
//const int N = 1e5 + 10;
//vector<int> edges[N]; 
//bool st[N];
//queue<int> q;  //���еĶ�����Էŵ�bfs�����ڣ���Ϊ������ȫ�ֵĵط��ò���������У�������bfs��ʵ����Ҫ���� 
//int n;
// 
//void bfs()
//{
//	//��һ��������Ը��ڵ����Ӻͱ�ǲ��� 
//	q.push(1); //���1Ҳ������Ϊ��������bfs 
//	st[1] = true;
//	
//	while(q.size()) //����һ�����ѭ���������л���Ԫ�ص�ʱ��ͻ�һֱִ�� 
//	{
//		int t = q.front(); q.pop();
//		cout << t << " ";
//		
//		for(auto v:edges[t]) //ʵ���ϱ���t�Ľ�㲻ֻ��t���ӽ�㣬��Ϊ����������޸������еĴ洢�����ﻹ�������t�ĸ���㣬���Ա���Ѿ���ӵĽ���൱��Ҫ����Ȼ�ͻ�������ѭ�� 
//		{
//			if(!st[v])
//			{
//				q.push(v); //ֻҪ��ӣ���Ҫ��st�б�������� 
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

//��ʽǰ���� DFS
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
	//���� 
    cin >> n;
    for(int i=1;i<n;i++)
    {
    	int a,b; cin >> a >> b;
    	add(a,b); add(b,a);
	}
	//BFS���� 
	bfs();
	return 0;
}

 
