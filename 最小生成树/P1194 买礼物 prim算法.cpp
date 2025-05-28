#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;

int edge[N][N]; //edge[i][j]��i��j����ı�Ȩֵ 
int dist[N]; //ÿ����������������ľ��� 
int st[N];
int n,v; //n����Ʒ����v��ͳһ�۸� 

//��ʽһ���ں���������
int prim1()
{
	memset(dist,0x3f,sizeof dist);
	
	int ret = 0; //��С���� 
	
	//����ѡ��һ������Ϊ���
	dist[1] = 0;
	
	for(int i=1;i<=n;i++) //ѭ������n���� 
	{
		//1.ѡ������ĵ�
		int t = 0;
		for(int i=1;i<=n;i++) 
		{
			if(!st[i] && dist[i] < dist[t]) t = i;
		}
		
		if(dist[t] <= v) ret += dist[t];
		else ret += v;//�Żݼ۷������߻���û���Żݣ���ô��ֱ���� 
		st[t] = true;
		
		//�����ж���ͨ������һ����ͨ
		
		//2.���¾���
		for(int i=1;i<=n;i++)
		{
			dist[i] = min(dist[i],edge[t][i]);
		} 
	}
	 
	return ret;
}

int prim2()
{
	memset(dist,0x3f,sizeof dist);
	
	int ret = 0; //��С���� 
	
	//����ѡ��һ������Ϊ���
	dist[1] = 0;
	
	for(int i=1;i<=n;i++) //ѭ������n���� 
	{
		//1.ѡ������ĵ�
		int t = 0;
		for(int i=1;i<=n;i++) 
		{
			if(!st[i] && dist[i] < dist[t]) t = i;
		}
		
		ret += dist[t];
		st[t] = true;
		
		//�����ж���ͨ������һ����ͨ
		
		//2.���¾���
		for(int i=1;i<=n;i++)
		{	
			dist[i] = min(dist[i],edge[t][i]);
		} 
	}
	 
	return ret;
}

int main()
{
	cin >> v >> n;
	
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			int x; cin >> x; 
			if(x == 0 || x > v) edge[i][j] = v; //��ʽ����ֱ���ڶ����ݵ�ʱ����
			else edge[i][j] = x;
		}
	}
	
	cout << prim() + v; 
	
	return 0;
} 
