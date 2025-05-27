//�ڽӱ�ʵ��
//vector����ʵ�ֺ��ӱ�ʾ�����ڽӱ� 
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 5010, INF = 0x3f3f3f3f;

vector<PII> edge[N];
int dist[N];
bool st[N];

int n,m;

int prim()
{
	memset(dist,0x3f,sizeof dist);
	
	dist[1] = 0;
	
	int ret = 0;
	
	for(int i=1;i<=n;i++) //ȷ����Ҫ���n���㣬��ֱ����ѭ�� 
	{
		//1.�Ҿ�����̵Ķ��� 
		int t = 0;
		for(int i=1;i<=n;i++)
		{
			if(!st[i] && dist[i] < dist[t]) t = i;
		}
			
		//�ж��Ƿ���ͨ 
		if(dist[t] == INF) return INF;
		
		st[t] = true;
		ret += dist[t];
		
		//2.������̾��� 
		for(auto& p:edge[t]) //ѭ����t�����ĵ� 
		{
			int a = p.first, b = p.second; //��ǰ�¼���ĵ㵽ĳ��������a��ľ���b 
			dist[a] = min(dist[a],b); //����ĳ��������a�����̾��� 
		}
	} 
	
	return ret;
}

int main()
{
	cin >> n >> m;
	//��ͼ 
	for(int i=1;i<=m;i++) 
	{
		int x,y,z; cin >> x >> y >> z;
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	
	int ret = prim();
	
	if(ret == INF) cout << "orz" << endl;
	else cout << ret << endl;
	 
	return 0;
 } 
