#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL f[N];
int n,m;

int main()
{
	cin >> n >> m;
	//���ò���������ÿ��·�߷ֱ��߶��ٴ� 
//	for(int i=1;i<=m;i++) 
//	{
//		cin >> x >> y; //���������������վ��Ļ������ݸ���Ϊ��������ô�졣 
//	}
	int x; cin >> x; //�ȶ���һ��x����ѭ������y����ÿ��ѭ������ʱ��y��ֵ��x 
	//��ʼ��������飨ͳ��·�δ����� 
	for(int i=2;i<=m;i++)
	{
		int y; 
		cin >> y;
		if(x > y) //�Ӵ�վ�㵽Сվ��Ҫ�������Ӽ�������� 
		{
			f[x]--;
			f[y]++;
		 } 
		else
		{
			f[x]++;
			f[y]--;
		}
		x = y; 
	}
	//��ԭ���� 
	LL ret = 0;
	for(int i=1;i<n;i++)
	{
		f[i] += f[i-1]; //�ı������� ֱ�Ӵ��� ���������
		//��ȡa,b,c
		int a,b,c;
		cin >> a >> b >> c; 	
		//f�д�ʱ����ÿ��·�ľ�������
		ret += min(a * f[i], c + b * f[i]); //ֱ����Ʊ����ic��	
	}
	cout << ret;
	return 0;
} 
