#include<iostream>
#include<vector>
using namespace std;
vector<int> a;
const int N = 15;
//һ��ֻѡһ��
bool col[N]; //�ж��� 
bool st1[N*2],st2[N*2]; //�ж������Խ���
//int a[N];
int n;
int ret;

void dfs(int pos)
{
	if(pos > n)
	{
		ret++;
		if(ret<=3) 
		{
			for(auto x:a) cout << x << " ";
			cout << endl;
		}
		
		return;
	}
	//ÿ���Ѿ���pos�������� 
	for(int j=1;j<=n;j++) //ÿ�� 
	{
		if(col[j]) continue;
		if(st1[pos-j+n] || st2[pos+j]) continue;
		a.push_back(j); //��¼��� 
		//���� 
		st1[pos-j+n] = true; 
		st2[pos+j] = true;
		col[j] = true;
		//�ݹ� 
		dfs(pos+1);
		//��ԭ�ֳ� 
		a.pop_back();
		st1[pos-j+n] = false; 
		st2[pos+j] = false;
		col[j] = false;			
	}
	
 } 
 
int main()
{
	cin >> n;
	dfs(1);
	cout << ret;	
	return 0;
}
