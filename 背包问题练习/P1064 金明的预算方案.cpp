//ע����������е������ı���Ǹ��ݵ�ǰ�����ڵڼ���ȷ���ģ������ǰ�˳��1��2��3��4�����ġ���һ����Ŀ��δ˵�� 
#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 70, M = 4e4 + 10;

int n,m;

int v[N][3], w[N][3]; //v[i][0]������ v[i][1]������1 v[i][2]������2 

int f[N][M];

int main()
{
	cin >> m >> n ;
	
	for(int i=1;i<=n;i++)
	{
		int a,p,q; cin >> a >> p >> q;
		if(q == 0)
		{
			v[i][0] = a;
			w[i][0] = a * p; 
		}
		else 
		{
//			if(v[q][0] == 0) continue; // ������� q �����ڣ�����
			if(v[q][1] == 0) //v[i][1]�ǿյľ�����
			{
				v[q][1] = a;
				w[q][1] = a * p;
			} 
			else //�и���1�˾����븽��2 
			{
				v[q][2] = a;
				w[q][2] = a * p;
			}		
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			//��ѡ 
			f[i][j] = f[i-1][j];
			
			//���v[i][0]�������������������ȿ�������
			if(v[i][0] == 0) continue;
			
			//ѡ���� 
			if(j >= v[i][0])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]]+w[i][0]);
			} 		 
			//��+����1
			if(j >= v[i][0] + v[i][1])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]-v[i][1]]+w[i][0]+w[i][1]);
			}
			//��+����2
			if(j >= v[i][0] + v[i][2])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]-v[i][2]]+w[i][0]+w[i][2]);
			}
			//��+����1+����2 
			if(j >= v[i][0] + v[i][1] + v[i][2])
			{
				f[i][j] = max(f[i][j],f[i-1][j-v[i][0]-v[i][1]-v[i][2]]+w[i][0]+w[i][1]+w[i][2]);
			}
		}
	}
	
	cout << f[n][m];
	return 0;
 } 



