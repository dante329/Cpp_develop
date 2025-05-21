#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1010;

vector<PII> g[N];
int f[N][N]; //f[i][j]��ʾ����1~n����Ʒ��ѡ������������j������ֵ 
int n,m,cnt; //cnt������¼�ж�������Ʒ 

int main() 
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		int a,b,c; cin >> a >> b >> c;
		cnt = max(cnt,c); 
		g[c].push_back({a,b}); 
	}
	
	for(int i=1;i<=cnt;i++) //ѭ������ 
	{
		for(int j=m;j>=0;j--)
		{
			//����Ҫ�ȿ��ǲ�ѡ�����Ȼ���f[i][j]��ֵ����Ϊ�п���j<a��������ȥ�ж� 
			f[i][j] = f[i-1][j];
			for(auto& t:g[i])
			{
				int a = t.first, b = t.second;
				if(j >= a)
				{
					f[i][j] = max(f[i][j],f[i-1][j-a]+b);
				}
			}
		}
	}
	
	cout << f[cnt][m];
	
	return 0;
}

//�ռ��Ż�
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 1010;

vector<PII> g[N];
int f[N]; //f[i][j]��ʾ����1~n����Ʒ��ѡ������������j������ֵ 
int n,m,cnt; //cnt������¼�ж�������Ʒ 

int main() 
{
	cin >> m >> n;
	
	for(int i=1;i<=n;i++)
	{
		int a,b,c; cin >> a >> b >> c;
		cnt = max(cnt,c); 
		g[c].push_back({a,b}); 
	}
	
	for(int i=1;i<=cnt;i++) //ѭ������ 
	{
		for(int j=m;j>=0;j--)
		{
			for(auto& t:g[i])
			{
				int a = t.first, b = t.second;
				if(j >= a)
				{
					f[j] = max(f[j],f[j-a]+b);
				}
			}
		}
	}
	
	cout << f[m];
	
	return 0;
} 
