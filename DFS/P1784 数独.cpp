#include<iostream>
using namespace std;
const int N = 10; 
int a[N][N];
bool col[N][N],row[N][N],st[N][N][N]; //0-based����Ϊ�˷��������ӳ��
int n=9;

bool dfs(int i,int j)
{
	if(i == n) return true;
	if(j == n) return dfs(i+1,0);
	
	//���д�������������ͱ����ȼ��j�ټ��i����Ϊ���j��ʱ���п��ܻ�ı�iʹ��i���Ϸ�
//	if(j == n) 
//	{
//	    i++;
//		j = 0;
//	}
//	if(i == n) return true;
	

	if(a[i][j]) return dfs(i,j+1); //����һ��Ҫ��treturn�����i��j�Ѿ���Ԫ���˾�Ҫ������һ��λ�õ�dfs�����ҵ�ǰλ��һ��Ҫ��������Ȼ������Ƿ��ص���ǰdfs�� 
	
	for(int x=1;x<=n;x++)
	{
		if(row[i][x] || col[j][x] || st[i/3][j/3][x]) continue;
		
		a[i][j] = x;
		row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
		
		if(dfs(i,j+1)) return true;
		
		row[i][x] = col[j][x] = st[i/3][j/3][x] = false;
		a[i][j] = 0;
	}
	return false;
}

int main()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
			int x = a[i][j];
			if(x) row[i][x] = col[j][x] = st[i/3][j/3][x] = true;
		}
	}
	
	dfs(0,0);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
 } 
