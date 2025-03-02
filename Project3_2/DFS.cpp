//vector����洢���� DFS 
//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int N = 1e5 + 10;
//vector<int> edges[N]; //�洢�� 
//int n;
//
//bool st[N]; //������ǽ���Ƿ��Ѿ����������� 
//
//void dfs(int x)
//{
//	cout << x << " ";
//	st[x] = true; //����ȫ�ֵ�dfs������Ѿ����ʹ��� 
//	for(auto v:edges[x])
//	{
//		if(!st[v]) dfs(v);
//	}
//}
//
//
//int main() 
//{
//	//���� 
//	cin >> n; //����n���ڵ� 
//	for(int i=1;i<n;i++) //����n-1���� 
//	{
//		//a��b֮����һ���� 
//		int a,b; cin >> a >> b;
//		edges[a].push_back(b);
//		edges[b].push_back(a);
//	}
//	
//	//������ȱ��� 
//	dfs(1); //����1Ϊ���ڵ㣬��1Ϊ��dfs���� 
//	
//	return 0;
//}

//��ʽǰ���Ǵ洢���� DFS 
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int id,e[N*2],ne[N*2],h[N];//�洢�� 
int n;

bool st[N]; //������ǽ���Ƿ��Ѿ����������� 

void dfs(int x)
{
	cout << x << " ";
	st[x] = true;
	for(int i = h[x];i;i=ne[i])
	{
		int v = e[i]; //���� 
		if(!st[v]) 
		{
//			cout << v << " ";
			dfs(v); 
		}
	}
}

void add(int x,int y) //���add��������ͷ��
{
	id++;
	e[id] = y;
	ne[id] = h[x];
	h[x] = id;
} 

int main() 
{
	//����  //��a���ӽڵ�bͷ�嵽a�������� 
	cin >> n;
	for(int i=1;i<n;i++)
	{
		int a,b; cin >> a >> b;
		add(a,b); add(b,a);
	}
	//������ȱ���
	dfs(1); //���Ǽ���1Ϊ�� 
	
	
	return 0;
}



