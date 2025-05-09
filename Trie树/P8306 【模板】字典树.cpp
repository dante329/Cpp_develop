#include <iostream>
#include <cstring>
using namespace std;
const int N = 3e6 + 10;
int tree[N][62],p[N];
//int e[N]; ֻ��ǰ׺����Ҫe���� 
int idx;

int get_num(char ch)
{
	if(ch >= 'a' && ch <= 'z') return ch - 'a';
	else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
	else return ch - '0' + 52;
}

//�洢�ַ�����Trie�� 
void insert(string& s)
{
	int cur = 0; //����һ��cur�Ӹ��ڵ㿪ʼ�ߣ�����¼��ǰ������ 
	p[cur]++; 
	
	for(auto ch:s)
	{
		int path = get_num(ch); //��ǰ�ַ�Ӧ�����λ��
		if(tree[cur][path] == 0) tree[cur][path] = ++idx;		 
		cur = tree[cur][path]; //���cur����ֱ�Ӹ���Ϊidx��ֻ���¿��ٽ���ʱ��cur�ŵ���idx�����tree[cur][path]�Ѿ���ֵ�ˣ���ôcur��Ҫ����Ϊtree[cur][path] 
		p[cur] += 1; 
	}
 } 

//��ѯTrie�����ж��ٸ����ϸ�ǰ׺�� 
int query(string& s)
{
	int cur = 0;
	
	for(auto ch:s)
	{
		int path = get_num(ch);
		if(tree[cur][path] == 0) return 0;
		cur = tree[cur][path];
	}
	return p[cur];
}

//���ݷ�Χ̫���ˣ���memset��ջᳬʱ 
//void clear()
//{
//	idx = 0; 
//	memset(tree,0,sizeof tree);
//	memset(p,0,sizeof p);
//}

//idx��ʾ���ٵĽ������������Ӧ�ø���idx��������� 
void clear()
{
	for(int i=0;i<idx;i++)
	{
		memset(tree[i],0,sizeof tree[i]);
	}
	
	for(int i=0;i<idx;i++)
	{
		p[i] = 0;
	}
	 
	idx = 0; //���������idx 
}

int main() 
{
	int T; cin >> T;
	while(T--)
	{	
		int n,q;
		cin >> n >> q;
		for(int i=1;i<=n;i++)
		{
			string s; cin >> s;
			insert(s);
		}
		for(int i=1;i<=q;i++)
		{
			string s; cin >> s;
			cout << query(s) << endl;
		}
		
		for(int i=0;i<idx;i++)
		{
			memset(tree[i],0,sizeof tree[i]);
		}
		for(int i=0;i<idx;i++)
		{
			p[i] = 0;
		}	
	
		clear(); //������� 
	}
	return 0;
}
