#include<iostream>

using namespace std;
int n;
char a,b,c;

//��x�ϵ�n������ͨ��yת�Ƶ�z�� 
void dfs(int n,char x,char y,char z)
{
	if(n==0) return;
	dfs(n-1,x,z,y);
	printf("%c->%d->%c\n",x,n,y);
	dfs(n-1,y,x,z); 
}

int main()
{
	cin >> n >> a >> b >> c;
	dfs(n,a,c,b);
	return 0;
} 
