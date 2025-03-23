#include<iostream>
#include<cstring>
using namespace std;

const int N = 20;
int n;
int a[N];
int t[N];

int calc(int x,int y)
{
	int cnt = 0;
	for(int i=0;i<=n;i++)
	{
		//(x & (1<<i) == 1) ֻ���� i=0 ʱ�������壬��Ϊ 1<<0 �� 1������ i>0��1<<i �� 2, 4, 8, ...������ (x & (1<<i) == 1) ��Զ����Ϊ�棨���� i=0��
		//���� 10010011 & 00010000 ���Ϊ 00010000
//		if((x & (1<<i) == 0) && (y & (1<<i) == 1)) cnt++;
//		if((x & (1<<i) == 1) && (y & (1<<i) == 0)) return -1;
    	//���������� i λ�Ƿ�Ϊ 1��Ӧ��ʹ������д����
		if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1) cnt++;
 		if(((x >> i) & 1) == 1 && ((y >> i) & 1) == 0) return -1;
	}
	return cnt;
}

int solve()
{
		int ret = 0x3f3f3f3f;			 
		for(int st=0;st<=(1<<n)-1;st++) //ö��nλ�Ϸ������ƣ�ö�ٵ�ÿ����������st��ʾ 
		{
			memcpy(t,a,sizeof a); //������t�д���
			int	change = st;
			int cnt = 0;
			bool flag = 1;
			for(int i=1;i<=n;i++)
			{
				//���ж�change����t[i]�Ƿ�Ϸ� 
				int c = calc(t[i],change);
				if(c == -1)
				{
					flag = 0;
					break; 
				}
				cnt += c;
				//��t[i]���иı�
				t[i] = change;
				change = t[i-1] ^ (t[i]<<1) ^ (t[i]>>1);
				change &= (1<<n) - 1;
			}
			if(flag) ret = min(ret,cnt);
		}
		if(ret == 0x3f3f3f3f) ret = -1;
		return ret;
 } 

int main()
{
	int T; cin >> T;
	for(int k=1;k<=T;k++)
	{
		memset(a,0,sizeof a);
		//�����ݣ��浽a 
		cin >> n;
		for(int i=1;i<=n;i++) //a������±�1��ʼ�棬��Ϊ�ڽ��в���ʱҪ�õ������е����� 
		{
			for(int j=0;j<n;j++)
			{
				int x; cin >> x; 
				if(x == 1) a[i] |= (1 << j);
			}
		}  
			
		//�������� 

		printf("Case %d: %d\n",k,solve());
	}	
	return 0;
} 
