#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N = 510;

vector<int> edge[N];

int n;
int in[N];
bool st[N];
int ret;

int main()
{
	cin >> n;	

	for(int i=1;i<=n;i++)
	{
		int x,m; cin >> x >> m;
		st[x] = true;
		for(int j=1;j<=m;j++) //���Կ���m��λ�� 
		{
			int y; cin >> y;
			edge[x].push_back(y);			
			in[y]++;
		}
	} 
	
	queue<int> q;
	
	for(int i=1;i<=500;i++)
	{
		if(st[i] && in[i] == 0) q.push(i); 
	}
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		ret++; //������ͳ�ƣ���ӵĽ�㶼�Ǵ��������Ϊ0�� 
		for(auto p:edge[t])
		{
			in[p]--;
			if(st[p] && in[p] == 0) q.push(p); 
		}		
	}
	
	//�Ӷ�����ͳ�ƣ�����޻�������������Ľ�����Ϊ0 
//	for(int i=1;i<=500;i++)
//	{
//		if(st[i] && in[i] == 0) ret++;
//	} 
	
	if(ret == n) cout << "YES" << endl;
	else cout << n - ret << endl;
	
	return 0;
}
