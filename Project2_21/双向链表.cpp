#include<iostream>

using namespace std;

const int N = 1e5 +10;

int e[N],ne[N],pre[N],h,id; //��̬ģ��ʵ�������ʱ��һ��Ҫע������� �߼��ṹ �� ����ṹ ���������߼��ṹ�ϵĵ�һ���ڵ㣨��ͷ�ڵ㣩������������ṹ�����飩�����һ��λ���� 

int mp[N];

//������ӡ 
void print()
{
	for(int i=ne[h];i;i=ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
} 

//ͷ�� 
void push_front(int x)
{
	//Ϊ�½ڵ����λ�� 
	id++;
	//���½ڵ��ֵ��������
	e[id] = x; 
	//���޸��½ڵ��ǰ��ָ��
	pre[id] = h;
	ne[id] = ne[h];
	//���޸�ͷ�ڵ���һ���ڵ��ǰָ��
	pre[ne[h]] = id;
	//������޸�ͷ�ڵ�ĺ�ָ�룬��һ��һ��Ҫ����޸�
	ne[h] = id;
	//����mp���� 
	mp[x] = id;
}

//��ֵ����
int find(int x)
{
	return mp[x];	
} 

//������λ��֮�����һ���ڵ�
void insert_back(int p,int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	pre[id] = p;
	ne[id] = ne[p];
	
	pre[ne[p]] = id;
	ne[p] = id;
}
 
//������λ��֮ǰ����һ���ڵ�
void insert_front(int p,int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	pre[id] = pre[p];
	ne[id] = p;
		
	ne[pre[p]] = id;
	pre[p] = id;
}
 
//ɾ������λ�õĽڵ㣨ͷ�ڵ���Ժ��м�ڵ�ϲ������һ���ڵ�Ҳ���Ժϲ������ǻ�ı�ͷ�ڵ��pre�� 
void erase(int p)
{
	if (p == 0) //���ɾ��ͷ�ڵ� 
	{
		return;
	}
	else if (ne[p] == 0) //ɾ�����һ���ڵ� 
	{
		ne[pre[p]] = ne[p];
		mp[e[p]] = 0;
	}
	else //ɾ���м�ڵ� 
	{
		ne[pre[p]] = ne[p]; 
		mp[e[p]] = 0;
	}
 } 
 
int main()
{
	for(int i=1;i<=5;i++)
	{
		push_front(i);
		print();
	}
	
//	cout << find(1) << endl << find(4) << endl << find(9);

//	insert_back(2,22);
//	print();
//	insert_back(3,33);
//	print();

	insert_front(2,22);
	print();
	insert_front(3,33);
	print();
	return 0;
}
