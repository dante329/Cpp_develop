#include<iostream> 
#include<queue>
#include<vector>

using namespace std;

const int N = 5010, MOD = 80112002;

int n,m;
int in[N],out[N]; //out������������������Щ����Ϊ0�����Ȼ���ۼ����ǵ����� 
int f[N];

vector<int> edge[N];

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=m;i++)
	{
		int x,y; cin >> x >> y;
		in[y]++; out[x]++;
	edge[x].push_back(y);
	}
	
	queue<int> q;
	
	//�����Ϊ0�Ľ�������У����ҳ�ʼ�����ǵ�״̬ 
	for(int i=1;i<=n;i++)
	{
		if(in[i] == 0)
		{
			q.push(i);
			f[i] = 1;
		}
	}
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		
		for(auto p:edge[t])
		{
			in[p]--;
			f[p] = (f[p] + f[t]) % MOD;
			if(in[p] == 0) q.push(p);
		}		
	}
		
		
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		if(out[i] == 0) ret = (ret + f[i]) % MOD;
	}
	
	cout << ret << endl;
	
	return 0;
}
