#include<iostream>
#include<cstring> 
using namespace std;
const int N = 15;
int t[N],d[N],l[N];
int T,n;
bool st[N];
//���������������⣬����Ϊ��Ҫ���շɻ����˳���䣬�������Ǽ򵥵��ظ������� 
//bool dfs(int pos,int fly) //pos����i�ܷɻ�  fly����ǰ�ɻ�ʵ����ɵ�ʱ�� 
//{	
//	if(fly > d[pos+1])
//	{
//		return false;
//	}
//	if(fly <= t[pos]) dfs(pos+1,t[pos]+l[pos]);
//	else dfs(pos+1,fly+l[pos]);
//	return true;
//}	

//�ڶ��γ��ԣ�����ı��� 
//bool dfs(int pos,int end)
//{
//	if(pos > n) return true;
//	if(end > t[pos+1] + d[pos+1]) return false;
//	for(int i=1;i<=n;i++)
//	{
//		if(st[pos]) continue;
//		st[i] = true;
//		dfs(pos+1,max(end,t[pos+1])+l[pos+1]); 
//		st[pos] = false;
//	}
//}

bool dfs(int pos,int end) //�ڴ����˼·��pos����i�ܷɻ�����ʵ���ϵ�i�ܷɻ��Ǹ���ѭ���е�i�������ģ�pos����ͳ�Ʒɻ�����������pos>n��ʱ�ݹ�ĳ��� 
{
	if(pos > n) return true;
	
	for(int i=1;i<=n;i++)
	{
		if(st[i]) continue;
		if(end > t[i] + d[i]) continue; 
		
		st[i] = true; //��ĳһ�ܷɻ���ǰ���£���ȥѡ��ʣ�µ�ĳһ�ܷɻ����Ҿ�Ҫ��ѡ��ķɻ���Ϊtrue����ǰ���µĵݹ��������Ҫ����ܷɻ����false����Ϊ�ҵ�ǰ��Ҫ�ı��ˣ���ǰ����һ���ֶ����µ� 
		int new_end = max(end,t[i])+l[i];
		if(dfs(pos+1,new_end)) return true; //ÿ�����½���dfs��������n�λ���ȥѡ��ͬ��i���ٸ���st[i]ȥɸѡ 
		st[i] = false; //��ԭ�ֳ� 
	}
	return false; //�ݹ��Ƕ��ģ��ںܶ�����ζ������ߵ��⣬����ߵ���pos��ȻС��n���� return false ��ʾ��ǰ��֧ʧ�� 
	//�����зɻ������Թ�����Ȼ�޷�����ʱ��˵����ǰ·����Ч�����뷵�� false ���ϲ�ݹ鳢�����������ԡ�
}

int main()
{
	cin >> T;
	while(T--)
	{
		memset(st,0,sizeof(st)); //�����������Ҫ������ݣ��������� 
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> t[i] >> d[i]	>> l[i];	 
		}
		if(dfs(1,0)) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}	
	return 0;
}
