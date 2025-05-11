#include<iostream>

using namespace std;

const int N = 360, M = 50;

int f[M][M][M][M]; //dp���� 
int n,m;
int cnt[5];
int x[N];

int main()
{
	//������ 
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> x[i];
	for(int i=1;i<=m;i++)
	{
		int t; cin >> t;
		cnt[t]++;
	}
	
	//��ʼ��
	f[0][0][0][0] = x[1]; //��û�ߵ�ʱ�򣬵÷־������λ�õķ��� 
	
	//״̬ת�Ʒ��� 
	for(int a=0;a<=cnt[1];a++) //��0��ʼ����ʾ��û���ù����ſ�Ƭ�������ſ�Ƭ����������Ϊֹ 
		for(int b=0;b<=cnt[2];b++)
			for(int c=0;c<=cnt[3];c++)
				for(int d=0;d<=cnt[4];d++)
				{
					//����a��b��c��d�������ǰ������
					int i = 1 + a + b * 2 + c * 3 + d * 4; //����λ�ñ����˼������λ�õ�1������ 
					int& t = f[a][b][c][d]; //���ã�t�൱��f[a][b][c][d] 
					
					//ÿ���ж�Ҫȡ���ֵ����Ϊ�㲻֪��ʹ�����ſ�Ƭ�÷���� 
					//�߽����Ҳ��ͬ�����õģ�����˵ֻ��һ��b�ģ���ô�����������ж϶�����ȥ��ֻ��ִ�е�b��״̬ת�Ʒ��� 
					if(a>=1) t = max(t, f[a-1][b][c][d] + x[i]);
					if(b>=1) t = max(t, f[a][b-1][c][d] + x[i]);
					if(c>=1) t = max(t, f[a][b][c-1][d] + x[i]);
					if(d>=1) t = max(t, f[a][b][c][d-1] + x[i]);
					
					//��������������жϣ��Ǵ�� 
//					if(a>=1) t = f[a-1][b][c][d] + x[i];
//					if(b>=1) t = f[a][b-1][c][d] + x[i];
//					if(c>=1) t = f[a][b][c-1][d] + x[i];
//					if(d>=1) t = f[a][b][c][d-1] + x[i];
				}
	
	cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
	
	return 0;
} 
