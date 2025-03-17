#include<iostream>

using namespace std;
const int N = 1e6 + 10; 
int a[N],b[N],c[N];
int la,lb,lc;

bool cmp(string& x,string& y) //�����һ������С�ͷ���true 
{
	if(x.size() != y.size())
	{
		return x.size() < y.size();
	}
	else
	{
		return x < y;
	}
}

void sub(int c[],int a[],int b[])
{
	for(int i=0;i<lc;i++)
	{
		c[i] += a[i] - b[i];
		if(c[i] < 0)
		{
			c[i + 1] -= 1; //c[i+1] = -1;
			c[i] += 10;
		}
	}
	while(lc > 1 && c[lc-1] == 0 ) lc--; //lc������1 
}

int main()
{
	string x,y;
	cin >> x >> y;
	if(cmp(x,y))  
	{
		swap(x,y); //ȷ��x��y����Ϊ�Ȼ�Ҫ�ô�����С��
		cout << "-"; //������˵����Ŀ�����Ǵ�����С�������Ϊ���� 
	}
	la = x.length(); lb = y.length(); lc = max(la,lb);
	//ת����������ʽ ע���ȥ�ַ�'0' 
	for(int i=0;i<la;i++) a[i] = x[la-1-i] - '0';
	for(int i=0;i<lb;i++) b[i] = y[lb-1-i] - '0';
	//ִ�м��� 
	sub(c,a,b); 
	//���c������
	for(int i=lc-1;i>=0;i--) cout << c[i]; 
	return 0;
} 
