//����С������ 
//�ڽӾ����ͼ 
#include <iostream>
#include <cstring>

using namespace std;

const int N = 5010, INF = 0x3f3f3f3f;

int edge[N][N]; //�ڽӾ���edge
int dist[N]; //ÿ����������������ľ��� 
bool st[N]; //�����Щ���Ѿ������������� 
int n,m;  

int prim()
{
	//dist��ʾ��������������ľ��룬��տ�ʼ����ʼ��Ϊ����� 
	memset(dist,0x3f,sizeof dist);
	
	dist[1] = 0;
	
	int ret = 0;
	for(int i=1;i<=n;i++) //ѭ������n���� 
	{
		//1.�������
		int t = 0; 
		for(int i=1;i<=n;i++) 
		{
			if(!st[i] && dist[i] < dist[t]) t = i; //�ҵ�û�з��ʵĵ㣬��������������������� 
		}	
		
		//�ж��Ƿ���ͨ 
		if(dist[t] == INF) return INF; //����ֱͨ�ӷ���INF
		
		st[t] = true;
		ret += dist[t]; 
		
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
	cin >> n >> m;
	//��ʼ��edge������ȡ��С��ʱ�򲻻�Ӱ���� 
	memset(edge,0x3f,sizeof edge);
	//��ͼ
	for(int i=1;i<=m;i++)
	{
		int x,y,z; cin >> x >> y >> z;
		edge[x][y] = edge[y][x] = min(edge[x][y], z); //�����ر�  
	}
	
	int ret = prim(); 
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	
	return 0;
}
