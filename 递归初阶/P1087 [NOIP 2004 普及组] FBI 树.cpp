#include<iostream>
using namespace std;
const int N = 11;

int f[1 << N]; //ǰ׺�� 
int n;

void dfs(int l,int r)
{
	if(l > r) return; 
	//�ж����������ʲô��
	char ret;
	int sum = f[r] - f[l-1];
	if(sum == 0) ret = 'B';
	else if(sum == (r-l+1)) ret = 'I';
	else ret = 'F';
	if(l == r) 
	{
		cout << ret;
		return;
	}
	//�ж������Ӵ� 
	int mid = (l + r) / 2;
	dfs(l,mid);
	dfs(mid+1,r);
	//������������������ڵ�
	cout << ret;  
}

int main()
{
	cin >> n;	
	n = (1 << n);
	//�����ݣ�������Ҫ��������ֱ�Ӵ浽ȫ�ֵ�ǰ׺�������У���dfs������ǰ׺���ж�FBI�� 
	for(int i=1;i<=n;i++)
	{
		char ch; cin >> ch;
		f[i] = f[i-1] + (ch - '0');
	}
	dfs(1,n);
	return 0;
}
