#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std; 

const int N = 110, T = 1e5 + 10;

int f[N][T]; //dp��f[i][j]��ʾ�������i������֮�󣬸߶�Ϊjʱ�����Ѫ���� �������i������֮�󣡣� 
int d,n; //��������ȡ����������� 
struct node
{
	int t,w,h; //���µ�ʱ�䡢ά��������ʱ�䡢�ܵ�ߵĸ߶� 
}a[N];

bool cmp(node& a, node& b)
{
	return a.t < b.t;
}

int main() 
{
	cin >> d >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].t >> a[i].w >> a[i].h;	
	}	
	
	sort(a + 1, a + 1 + n, cmp); //�����ĸ������������� 
		
	f[0][0] = 10;
	
	for(int i=1;i<=n;i++)
	{	
		for(int j=0;j<=d;j++)
		{			
			if(f[i-1][j] >= a[i].t) //���õ�������� 
			{
				if(j + a[i].h >= d) //����ͳ�ȥ�ˣ��Ǿ�ֱ�ӷ��������Ʒ�����ʱ��  
				{
					cout << a[i].t << endl;
					return 0;
				}
				
				//��ǰ��Ʒ����ֱ�ӵ��ȥ
				//��ס��״̬��ʾ�Ǵ������i����Ʒ����ô������ᵼ�����ֿ��ܡ���������1~i����Ʒ��ѡ�񣬵�i����Ʒ��״̬�������ֿ����Ե��µ� 
				f[i][j] = max(f[i][j],f[i-1][j] + a[i].w); //�Ե���i����Ʒ���µ�״̬
				f[i][j+a[i].h] = max(f[i][j+a[i].h],f[i-1][j]); //��������i����Ʒ���µ�״̬			 
			}
			
		}
	}
		
	int ret = 10;
	for(int i=1;i<=n;i++)
	{
		if(ret < a[i].t) break;
		else ret += a[i].w;
	}
	cout << ret << endl;
	
	
	return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std; 

const int N = 110, T = 1e5 + 10;

int f[N][T]; //dp��f[i][j]��ʾ�������i������֮�󣬸߶�Ϊjʱ�����Ѫ���� �������i������֮�󣡣� 
int d,n; //��������ȡ����������� 
struct node
{
	int t,w,h; //���µ�ʱ�䡢ά��������ʱ�䡢�ܵ�ߵĸ߶� 
}a[N];

bool cmp(node& a, node& b)
{
	return a.t < b.t;
}

int main() 
{
	cin >> d >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].t >> a[i].w >> a[i].h;	
	}	
	
	sort(a + 1, a + 1 + n, cmp); //�����ĸ������������� 
	
	memset(f, -0x3f, sizeof f); //�������ʾ�޷������״̬	
	f[0][0] = 10;
	
	for(int i=1;i<=n;i++)
	{
		int delta = a[i].t - a[i-1].t;
		
		for(int j=0;j<=d;j++)
		{
			if(f[i-1][j] < delta) continue; //�Ų���������������
			 
			//���õ����� 
			if(j + a[i].h >= d) //����ͳ�ȥ�ˣ��Ǿ�ֱ�ӷ��������Ʒ�����ʱ��  
			{
				cout << a[i].t << endl;
				return 0;
			}
			
			//��ǰ��Ʒ����ֱ�ӵ��ȥ
			//��ס��״̬��ʾ�Ǵ������i����Ʒ����ô������ᵼ�����ֿ��ܡ���������1~i����Ʒ��ѡ�񣬵�i����Ʒ��״̬�������ֿ����Ե��µ� 
			f[i][j] = max(f[i][j], f[i-1][j] - delta + a[i].w); //�Ե���i����Ʒ���µ�״̬
			f[i][j+a[i].h] = max(f[i][j+a[i].h], f[i-1][j] - delta); //��������i����Ʒ���µ�״̬			 
			
		}
	}
		
	int ret = 10;
	for(int i=1;i<=n;i++)
	{
		if(ret < a[i].t) break;
		else ret += a[i].w;
	}
	cout << ret << endl;
	
	
	return 0;
}
