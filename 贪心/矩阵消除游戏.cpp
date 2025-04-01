#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 20;
int a[N][N];
int col[N]; //�е�ѡ�񿿶�����ö�٣��о�ͳ��û��ö�ٵ� 
int n,m,k;

int calc(int x)
{
	int cnt = 0;
	while(x)
	{
		cnt++;
		x &= x-1;
		//x -= x & -x;
	}
	return cnt;
}

bool cmp(int x1,int x2)
{
	return x1 > x2;
}

int main()
{
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	int ret = 0;
	//ö���е�ѡ������п��� �е�ѡ����ȷ���ģ�ֻ��Ҫ�ۼӣ������е�ѡ���Ǹ���ʣ��Ĵ���ѡ��ǰ���������� 
	for(int st=0;st<=(1<<n)-1;st++)
	{
		if(k-calc(st)<0) continue; //1�ĸ�������k�Ƿ� 
		//�Ϸ��Ϳ���һλ��1���Ͷ���һ��ȫ�������������Ծ�Ҫ��һ������������
		memset(col,0,sizeof col);
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if((st >> i) & 1) sum += a[i][j];
				else col[j] += a[i][j];
			}
		} 		
		sort(col,col + m,cmp); //cmp����
		for(int i=0;i<min(k-calc(st),m);i++) sum += col[i]; //k�ķ�Χ�Ƚϴ�k-calc(st)�п��ܳ���m
		ret = max(ret,sum);
	}
	cout << ret;
	return 0;
}
