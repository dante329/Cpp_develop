//����ȫ�ֱ����ͻ��� 
#include <iostream>
using namespace std;
string s; //ȫ�ֱ�����¼���
int n; 

void dfs(int pos)
{
	if(pos > n)
	{
		cout << s << endl;
		return;
	}
	
	//��ѡ(��Ҫ���ֵ�������𰸣��ȿ���N�ֵ����С)
	s += 'N';
	dfs(pos+1); //��ǰposѡ��N֮��ȥ������һλ��������ô�����Ȳ��ܣ���dfsд����֮���֪���� 
	s.pop_back(); //��dfs(pos+1);ִ����֮�󣬾��ǻ��ݣ�Ҫ��Nɾ�� 
	//ѡ 
	s += 'Y';
	dfs(pos+1);
	s.pop_back();
}

int main() 
{
	cin >> n;
	dfs(1);
	return 0;
}
